#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
#define maxn 1005
#define maxm 200000 + 10
const int base = 1e5 + 5;
int dp[maxm];
int s[maxn], f[maxn];
bool vis[maxn];
int pst[maxm], len;

void init()
{
	len = 0;
	for(int i = 0; i < maxm; i++)
		vis[i] = false;
	memset(dp, 0, sizeof(dp));
}

void solve()
{
	int res = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &s[i], &f[i]);
	init();
	pst[len++] = base;
	for(int i = 1; i <= n; i++){
		int tmp = len;
		for(int j = 0; j < tmp; j++){
			if(vis[s[i] + pst[j]])
				dp[s[i] + pst[j]] = max(dp[s[i] + pst[j]], dp[pst[j]] + f[i]);
			else
				vis[s[i] + pst[j]] = true,
				dp[s[i] + pst[j]] = f[i] + dp[pst[j]],
				pst[len++] = s[i] + pst[j];
		}	
	}
	/*for(int i = 0; i < len; i++)
		printf("%d %d\n", pst[i] - base, dp[pst[i]]);*/
	for(int i = base; i < maxm ; i++)
		if(vis[i] && dp[i] >= 0) res = max(res, dp[i] + i - base);
	printf("%d\n", res);
}

int main()
{
	scanf("%d", &n);
	solve();
}
