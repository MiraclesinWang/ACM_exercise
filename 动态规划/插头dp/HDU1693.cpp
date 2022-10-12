#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxs = (1<<12);
#define ll long long
ll dp[15][15][maxs][2];
int mp[15][15];
int n, m;

int solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for (int j = 1; j <= m; j++)
			scanf("%d", &mp[i][j]);		
	}
	int s = (1<<m);
	memset(dp, 0, sizeof(dp));
	if(n==1 || m==1) return 0;
	dp[0][m][0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(mp[i][1]){
			for(int k = 0; k < s; k++){
				dp[i][1][k^1][1] = dp[i-1][m][k][0];
				if(k&1)
					dp[i][1][k][0] += dp[i-1][m][k][0];
			}
		}
		else{
			for(int k = 0; k < s; k++)
				if(!(k&1)) dp[i][1][k][0] = dp[i-1][m][k][0];
		}
		
		for(int j = 2; j < m; j++){
			if(mp[i][j]){
				for(int k = 0; k < s; k++){
					dp[i][j][k^(1<<(j-1))][0] += dp[i][j-1][k][1];
					dp[i][j][k^(1<<(j-1))][1] += dp[i][j-1][k][0];
					if(k&(1<<(j-1)))
						dp[i][j][k][0] += dp[i][j-1][k][0];
					else
						dp[i][j][k][1] += dp[i][j-1][k][1];
				}
			}
			else{
				for(int k = 0; k < s; k++)
					if(!(k&(1<<(j-1)))) dp[i][j][k][0] = dp[i][j-1][k][0];
			}
		}
		
		if(mp[i][m]){
			for(int k = 0; k < s; k++){
				dp[i][m][k^(1<<(m-1))][0] = dp[i][m-1][k][1];
				if(k&(1<<(m-1)))
					dp[i][m][k][0] += dp[i][m-1][k][0];
			}
		}
		else{
			for(int k = 0; k < s; k++)
				if(!(k&(1<<(m-1)))) dp[i][m][k][0] = dp[i][m-1][k][0];
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		solve();
		printf("Case %d: There are %lld ways to eat the trees.\n", i, dp[n][m][0][0]);
	}
}
