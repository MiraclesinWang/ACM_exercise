#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e6 + 5;
struct query{
	int x, z;
} zx[maxn];
int x[maxn*2], tree[maxn*16];
int t[maxn*2];
#define lowbit(x) x&(-x)

void build(int l, int r, int dex)
{
	if(l == r) tree[dex] = x[l], t[l] = dex;
	else{
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex] = min(tree[dex*2], tree[dex*2+1]);
	}
}
void update(int dex)
{
	tree[dex] = 1e9 +10;
	dex >>= 1;
	while(dex){
		tree[dex] = min(tree[dex*2], tree[dex*2+1]);
		dex >>= 1;
	}
}
int query(int l, int r, int dex, int x, int y)
{
	if(l>=x && r<= y) return tree[dex];
	else if(l > y || r < x) return 1e9 + 10;
	else{
		int mid = (l+r)>>1;
		return min(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
	}
}

int main() 
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= q; i++){
		scanf("%d%d", &zx[i].z, &zx[i].x);
		x[i] = zx[i].x;
		if(x[i] < n) x[i+q] = zx[i].x +1;
	}
	sort(x+1, x+1+2*q);
	int m = unique(x+1, x+1+2*q) - x - 1;
	for(int i = 1; i <= q; i++) zx[i].x = lower_bound(x+1, x+1+m, zx[i].x)-x;
	for(int i = 1; i <= m; i++) tree[i] = x[i];
	build(1, m, 1);
	for(int i = 1; i <= q; i++){
		if(zx[i].z == 1) update(t[zx[i].x]);
		else{
			int res = query(1, m, 1, zx[i].x, m);
			if(res > (int)1e9) printf("-1\n");
			else printf("%d\n", res);
		}
	}
}
