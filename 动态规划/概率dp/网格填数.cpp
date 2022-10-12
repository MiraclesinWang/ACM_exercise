#include <bits/stdc++.h>
using namespace std;

double dp[2510][1260];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	memset(dp, 0.0, sizeof(dp));
	for(int i = n*m/2 - 1; i >= 0; i--) dp[n*m][i] = dp[n*m][i+1] + 1.0;
	for(int i = n*m-1; i >= 0; i--)
		for(int j = n*m/2; j >= 0; j--){
			if(j*2 > i) continue;
			dp[i][j] += (dp[i+1][j+1] + 1.0) * double(i-2*j) / double(n*m - i);
			if(i+2 <= n*m)
				dp[i][j] += (dp[i+2][j+1] + 1.0) * (1.0 - double(i-2*j) / double(n*m - i)) / double(n*m-i-1),
				dp[i][j] += (dp[i+2][j] + 1.0) * (1.0 - double(i-2*j) / double(n*m - i)) * double(n*m - 2*(i+1-j)) / double(n*m-1-i),
				dp[i][j] += (dp[i+2][j+1] + 2.0) * (1.0 - double(i-2*j) / double(n*m - i)) * double(i-2*j) / double(n*m-i-1);
		}
	printf("%.15f\n", dp[0][0]);
}
