#include <bits/stdc++.h>
using namespace std;

int dp[10000+10], nb[100+10];
int main()
{
	memset(dp, 0, sizeof(dp));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &nb[i]);
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = m; j >=0 ; j--){
			if(nb[i]+j > m) continue;
			dp[nb[i]+j] += dp[j];
		}
	printf("%d\n", dp[m]);
}
