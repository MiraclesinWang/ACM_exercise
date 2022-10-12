#include <bits/stdc++.h> 
using namespace std;

const int maxn = 110;
double dp[210][maxn];
int dist[maxn][maxn];
int m, n;


void solve()
{
	memset(dist, false, sizeof(dist));
	memset(dp, 0, sizeof(dp));
	int u, v;
	while(m--) scanf("%d%d", &u, &v), dist[u][v] += 1;
	dp[0][1] = 1.0;
	for(int step = 0; step < 200; step++)
		for(int i = 1; i <= n; i++){
			double tot = 1.0;
			for(int j = 1; j <= n; j++) tot += (double)dist[i][j];
			for(int j = 1; j <= n; j++)
				if(dist[i][j]) dp[step+1][j] += dp[step][i] * double(dist[i][j])/tot;
			dp[step+1][i] += dp[step][i] * 1.0/tot;
		}
	double mx = 0.0;
	for(int i = 1; i <= n; i++) mx = max(mx, dp[200][i]);
	printf("%f\n", mx);
}

int main()
{
	while(~scanf("%d%d", &n, &m)) solve();
}
