#include <bits/stdc++.h>
using namespace std;

const int maxn = 6000 + 50;
int h[maxn], v[maxn], to[maxn], head[maxn], cnt = 0, fa[maxn], dp[maxn][2];

void dfs(int rt, int fa)
{
	int tmp = 0, t = 0;
	for(int i = head[rt]; i; i = to[i]){
		int j = v[i];
		//printf("%d %d\n", rt, j);
		if(j == fa) continue;
		dfs(j, rt);
		tmp += max(dp[j][0], dp[j][1]);
		t += dp[j][0];
	}
	dp[rt][0] = tmp, dp[rt][1] = h[rt]+t;
}
void addedge(int a, int b)
{
	v[++cnt] = a;
	if(!head[b]) head[b] = cnt;
	else to[cnt] = head[b], head[b] = cnt;
}
int main()
{
	memset(to, 0, sizeof(to));
	memset(head, 0, sizeof(head));
	memset(fa, 0, sizeof(fa));
	int n, a, b, rt;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		addedge(a, b);
		fa[a] = b;
	}
	for(int i = 1; i <= n; i++)
		if(!fa[i]) {rt = i;break;}
	dfs(rt, -1);
	printf("%d\n", max(dp[rt][1], dp[rt][0]));
}
