#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 105
#define ll long long
const ll mod = 998244353;
ll dp[maxn][maxn];
bool vis[maxn];
struct color{
	int dex, clor;
	bool operator <(const color &oth)
	{return clor > oth.clor;}
} c[maxn];
int main()
{
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn ; j++)
			dp[i][j] = 1;
	//memset(dp, 1, sizeof(dp));
	int n, m, r;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i].clor),
		c[i].dex = i;
	sort(c+1, c+1+n);
	for(int i = 1; i <= n; i++){
		vis[c[i].dex] = true;
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				dp[i][j+k+1] += (dp[i-1][j]*dp[i+1][k]) % mod * (j+1) % mod * (k+1) %mod;
		int dex = c[i].dex - 1;
		while(dex > 0 && vis[dex]){
			for(int j = 0; j <= n; j++)
				dp[dex][j] = dp[i][j];
		}
		dex = c[i].dex - 1;
		while(dex <= n && vis[dex]){
			for(int j = 0; j <= n; j++)
				dp[dex][j] = dp[i][j];
		}		
	}
	ll res = 0;
	for(int i = 1; i <= n; i++)
		res = (res + dp[c[n].dex][i]) % mod;
	printf("%lld\n", res);
}
