#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int h[maxn], v[maxn], to[maxn], head[maxn], cnt = 0, fa[maxn], dp[maxn][maxn];
int n, m;
void addedge(int a, int b)
{
	v[++cnt] = a;
	if(head[b] == -1) head[b] = cnt;
	else to[cnt] = head[b], head[b] = cnt;
}
void dfs(int rt, int fa)
{
	dp[rt][0] = 0, dp[rt][1] = h[rt];
	int cnt = 0;
	for(int i = head[rt]; ~i; i = to[i]){
		int j = v[i];
		if(j == fa) continue;
		dfs(j, rt);
		for(int k = m; k; k--){
			for(int t = k-1; t; t--){
				if(!dp[j][t]) continue;
				dp[rt][k] = max(dp[rt][k], dp[rt][k-t]+dp[j][t]);
			}
		} 
		/*for(int k = m; k; k--)
			for(int t = 0; t < k; t++)
				if(dp[j][k-1-t]) dp[rt][k] = max(dp[j][k-t-1]+h[rt]+dp[rt][t], dp[rt][k]);*/
	}
	/*printf("%d:\n", rt);
	for(int i = 1; i <= m; i++) printf("%d ", dp[rt][i]);
	printf("\n");*/
}

int main()
{
	//freopen("test.txt", "r", stdin);
	memset(dp, 0, sizeof(dp));
	memset(head, -1, sizeof(head));
	memset(to, -1, sizeof(to));
	scanf("%d%d", &n, &m);
	m++;h[0] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &fa[i], &h[i]), 
		addedge(i, fa[i]);
	dfs(0, 0);
	printf("%d\n", dp[0][m]-1);
}
