#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int l, r, m;
	int sl, sr, sm;
	int lzy;
} tree[maxn*8];
int n, t;

void pushdown(int l, int r, int dex)
{
	if(!tree[dex].lzy) return;
	tree[dex*2].lzy = tree[dex*2+1].lzy = tree[dex].lzy;
	tree[dex].lzy = 0;
	int mid = (l+r) >> 1;
	if(tree[dex*2].lzy == 1){
		tree[dex*2].l = tree[dex*2].m = tree[dex*2].r = mid-l+1;
		tree[dex*2].sl = tree[dex*2].sm = tree[dex*2].sr = mid-l+1;
		tree[dex*2+1].l = tree[dex*2+1].m = tree[dex*2+1].r = r-mid;
		tree[dex*2+1].sl = tree[dex*2+1].sm = tree[dex*2+1].sr = r-mid;
	}
	else if(tree[dex*2].lzy == 2){
		tree[dex*2].l = tree[dex*2].m = tree[dex*2].r = 0;
		tree[dex*2+1].l = tree[dex*2+1].m = tree[dex*2+1].r = 0;
	}
	else{
		tree[dex*2].l = tree[dex*2].m = tree[dex*2].r = 0;
		tree[dex*2+1].l = tree[dex*2+1].m = tree[dex*2+1].r = 0;
		tree[dex*2].sl = tree[dex*2].sm = tree[dex*2].sr = 0;
		tree[dex*2+1].sl = tree[dex*2+1].sm = tree[dex*2+1].sr = 0;	
	}
}
void build(int l, int r, int dex)
{
	tree[dex].l = tree[dex].m = tree[dex].r = r-l+1;
	tree[dex].sl = tree[dex].sm = tree[dex].sr = r-l+1;
	tree[dex].lzy = 0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
void update(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y){
		tree[dex].l = tree[dex].m = tree[dex].r = r-l+1;
		tree[dex].sl = tree[dex].sm = tree[dex].sr = r-l+1;
		tree[dex].lzy = 1;
	}
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		update(l, mid, dex*2, x, y), update(mid+1, r, dex*2+1, x, y);
		tree[dex].l = tree[dex*2].l, tree[dex].r = tree[dex*2+1].r;
		tree[dex].m = max(tree[dex*2].m, tree[dex*2+1].m);
		tree[dex].m = max(tree[dex*2].r + tree[dex*2+1].l, tree[dex].m);
		if(tree[dex*2].l == mid-l+1) tree[dex].l += tree[dex*2+1].l;
		if(tree[dex*2+1].r == r-mid) tree[dex].r += tree[dex*2].r;
	}
}
void cover(int l, int r, int dex, int x, int y, int ns)
{
	//printf("%d %d\n", x, y);
	if(l >= x && r <= y){
		tree[dex].l = tree[dex].m = tree[dex].r = 0;
		if(ns) tree[dex].sl = tree[dex].sm = tree[dex].sr = 0;
		tree[dex].lzy = 2 + ns;
	}
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		cover(l, mid, dex*2, x, y, ns), cover(mid+1, r, dex*2+1, x, y, ns);
		tree[dex].l = tree[dex*2].l, tree[dex].r = tree[dex*2+1].r;
		tree[dex].m = max(tree[dex*2].m, tree[dex*2+1].m);
		tree[dex].m = max(tree[dex*2].r + tree[dex*2+1].l, tree[dex].m);
		if(tree[dex*2].l == mid-l+1) tree[dex].l += tree[dex*2+1].l;
		if(tree[dex*2+1].r == r-mid) tree[dex].r += tree[dex*2].r;
		
		if(ns){
			tree[dex].sl = tree[dex*2].sl, tree[dex].sr = tree[dex*2+1].sr;
			tree[dex].sm = max(tree[dex*2].sm, tree[dex*2+1].sm);
			tree[dex].sm = max(tree[dex*2].sr + tree[dex*2+1].sl, tree[dex].sm);
			if(tree[dex*2].sl == mid-l+1) tree[dex].sl += tree[dex*2+1].sl;
			if(tree[dex*2+1].sr == r-mid) tree[dex].sr += tree[dex*2].sr;			
		}
	}
	//printf("%d %d %d %d %d\n", l, r, tree[dex].l, tree[dex].m, tree[dex].r);	
}
int query(int l, int r, int dex, int qt, int ns)
{
	if(l==r){
		if(tree[dex].l == qt) {cover(1, t, 1, l, l, ns); return l;}
		else return 0;
	}
	int mid = (l+r) >> 1;
	if(tree[dex].l >= qt){
		cover(1, t, 1, l, l+qt-1, ns);
		return l;
	}
	else if(tree[dex].m >= qt){
		pushdown(l, r, dex);
		int res = query(l, mid, dex*2, qt, ns);
		if(res) return res;
		if(tree[dex*2].r+tree[dex*2+1].l >= qt){
			res = mid-tree[dex*2].r+1;
			cover(1, t, 1, mid-tree[dex*2].r+1, mid-tree[dex*2].r+qt, ns);
			return res;
		}
		res = query(mid+1, r, dex*2+1, qt, ns);
		if(res) return res;
		else{
			res = r-tree[dex].r+1;
			cover(1, t, 1, res, res+qt-1, ns);
			return res;			
		}
	}
	else if(tree[dex].r >= qt){
		int res = r-tree[dex].r+1;
		cover(1, t, 1, res, res+qt-1, ns);
		return res;			
	}
	else return 0;
}
int requery(int l, int r, int dex, int qt, int ns)
{
	if(l==r){
		if(tree[dex].sl == qt) {cover(1, t, 1, l, l, ns); return l;}
		else return 0;
	}
	int mid = (l+r) >> 1;
	if(tree[dex].sl >= qt){
		cover(1, t, 1, l, l+qt-1, ns);
		return l;
	}
	else if(tree[dex].sm >= qt){
		int res = requery(l, mid, dex*2, qt, ns);
		if(res) return res;
		if(tree[dex*2].sr+tree[dex*2+1].sl >= qt){
			res = mid-tree[dex*2].sr+1;
			cover(1, t, 1, mid-tree[dex*2].sr+1, mid-tree[dex*2].sr+qt, ns);
			return res;
		}
		res = requery(mid+1, r, dex*2+1, qt, ns);
		if(res) return res;
		else{
			res = r-tree[dex].sr+1;
			cover(1, t, 1, res, res+qt-1, ns);
			return res;			
		}
	}
	else if(tree[dex].sr >= qt){
		int res = r-tree[dex].sr+1;
		cover(1, t, 1, res, res+qt-1, ns);
		return res;			
	}
	else return 0;
}

void solve()
{
	string s;
	scanf("%d%d", &t, &n);
	int l, r, qt;
	build(1, t, 1);
	for(int i = 1; i <= n; i++){
		scanf("\n"); cin >> s;
		if(s[0] == 'S'){
			scanf("%d%d", &l, &r);
			update(1, t, 1, l, r);
			printf("I am the hope of chinese chengxuyuan!!\n");
		}
		else{
			scanf("%d", &qt);
			/*for(int i = 1; i <= 6; i++)
				printf("%d %d %d\n", tree[i].l, tree[i].m, tree[i].r);*/
			int res = query(1, t, 1, qt, s[0] == 'N');
			if(s[0] == 'N'){
				if(res) printf("%d,don't put my gezi\n", res);
				else{
					//printf("%d\n", res);
					res = requery(1, t, 1, qt, 1);
					if(res) printf("%d,don't put my gezi\n", res);
					else printf("wait for me\n");
				}
			}
			else{
				if(res) printf("%d,let's fly\n", res);
				else printf("fly with yourself\n");
			}
		}
	}
}

int main()
{
	int kase;
	scanf("%d", &kase);
	for(int i = 1; i <= kase; i++) 
		printf("Case %d:\n", i), solve();
}
