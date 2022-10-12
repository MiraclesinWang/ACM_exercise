#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 9;
const int maxn = 1296 + 10;
ll dp[maxn][maxn];  // dp[i][j][0] = sigma(k 1~n) dp[i][j][k]
int n, l;
int c[maxn];

ll qp(ll a, ll p)
{
	ll res = 1;
	while(p){
		if(p & 1ll) res = (res * a) % mod;
		p >>= 1;
		a = (a*a)%mod;
	}
	return res;
}
ll inv(ll a) {return qp(a, mod-2);}

int main()
{
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	memset(dp, 0, sizeof(dp));
	dp[1][c[n]] = dp[1][0] = 1;
	for(int i = n -1; i; i--){
		ll tmp = inv(n-i);
		for(int j = l; j > 1; j--)
			(dp[j][0] += (dp[j-1][0] - dp[j-1][c[i]] + dp[j][c[i]] + mod) * tmp) %= mod,
			(dp[j][c[i]] += (dp[j-1][0] - dp[j-1][c[i]] + dp[j][c[i]] + mod) * tmp) %= mod;
		if(c[i] == c[n])
			(dp[1][0] += dp[1][c[n]] * tmp) %= mod,
			(dp[1][c[n]] += dp[1][c[n]]*tmp) %= mod;	
	}
	for(int i = n-1; i; i--)
		(dp[l][0] *= (long long)(n-i)) %= mod;
	printf("%lld\n", dp[l][0]);
}
