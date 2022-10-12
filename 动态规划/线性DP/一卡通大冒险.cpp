#include <bits/stdc++.h>
using namespace std;

const int mod = 1e3;
const int maxn = 2e3 + 5;
int dp[maxn][maxn];
#define rep(i, x, y) for(int i = x; i < y; i++)

void init()
{
	memset(dp, 0, sizeof(dp));
	rep(i, 1, maxn){
		dp[i][1] = 1;
		rep(j, 2, i+1){
			dp[i][j] = (j*dp[i-1][j] + dp[i-1][j-1])%mod;
		}
	}
}

int main()
{
	init();
	int kase, n;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d", &n);
		int res = 0;
		rep(i, 1, n+1) res = (res+dp[n][i])%mod;
		printf("%d\n", res);
	}
}
