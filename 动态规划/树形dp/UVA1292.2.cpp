#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1500 + 10;
int sn[maxn][maxn], dp[maxn][2];
int n;

void bfs(int dex)
{
	int z = 0, o = 1;
	for(int i = 1; i <= sn[dex][0]; i++){
		bfs(sn[dex][i]);
		z += dp[sn[dex][i]][1], o += min(dp[sn[dex][i]][0], dp[sn[dex][i]][1]);
	}
	dp[dex][0] = z, dp[dex][1] = o;
}

void solve()
{
	int rt;
	for(int i = 0; i < n; i++){
		int cnt, dex;
		scanf("%d:(%d)", &dex, &cnt);
		if(!i) rt = dex;
		sn[dex][0] = cnt;
		for(int j = 1; j <= cnt; j++) scanf("%d", &sn[dex][j]);
	}
	bfs(rt);
	printf("%d\n", min(dp[rt][0], dp[rt][1]));
}

int main()
{while(scanf("%d", &n) != EOF) solve();} 
