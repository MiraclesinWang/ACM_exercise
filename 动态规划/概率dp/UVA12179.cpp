#include <bits/stdc++.h>
using namespace std;

int dis[105][105];
double dp[105][10005];
struct Cp{
	int dist, m;
} cp[1005];
#define rep(x, y) for(int i = x; i< y; i++)

void solve()
{
	int n, r, cnt, a, b, t, max_dis = 0, max_m = 0;
	char c;
	scanf("%d%d", &n, &r);
	rep(1, n+1){
		scanf("\n");
		for(int j = 1; j <= n; j++){
			scanf("%c", &c);
			if(c == 'Y') dis[i][j] = 1;
			else dis[i][j] = 10000;
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
	scanf("%d", &cnt);
	rep(1, cnt+1){
		scanf("%d%d%d", &a, &b, &t);
		cp[i].dist = dis[a][b], cp[i].m = t;
		if(cp[i].dist < 200)
			max_dis = max(cp[i].dist, max_dis);
		max_m = max(max_m, cp[i].m);
	}
	
	memset(dp, 0.0, sizeof(dp));
	dp[0][0] = 1.0;
	double p = 1.0 / double(r);
	for(int i = 1; i <= max_dis; i++){
		double tmp = dp[i-1][0];
		for(int j = 1; j <= max_m; j++){
			dp[i][j] = tmp * p;
			tmp += dp[i-1][j];
			if(j >= r) tmp -= dp[i-1][j-r];
		}
	}
	for(int i = 1; i <= max_dis; i++)
		for(int j = 2; j <= max_m; j++)
			dp[i][j] += dp[i][j-1];
	rep(1, cnt+1){
		if(cp[i].dist > 200) printf("0.0000\n");
		else printf("%f\n", dp[cp[i].dist][cp[i].m]);
	}	
	printf("\n");
}

int main()
{
	int kase;
	scanf("%d", &kase);
	rep(1, kase+1){
		printf("Case %d\n", i);
		solve();
	}
}
