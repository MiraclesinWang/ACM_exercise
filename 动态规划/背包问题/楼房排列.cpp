#include <bits/stdc++.h>
using namespace std;

#define ll long long
const double mod = (double)1e9 + 9;
const int maxn = 1296 + 10;
double dp[maxn][maxn];  // dp[i][j][0] = sigma(k 1~n) dp[i][j][k]
int n, l;
int c[maxn];

int main()
{
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	memset(dp, 0, sizeof(dp));
	dp[1][c[n]] = dp[1][0] = 1;
	for(int i = n -1; i; i--){
		double tmp = (double) (n-i);
		for(int j = l; j > 1; j--)
			dp[j][0] += (dp[j-1][0] - dp[j-1][c[i]] + dp[j][c[i]]) / tmp,
			dp[j][0] -= (long long)(dp[j][0] / mod) * mod,
			dp[j][c[i]] += (dp[j-1][0] - dp[j-1][c[i]] + dp[j][c[i]]) / tmp,
			dp[j][c[i]] -= (long long)(dp[j][c[i]] / mod) * mod;
		dp[1][0] += dp[1][0] / tmp, 
		dp[1][0] -= (long long)(dp[1][0] / mod) * mod;
	}
	for(int i = n-1; i; i--)
		dp[l][0] *= double(n-i),
		dp[l][0] -= (long long)(dp[l][0] / mod) * mod;
	printf("%d\n", (long long)round(dp[l][0]));
}
