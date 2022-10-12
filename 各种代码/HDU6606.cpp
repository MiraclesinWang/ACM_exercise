#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
#define lowbit(x) x&(-x)
const int maxn = 2e5 + 10;
ll a[maxn], sm[maxn], tb[maxn];
int tree[maxn];
int m = 5;

void build(int n)
{
	for(int i = 1; i <= n; i++){
		int j = 0;
		while((1<<j) & i == 0) tree[i] = 0, j++; 
	}
}
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
	int a, b, c;
	build(5);
	while(true){
		scanf("%d%d%d", &a, &b, &c);
		if(a == 1) update(b, c);
		else printf("%d\n", query(b));
	}
	/*int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		sm[0] = 0, sm[n+1] = 1e18;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			sm[i] = a[i] + sm[i-1];
			tb[i] = sm[i];
		}
		sort(tb+1, tb+1+n);
		int m = unique(tb+1, tb+1+n) - tb-1;
		build(m);
		ll u = 1e9, d = -1e9;
		u *= (ll)n, d*= (ll)n;
		printf("%lld %lld\n", u, d);
		while(u != d){
			ll mid = ((u + d) >> 1)+1, tmp = 0;
			printf("%lld %lld %lld\n", d, mid, u);
			int pre = 0;
			bool flag = true;
			for(int i = 1; i <= k; i++){
				tmp += mid;
				int l = lower_bound(sm+1, sm+2+n, tmp) - sm;
				if(l == n+1) {flag = false;break;}
				if(sm[l] != tmp) l--;
				l = min(l, n-k+i); l = max(l, pre+1);
				tmp = sm[l], pre = l;
				if(mid == 3ll) printf("%d ", pre);
			}
			if(flag) d = mid;
			else u = mid-1ll;
		}
		printf("\n%lld\n", u);
	}*/
}
// -1000 1000 -1
