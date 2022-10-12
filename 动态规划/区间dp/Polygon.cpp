#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;
const LL INF = 0x3f3f3f3f;
LL dp[55][55], mn[55][55], res[55];
int n, vl[55];
char sg[55];

void push_forward(int dex)
{
	memset(dp, -INF, sizeof(dp));
	memset(mn, INF, sizeof(mn));
	rep(i, 1, n+1) dp[i][i] = vl[i], mn[i][i]=vl[i];
	rep(k, 1, n){
		rep(i, 1, n-k+1){
			int j = i+k;
			rep(p, i, j){
				if(sg[p]=='t')
					dp[i][j] = max(dp[i][j], dp[i][p] + dp[p+1][j]),
					mn[i][j] = min(mn[i][j], mn[i][p] + mn[p+1][j]);
				else{
					dp[i][j] = max(dp[i][j], dp[i][p] * dp[p+1][j]);
					if(mn[i][p] < 0 && mn[p+1][j] < 0)
						dp[i][j] = max(dp[i][j], mn[i][p] * mn[p+1][j]);
					
					mn[i][j] = min(mn[i][j], mn[i][p] * mn[p+1][j]);
					mn[i][j] = min(mn[i][j], dp[i][p] * mn[p+1][j]);
					mn[i][j] = min(mn[i][j], mn[i][p] * dp[p+1][j]);
					mn[i][j] = min(mn[i][j], dp[i][p] * dp[p+1][j]);
				}
			}
		}
	}
	res[dex] = dp[1][n];
	rep(i, 0, n) vl[i] = vl[i+1];
	vl[n] = vl[0];
	sg[n] = sg[0];
	rep(i, 0, n) sg[i] = sg[i+1];
}

int main()
{
	scanf("%d\n", &n);
	rep(i, 0, n){
		scanf("%c%d", &sg[i], &vl[i+1]);
		if(i < n-1) scanf(" ");
	}
	rep(i, 1, n+1) push_forward(i);
	LL mres = -INF;
	rep(i, 1, n+1) mres = max(mres, res[i]);
	printf("%lld\n", mres);
	rep(i, 1, n+1){
		if(mres == res[i]) printf("%d ", i);
	}
}
