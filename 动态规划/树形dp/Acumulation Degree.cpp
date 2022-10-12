#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int h[maxn], v[maxn*2], to[maxn*2], head[maxn], cnt = 0, dp[maxn], val[maxn*2], tp[maxn], t[maxn], fa[maxn], vll[maxn];
int n, m;
void addedge(int a, int b, int vl)
{
	v[++cnt] = a, val[cnt] = vl;
	if(head[b] == -1) head[b] = cnt;
	else to[cnt] = head[b], head[b] = cnt;
}
void bfs(int rt, int f)
{
	for(int i = head[rt]; ~i; i = to[i]){
		int j = v[i];
		if(j == f) continue;
		fa[j] = rt, h[j] = val[i];
		t[++cnt] = j;
	}
}

void solve()
{
	memset(dp, 0, sizeof(dp));
	memset(head, -1, sizeof(head));
	memset(to, -1, sizeof(to));
	scanf("%d", &n);
	int a, b, vl;
	for(int i = 1; i < n; i++)
		scanf("%d%d%d", &a, &b, &vl), 
		addedge(a, b, vl), addedge(b, a, vl);
	cnt = 1; t[1] = 1; fa[1] = 1;
	for(int i = 1; i <= n; i++) bfs(t[i], fa[t[i]]);

	for(int r = n; r; r--){
		int rt = t[r];
		int tmp = 0, c = 0;
		for(int i = head[rt]; ~i; i = to[i]){
			int j = v[i];
			if(j == fa[rt]) continue;
			h[j] = val[i];
			tmp += dp[j];
			c++;
		}
		tp[rt] = tmp;
		if(c) dp[rt] = min(h[rt], tmp);
		else dp[rt] = h[rt];
		if(rt == 1) dp[rt] = tmp;	
	}
	
	vll[1] = 0;
	for(int r = 1; r <= n; r++){
		int rt = t[r];
		dp[rt] = vll[rt]+tp[rt];
		for(int i = head[rt]; ~i; i = to[i]){
			int j = v[i];
			if(j == fa[rt]) continue;
			vll[j] = min(vll[rt]+tp[rt]-dp[j], dp[j]);
		}
	}
	int res = -1;
	for(int i = 1; i <= n; i++)
		res = max(res, dp[i]);
	printf("%d\n", res);
}
int main()
{
	int kase;
	scanf("%d", &kase);
	while(kase--) solve();
}
