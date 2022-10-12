#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
struct node{
	int sm, m;
	int res;
} tree[maxn*8];
int num[maxn];

void build(int l, int r, int dex)
{
	tree[dex].res = 0;
	if(l == r) tree[dex].m = num[l], tree[dex].sm = 0;
	else{
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex].m = min(tree[dex*2].m, tree[dex*2+1].m);
		tree[dex].sm = 0;
	}
}
void update(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) tree[dex].sm++;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		update(l, mid, dex*2, x, y), update(mid+1, r, dex*2+1, x, y);
	}
}
int query(int l, int r, int dex, int x, int y)
{
	printf("%d %d %d %d\n", l, r, x, y);
	if(l > y || r < x) return 0;
	else if(l >= x && r <= y){
		if(tree[dex].m > tree[dex].sm) return tree[dex].res;
		if(l != r){
			int mid = (l+r) >> 1;
			tree[dex*2].sm += tree[dex].sm, tree[dex*2+1].sm += tree[dex].sm;
			tree[dex].sm = 0;
			tree[dex].res = query(l, mid, dex*2, x, y) + query(mid+1, r, dex*2+1, x, y),
			tree[dex].m = min(tree[dex*2].m, tree[dex*2+1].m);
		}
		else{
			tree[dex].res++, tree[dex].sm -= tree[dex].m;
			tree[dex].res += tree[dex].sm / num[l], tree[dex].m = num[l] - tree[dex].sm, tree[dex].sm = 0;
		}
		printf("%d\n", tree[dex].res);
		return tree[dex].res;
	}
	else{
		int mid = (l+r) >> 1;
		tree[dex*2].sm += tree[dex].sm, tree[dex*2+1].sm += tree[dex].sm;
		tree[dex].sm = 0;
		tree[dex].res = query(l, mid, dex*2, x, y) + query(mid+1, r, dex*2+1, x, y);
		tree[dex].m = min(tree[dex*2].m, tree[dex*2+1].m);
		return tree[dex].res;
	}
}

int main()
{
	int n, q, l, r;
	char cmd[10];
	while(scanf("%d%d", &n, &q) != EOF){
		for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
		build(1, n, 1);
		while(q--){
			scanf("\n%s%d%d", cmd, &l, &r);
			if(cmd[0] == 'a') update(1, n, 1, l, r);
			else printf("%d\n", query(1, n, 1, l, r));
		}
	}
}
