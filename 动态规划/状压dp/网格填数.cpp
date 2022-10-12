#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
int Map[60][60], cnt[20][20];
ll dp[20][20][1030*2];
int h, w, n, m;
ll fr[2600], fv[2600];



int main()
{
	fr[0] = fv[0] = 1;
	for(int i = 1; i <= 2500; i++) fr[i] = (4*fr[i-1])%mod, fv[i] = (5*fv[i-1])%mod;
	char c;
	scanf("%d%d%d%d", &h, &w, &n, &m);
	for(int i = 1; i <= h; i++){
		scanf("\n");
		for(int j = 1; j <=w ; j++){
			scanf("%c", &c);
			if(c != '.') Map[i][j] = (c - '0')%2;
			else Map[i][j] = -1;
		}	
	}
	memset(dp, 0, sizeof(dp));
	dp[0][m][1] = 1;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			int tmp = -1, Cnt = 0;
			ll res = 1;
			for(int x = i; x <= h; x+=n)
				for(int y = j; y <= w; y+=m){
					if(Map[x][y] >= 0){
						if(tmp < 0) tmp = Map[x][y];
						else if(Map[x][y] ^ tmp) {printf("0\n");return 0;}
					}
					else Cnt++;
				}
			cnt[i][j] = Cnt, Map[i][j] = tmp;
		}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(j > 1){
				int x = i, y = j-1;
				for(int k = 0; k < (1<<(m+1)); k++){
					if(Map[i][j] == 1) (dp[i][j][(k^(1<<j))^1] += (dp[x][y][k] * fv[cnt[i][j]])%mod)%=mod;
					else if(Map[i][j] == 0) (dp[i][j][k] += (dp[x][y][k] * fr[cnt[i][j]])%mod)%=mod;
					else 
						(dp[i][j][(k^(1<<j))^1] += (dp[x][y][k] * fv[cnt[i][j]])%mod)%=mod,
						(dp[i][j][k] += (dp[x][y][k] * fr[cnt[i][j]])%mod)%=mod;
					//printf("%d %d %d %lld:\n%d %lld\n%d %lld\n", i, j, k, dp[x][y][k], (k^(1<<j))^1, dp[i][j][(k^(1<<j))^1], k, dp[i][j][k]);
				}
			}
			else{
				int x = i-1, y = m;
				for(int k = 0; k < (1<<(m+1)); k++){
					if(!(k&1)) continue;
					if(Map[i][j] == 1) (dp[i][j][k^(1<<j)] += (dp[x][y][k] * fv[cnt[i][j]])%mod)%=mod;
					else if(Map[i][j] == 0) (dp[i][j][k^1] += (dp[x][y][k] * fr[cnt[i][j]])%mod)%=mod;
					else
						(dp[i][j][k^(1<<j)] += (dp[x][y][k] * fv[cnt[i][j]])%mod)%=mod,
						(dp[i][j][k^1] += (dp[x][y][k] * fr[cnt[i][j]])%mod)%=mod;
					//printf("%d %d %d %lld:\n%d %lld\n%d %lld\n", i, j, k, dp[x][y][k], k^(1<<j), dp[i][j][k^(1<<j)], k^1, dp[i][j][k^1]);
				}
			}
		}
	//printf("%d %lld\n", cnt[2][2], fr[1]);
	printf("%lld\n", dp[n][m][(1<<(m+1))-1]);
}
