#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int dp[maxn][maxn], w[maxn];
#define INF 0x3f3f3f3f

int main()
{
	memset(dp, INF, sizeof(dp));
	w[0] = 0;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &dp[i][i]), w[i] = w[i-1]+dp[i][i], dp[i][i] = 0;
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= n; j++){
			if(i+j > n) break;
			for(int k = j; k <i+j; k++) dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]+w[j+i]-w[j-1]);
		} 
	printf("%d\n", dp[1][n]);
}
