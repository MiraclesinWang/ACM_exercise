#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
#define lowbit(x) x&(-x)
const int maxn = 2e5 + 10;
ll a[maxn], sm[maxn], tb[maxn];
int tree[maxn], tt[maxn];
int m;

void update(int d, int val)
{
	for(int i = d; i <= m; i += lowbit(i))
		tree[i] = max(tree[i], val); 
}
int query(int d)
{
	int ans = 0;
	for(int i = d; i > 0; i -= lowbit(i))
		ans = max(tree[i], ans);
	return ans; 
}

int main()
{
	int t, n, k, dd;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		sm[0] = 0, sm[n+1] = 1e18, tb[n+1] = 0;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			sm[i] = a[i] + sm[i-1];
			tb[i] = sm[i];
		}
		sort(tb+1, tb+2+n);
		m = unique(tb+1, tb+2+n) - tb-1;
		for(int i = 1; i <= n; i++) tt[i] = lower_bound(tb+1, tb+1+m, sm[i]) - tb;
		tb[m+1] = 1e18;
		ll u = 1e9, d = -1e9;
		u *= (ll)n, d*= (ll)n;
		for(int i = 1; i <= m; i++)
			if(tb[i] == 0) {dd = i;break;}	
		while(u != d){
			memset(tree, 0, sizeof(tree));
			ll mid = ((u + d) >> 1);
			int ans = 0;
			for(int i = 1; i <= n; i++){
				int dex = lower_bound(tb+1, tb+1+m, sm[i]-mid) - tb;
				if(dex == m+1){
					if(sm[i] <= mid) update(m+1-tt[i], 1), ans = max(1, ans);
					continue;
				}
				int res = query(m-dex+1);
				if(sm[i] <= mid) update(m+1-tt[i], 1), ans = max(ans, 1);
				if(res){
					update(m+1-tt[i], res+1);
					ans = max(ans, res+1);					
				}
			}
			if(ans >= k) u = mid;
			else d = mid+1;
		}
		printf("%lld\n", u);
	}
}
