#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
const int maxn = 1e3 + 10;
const int maxl = 205;
int dp[maxn][maxl][maxl], dis[maxl][maxl], p[maxn];
int n, l;

void floyd()
{
	rep(k, 1, l+1)
		rep(i, 1, l+1)
			rep(j, 1, l+1)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
	scanf("%d%d", &l, &n);
	rep(i, 1, l+1)
		rep(j, 1, l+1)
			scanf("%d", &dis[i][j]);
	//floyd();
	rep(i, 1, n+1) scanf("%d", &p[i]);
	p[0] = 3;
	memset(dp, INF, sizeof(dp));
	dp[0][1][2] = 0;
	
	rep(k, 0, n)
		rep(i, 1, l)
			rep(j, i+1, l+1){
				if(i != p[k+1] && j!= p[k+1])
				dp[k+1][i][j] = min(dp[k][i][j] + dis[p[k]][p[k+1]], dp[k+1][i][j]);
				if(j!= p[k+1] && p[k] != p[k+1])
				dp[k+1][min(p[k], j)][max(p[k], j)]= min(dp[k][i][j] + dis[i][p[k+1]], dp[k+1][min(p[k], j)][max(p[k], j)]);
				if(i != p[k+1] && p[k] != p[k+1])
				dp[k+1][min(p[k], i)][max(p[k], i)] = min(dp[k][i][j] + dis[j][p[k+1]], dp[k+1][min(p[k], i)][max(p[k], i)]);
			}
	int res = INF;
	rep(i, 1, l)
		rep(j, i+1, l+1)
			res = min(res, dp[n][i][j]);
	printf("%d\n", res);
}
 
