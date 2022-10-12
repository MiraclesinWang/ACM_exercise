#include <bits/stdc++.h>
using namespace std;

int a[400], dp[50][50][50][50], cd[5];
int n, m, tmp;
int cal(int x, int y, int z, int m) {return a[n-x-2*y-3*z-4*m];}

int main()
{
	memset(cd, 0, sizeof(cd));
	memset(dp, 0, sizeof(dp));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &tmp), cd[tmp]++;
	dp[cd[1]][cd[2]][cd[3]][cd[4]] = a[1];
	for(int i = cd[1]; ~i; i--){
		for(int j = cd[2]; ~j; j--){
			for(int k = cd[3]; ~k; k--){
				for(int t = cd[4]; ~t; t--){
					if(i) dp[i-1][j][k][t] = max(dp[i-1][j][k][t], dp[i][j][k][t]+cal(i-1, j, k, t));
					if(j) dp[i][j-1][k][t] = max(dp[i][j-1][k][t], dp[i][j][k][t]+cal(i, j-1, k, t));
					if(k) dp[i][j][k-1][t] = max(dp[i][j][k-1][t], dp[i][j][k][t]+cal(i, j, k-1, t));
					if(t) dp[i][j][k][t-1] = max(dp[i][j][k][t-1], dp[i][j][k][t]+cal(i, j, k, t-1));
				}
			}
		}
	}
	printf("%d\n", dp[0][0][0][0]);
 } 
