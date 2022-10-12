#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
int tree[maxn*16], t[maxn*2];
ll a[maxn], tr[maxn*8];

void build(int l, int r, int dex)
{
	tree[dex] = 0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
	else t[l] = dex;
}
void update(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) tree[dex]++;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		update(l, mid, dex*2, x, y), update(mid+1, r, dex*2+1, x, y);
	}
}
void pushdown(int l, int r, int dex)
{
	if(l != r){
		int mid = (l+r) >> 1;
		tree[dex*2] += tree[dex], tree[dex*2+1] += tree[dex];
		pushdown(l, mid, dex*2), pushdown(mid+1, r, dex*2+1);
	}
}
void Build(int l, int r, int dex)
{
	tr[dex] = 0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tr[dex] = tr[dex*2] + tr[dex*2+1];
	}	
	else tr[dex] = a[l];
}
ll query(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) return tr[dex];
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		return query(l, mid, dex*2, x, y)+ query(mid+1, r, dex*2+1, x, y);
	}	
}

int main()
{
	int n, k, m, l, r;
	while(scanf("%d%d%d", &n, &k, &m) != EOF){
		ll res = 0, tmp = 0;
		build(1, n*2, 1);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 1; i <= m; i++){
			scanf("%d%d", &l, &r);
			update(1, n*2, 1, l*2, r*2);
		}
		pushdown(1, n*2, 1);
		for(int i = 1; i <= n*2; i++){
			if(i%2 == 0) printf("%d ", tree[t[i]]);
			if(tree[t[i]] >= k){
				if(i%2 == 0) tmp += a[i/2];
			}
			else res = max(res, tmp), tmp = 0;
		}
		//printf("%lld\n", res);
	}
} 

