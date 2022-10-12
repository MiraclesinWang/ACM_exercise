#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 1e3 + 10;
//const int INF = 2e9 + 100;
int dp[maxn][maxn], cnt[maxn][maxn];
struct city{
	string name;
	int val;
};
city nor[maxn], sou[maxn];

void solve()
{
	int sn, nn;
	string rub;
	scanf("%d", &nn);
	rep(i, 1, nn+1) scanf("\n"), cin >> rub >> nor[i].name >> nor[i].val;
	scanf("%d", &sn);
	rep(i, 1, sn+1) scanf("\n"), cin >> rub >> sou[i].name >> sou[i].val;
	
	memset(dp, -1, sizeof(dp));
	memset(cnt, 10000, sizeof(cnt));
	rep(i, 0, nn+1) cnt[i][0] = dp[i][0] = 0;
	rep(i, 0, sn+1) cnt[0][i] = dp[0][i] = 0;
	
	rep(i, 1, nn+1)
		rep(j, 1, sn+1){
			if(nor[i].name == sou[j].name)
				dp[i][j] = dp[i-1][j-1] + nor[i].val + sou[j].val, cnt[i][j] = cnt[i-1][j-1]+1;
			if(dp[i][j] < max(dp[i][j-1], dp[i-1][j])){
				if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j], cnt[i][j] = cnt[i-1][j];
				else if(dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1], cnt[i][j] = cnt[i][j-1];
				else dp[i][j] = dp[i][j-1], cnt[i][j] = min(cnt[i-1][j], cnt[i][j-1]);
			}
			else if(dp[i][j] == max(dp[i][j-1], dp[i-1][j])){
				if(dp[i-1][j] == dp[i][j]) cnt[i][j] = min(cnt[i][j], cnt[i-1][j]);
				if(dp[i][j-1] == dp[i][j]) cnt[i][j] = min(cnt[i][j], cnt[i][j-1]);
 			}
		}
	printf("%d %d\n", dp[nn][sn], cnt[nn][sn]);
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while(kase--) solve();
}
