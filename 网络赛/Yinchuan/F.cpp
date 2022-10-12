#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int num[maxn], d[maxn], tree[maxn*8], t[maxn], ans[maxn];

void build(int l, int r, int dex)
{
	tree[dex] = 0;
	if(l == r) t[num[l]] = dex;
	else{
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
int query(int l, int r, int dex, int x, int y)
{
	if(l>=x && r<= y) return tree[dex];
	if(l > y || r < x) return 0;
	int mid = (l+r)>>1;
	return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
}
void update(int dex, int val)
{
	tree[dex] = val;
	dex >>= 1;
	while(dex){
		tree[dex] = max(tree[dex*2], tree[dex*2+1]);
		dex >>= 1;
	}
}

void solve()
{
	ans[0] = 0;
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &num[i]), d[num[i]] = i;
	build(1, n, 1);
	for(int i = 1; i <= n; i++){
		int l = d[i]-k, r = d[i]+k;
		l = max(l, 1), r = min(r, n);
		int res = ans[query(1, n, 1, l, r)];
		ans[i] = res + 1;
		//printf("%d ", res+1);
		update(t[i], i);
	}
	for(int i = 1; i <= n; i++){
		printf("%d", ans[i]);
		printf(i==n?"\n":" ");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0; i <T; i++)
		solve();
} 
