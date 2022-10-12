#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 100000 + 10
int dp[maxn], cnt[maxn];
int u[maxn], v[maxn], to[maxn], ct = 0, sn[maxn];
int fa[maxn];
int n;

void addedge(int a, int b)
{
	u[++ct] = a, v[ct] = b;
	if(sn[a] == 0) sn[a] = ct;
	else to[ct] = sn[a], sn[a] = ct;
}
void init()
{
	memset(to, 0, sizeof(to));
	memset(sn, 0, sizeof(sn));
	for(int i = 0; i < maxn ; i++)
		fa[i] = i;
}

int frt(int x) {return fa[x] == x? x: fa[x] = frt(fa[x]);}

void bfs(int rt, int f)
{
	int lo = sn[rt];
	cnt[rt] = 1, dp[rt] = 0;
	while(lo){
		if(v[lo] == f) {lo = to[lo]; continue;}
		int j = v[lo];
		bfs(j, rt);
		cnt[rt] += cnt[j], dp[rt] += dp[j] + cnt[j];
		lo = to[lo];
	}
}

void rebfs(int rt, int f)
{
	int lo = sn[rt];
	while(lo){
		if(v[lo] == f) {lo = to[lo]; continue;}
		int j = v[lo];
		dp[j] = dp[rt] - cnt[j] - dp[j] + (n - cnt[j]);
		rebfs(j, rt);
		lo = to[lo];
	}
}

int main()
{
	init();
	int a, b;
	scanf("%d", &n);
	for(int i = 1; i <= n-2; i++){
		scanf("%d%d", &a, &b);
		addedge(a, b), addedge(b, a);
		if(frt(a) != frt(b)) fa[frt(a)] = frt(b);
	}
	for(int i = 1; i <= n; i++)
		frt(i);
	int rt1 = fa[1], rt2;
	for(int i = 2; i <= n; i++)
		if(fa[i] != rt1) {rt2 = fa[i];break;}
	bfs(rt1, 0), bfs(rt2, 0);
	rebfs(rt1, 0), rebfs(rt2, 0);
	int c1 = rt1, c2 = rt2;
	for(int i = 1; i <= n; i++){
		if(fa[i] == rt1 && dp[c1] > dp[i]) c1 = i;
		if(fa[i] == rt2 && dp[c2] > dp[i]) c2 = i; 
	}
	addedge(c1, c2), addedge(c2, c1);
	bfs(rt1, 0); rebfs(rt1, 0);
	int res = 0;
	for(int i =1; i <= n; i++)
		res += dp[i];
	res /= 2;
	printf("%d\n", res);
}
