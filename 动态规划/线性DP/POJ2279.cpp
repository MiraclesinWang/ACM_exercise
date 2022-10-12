#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i <y; i++)
typedef long long ll;
ll dp[32][18][12][10][8];
int line[10];

int main()
{
	int n;
	while(scanf("%d", &n), n){
		memset(line, 0, sizeof(line));
		rep(0, n) scanf("%d", &line[i]);
		memset(dp, 0ll, sizeof(dp));
		dp[0][0][0][0][0] = 1;
		for(int i = 0; i <= line[0]; i++)
			for(int j = 0; j <= line[1]; j++)
				for(int k = 0; k <= line[2]; k++)
					for(int p = 0; p <= line[3]; p++)
						for(int q = 0; q <= line[4]; q++){
							int m = i, s = line[0];
							if(i) dp[i][j][k][p][q] += dp[i-1][j][k][p][q];
							if(j && (j <= m || j > s)) dp[i][j][k][p][q] += dp[i][j-1][k][p][q];
							m = min(m, j), s = max(s, line[1]);
							if(k && (k <= m || k > s)) dp[i][j][k][p][q] += dp[i][j][k-1][p][q];
							m = min(m, k), s = max(s, line[2]);
							if(p && (p <= m || p > s)) dp[i][j][k][p][q] += dp[i][j][k][p-1][q];
							m = min(m, p), s = max(s, line[3]);
							if(q && (q <= m || q > s)) dp[i][j][k][p][q] += dp[i][j][k][p][q-1];
							//printf("%d %d %d %d %d %lld\n", i, j, k, p, q, dp[i][j][k][p][q]);
						}
		printf("%lld\n", dp[line[0]][line[1]][line[2]][line[3]][line[4]]);
	}	
}
