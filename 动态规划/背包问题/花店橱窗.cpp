#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
#define ll long long
const ll INF = -2e18;
ll dp[maxn][maxn], val[maxn][maxn];
int ord[maxn], pre[maxn][maxn], now[maxn][maxn];

int main()
{
	int f, v, d;
	ll res = INF;
	scanf("%d%d", &f, &v);
	for(int i = 1; i <= f; i++)
		for(int j = 1; j <= v; j++)
			scanf("%lld", &val[i][j]), dp[i][j] = INF;
	for(int i = 0; i <= f; i++) dp[i][0] = INF;
	for(int i = 1; i <= v; i++){
		if(val[1][i] > dp[1][i-1]) now[1][i] = i, dp[1][i] = val[1][i];
		else now[1][i] = now[1][i-1], dp[1][i] = dp[1][i-1];
		for(int j = 2; j <= f; j++){
			if(dp[j][i-1] >= dp[j-1][i-1]+val[j][i])
				now[j][i] = now[j][i-1], dp[j][i] = dp[j][i-1], pre[j][i] = pre[j][i-1];
			else
				now[j][i] = i, dp[j][i] = dp[j-1][i-1]+val[j][i], pre[j][i] = now[j-1][i-1];
		}
		/*for(int k = 1; k <= f; k++) printf("%d ", now[k][i]);
		printf("\n");
		for(int k = 1; k <= f; k++) printf("%d ", pre[k][i]);
		printf("\n");*/
		if(res < dp[f][i]) d = i, res = dp[f][i];
		//res = max(res, dp[f][i]);
	}
	for(int i = f; i; i--){
		ord[i] = d;
		d = pre[i][d];
	}
	printf("%lld\n", res);
	for(int i = 1; i <= f; i++) printf("%d ", ord[i]);
	printf("\n");
}
