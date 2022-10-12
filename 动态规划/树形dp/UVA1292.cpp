#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1500 + 10
int fa[maxn];
int sn[maxn][maxn];
int dp[maxn][2];
int n;

void recur(int dex)
{
	if(sn[dex][0] == 0) {
		dp[dex][0] = 0, dp[dex][1] = 1;
		return;	
	}
	dp[dex][1] = 1;
	for(int i = 1; i <= sn[dex][0]; i++){
		recur(sn[dex][i]);
		dp[dex][0] += dp[sn[dex][i]][1];
		dp[dex][1] += min(dp[sn[dex][i]][1], dp[sn[dex][i]][0]);
	}
	return ;
}

void solve()
{
	int rub, rt;
	for(int i = 0; i < n; i++) fa[i] = i;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++){
		scanf("%d:(%d)", &rub, &sn[i][0]);
		for(int j = 1; j <= sn[i][0]; j++)
			scanf("%d", &sn[i][j]),
			fa[sn[i][j]] = i;
	}
	for(int i = 0; i < n; i++)
		if(fa[i] == i) rt = i;
	printf("%d\n", rt);
	recur(rt);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	printf("%d\n", min(dp[rt][0], dp[rt][1]));
}

int main()
{
	while(scanf("%d", &n) != EOF)
		solve();
}
