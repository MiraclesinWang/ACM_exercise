#include <cstdio>
using namespace std;

#define ll long long
const int maxn = 5e5 + 10;
const ll mod = 1e9 + 7;
//ll r[maxn], s[maxn];
int x[maxn];
ll dp[maxn], a[maxn], p[maxn], k[maxn], b[maxn];
int n, q;

ll qp(ll x, ll n)
{
	ll res = 1;
	while(n){
		if(n&1ll) res = res*x%mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}

void solve()
{
	scanf("%d%d", &n, &q);
	ll s, r;
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld%d%lld", &r, &s, &x[i], &a[i]);
		p[i] = qp(r, mod-2)*s % mod;
	}
	k[1] = 1, b[1] = 0;
	for(int i = 1; i <= n; i++)
		printf("%lld ", p[i]);
	printf("\n");
	for(int i = 1; i <= n; i++){
		k[i+1] = (k[i]*p[i]-(p[i]-1)*k[x[i]] -p[i]+mod)%mod;
		b[i+1] = (b[i]*p[i]-(p[i]-1)*b[x[i]] -p[i]+mod)%mod;
	}
	printf("%lld %lld\n", k[n+1], b[n+1]);
	dp[1] = (mod-b[n+1])*qp(k[n+1], mod-2)%mod;
	printf("%lld\n", dp[1]);
	for(int i = 2; i <= n; i++)
		dp[i] = (k[i]*dp[1]+b[i])%mod;
	int l, rr;
	for(int i = 0; i < q; i++){
		scanf("%d%d", &l, &rr);
		printf("%lld\n", dp[l]-dp[rr]);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve();
 } 
