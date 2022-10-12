#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[4010];
const ll mod = 2147483648;

int main()
{
	memset(dp, 0, sizeof(dp));
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i + j > n) break;
			(dp[i+j] += dp[j])%=mod;
		}
	}
	printf("%lld\n", (dp[n]+mod-1)%mod);
}
