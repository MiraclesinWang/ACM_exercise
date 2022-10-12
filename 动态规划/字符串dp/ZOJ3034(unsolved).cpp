#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define maxn 1005
int n, m;
string nor[maxn], sou[maxn];
string rub;
int nval[maxn], sval[maxn];
int dp[maxn][maxn];
int cnt[maxn][maxn];

void solve()
{
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("\n"), cin >> rub, scanf(" "), cin >> nor[i],
		scanf("%d", &nval[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("\n"), cin >> rub, scanf(" "), cin >> sou[i],
		scanf("%d", &sval[i]);
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	for(int i = 0; i <= m; i++) dp[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(nor[i] == sou[j]){
				dp[i][j] = dp[i-1][j-1] + nval[i] + sval[j];
				cnt[i][j] = cnt[i-1][j-1] + 1;
			}
			else{
				if(dp[i][j-1] == dp[i-1][j]) dp[i][j] = dp[i-1][j], cnt[i][j] = min(cnt[i-1][j], cnt[i][j-1]);
				else if(dp[i][j-1] > dp[i-1][j]) dp[i][j] = dp[i][j-1], cnt [i][j] = cnt [i][j-1];
				else dp[i][j] = dp[i-1][j], cnt[i][j] = cnt[i-1][j];				
			}
		}
	}
	printf("%d %d\n", dp[n][m], cnt[n][m]);
}

int main()
{
	int kase;
	scanf("%d", &kase);
	for(int k = 0; k < kase; k++)
		solve();
}
