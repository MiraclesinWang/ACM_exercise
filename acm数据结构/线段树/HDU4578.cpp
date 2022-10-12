#include <cstdio>
#include <cstring>
using namespace std; 

#define ll long long
const int maxn = 1e5+10;
const int mod = 10007;
int n, m;

struct node{
	int k, b, c;
	int p[4];
} tree[maxn*8];

void change(int dex, int k, int b, int l, int r)
{
	tree[dex].p[3] = (k*k%mod*k%mod*tree[dex].p[3] + 3*k*k%mod*b%mod*tree[dex].p[2] + 3*k*b%mod*b%mod*tree[dex].p[1] + b*b%mod*b%mod*(r-l+1)%mod) %mod;
	tree[dex].p[2] = (k*k%mod*tree[dex].p[2]+2*k*b%mod*tree[dex].p[1]+b*b%mod*(r-l+1))%mod;
	tree[dex].p[1] = (k*tree[dex].p[1]+b*(r-l+1))%mod;	
}
void pushdown(int l, int r, int dex)
{
	int mid = (l+r) >> 1;
	if(tree[dex].c){
		tree[dex*2].c = tree[dex*2+1].c = tree[dex].c;
		tree[dex*2].k = tree[dex*2+1].k = tree[dex].k;
		tree[dex*2].b = tree[dex*2+1].b = tree[dex].b;
		tree[dex].b = tree[dex].c = 0, tree[dex].k = 1;
		int tmp = (tree[dex*2].c*tree[dex*2].k+tree[dex*2].b)%mod, t = 1;
		for(int i = 1; i < 4; i++)
			t = t*tmp%mod, tree[dex*2].p[i] = t*(mid-l+1)%mod, tree[dex*2+1].p[i] = t*(r-mid)%mod;
	}
	else{
		tree[dex*2].k = tree[dex*2].k*tree[dex].k%mod;
		tree[dex*2+1].k = tree[dex*2+1].k*tree[dex].k%mod;
		tree[dex*2].b = (tree[dex*2].b*tree[dex].k+tree[dex].b)%mod;
		tree[dex*2+1].b = (tree[dex*2+1].b*tree[dex].k+tree[dex].b)%mod;
		int k = tree[dex].k, b = tree[dex].b;
		tree[dex].k = 1, tree[dex].b = 0;
		change(dex*2, k, b, l, mid), change(dex*2+1, k, b, mid+1, r);
	}
}
void build(int l, int r, int dex)
{
	tree[dex].b = tree[dex].c = 0, tree[dex].k = 1;
	memset(tree[dex].p, 0, sizeof(tree[dex].p));
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
int query(int l, int r, int dex, int x, int y, int c)
{
	if(l >= x && r <= y) return tree[dex].p[c];
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		int res = query(l, mid, dex*2, x, y, c)+ query(mid+1, r, dex*2+1, x, y, c);
		for(int i = 1; i <= 3; i++)
			tree[dex].p[i] = (tree[dex*2].p[i] + tree[dex*2+1].p[i])%mod;
		return res%mod;
	}
}
void update(int l, int r, int dex, int x, int y, int c)
{
	if(l >= x && r <= y){
		tree[dex].c = c; tree[dex].k = 1, tree[dex].b = 0;
		int tmp = c;
		for(int i = 1; i < 4; i++)
			tree[dex].p[i] = (r-l+1)*tmp%mod, tmp = tmp * c %mod;
	}
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		update(l, mid, dex*2, x, y, c), update(mid+1, r, dex*2+1, x, y, c);
		for(int i = 1; i < 4; i++)
			tree[dex].p[i] = (tree[dex*2].p[i] + tree[dex*2+1].p[i])%mod;
	}
}
void mutiply(int l, int r, int dex, int x, int y, int c)
{
	if(l >= x && r <= y){
		tree[dex].k *= c, tree[dex].b *= c;
		tree[dex].k%=mod, tree[dex].b%=mod;
		int tmp = c;
		for(int i = 1; i < 4; i++)
			tree[dex].p[i] = (tree[dex].p[i]*tmp)%mod, tmp = tmp * c %mod;
	}
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		mutiply(l, mid, dex*2, x, y, c), mutiply(mid+1, r, dex*2+1, x, y, c);
		for(int i = 1; i < 4; i++)
			tree[dex].p[i] = (tree[dex*2].p[i] + tree[dex*2+1].p[i])%mod;
	}	
}
void add(int l, int r, int dex, int x, int y, int c)
{
	if(l >= x && r <= y){
		tree[dex].b = (c+tree[dex].b)%mod;
		change(dex, 1, c, l, r);
	}
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		pushdown(l, r, dex);
		add(l, mid, dex*2, x, y, c), add(mid+1, r, dex*2+1, x, y, c);
		for(int i = 1; i < 4; i++)
			tree[dex].p[i] = (tree[dex*2].p[i] + tree[dex*2+1].p[i])%mod;
	}
}

int main()
{
	//freopen("out.txt", "w", stdout);
	int x, y, c, cmd;
	while(scanf("%d%d", &n, &m), n||m){
		build(1, n, 1);
		while(m--){
			scanf("%d%d%d%d", &cmd, &x, &y, &c);
			if(cmd == 4) printf("%d\n", query(1, n, 1, x, y, c));
			else if(cmd == 3) update(1, n, 1, x, y, c);
			else if(cmd == 2) mutiply(1, n, 1, x, y, c);
			else add(1, n, 1, x, y, c);
		}		
	}
}

/*
5 20
3 3 5 7
4 1 1 1
4 2 2 1
4 3 3 1
4 4 4 1
4 5 5 1
1 2 4 4
4 1 1 1
4 2 2 1
4 3 3 1
4 4 4 1
4 5 5 1
4 1 5 1
4 1 5 2
*/
