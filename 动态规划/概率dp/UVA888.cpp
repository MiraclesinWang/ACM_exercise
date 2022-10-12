#include <bits/stdc++.h>
using namespace std;


#define rep(x, y) for(int i = x; i< y; i++)
double dp[55][55][55][55][5];
int pos[5];
const double p = 1.0 / 6.0;

double init()
{
	double res = 0.0;
	int m, n, now;
	memset(dp, 0.0, sizeof(dp));
	memset(pos, 0, sizeof(pos));
	scanf("%d%d", &m, &n);
	for(int j = 0; j < n; j++) scanf("%d", &pos[j]);
	scanf("%d", &now);
	
	if(n == 1) return 1.0;
	m++;
	dp[pos[0]][pos[1]][pos[2]][pos[3]][now-1] = 1.0;
	for(int i = pos[0]; i <= m; i++)
		for(int j = pos[1]; j <= m; j++){
			if(n > 2){
				for(int k = pos[2]; k <= m; k++){
					if(n > 3){
						for(int t = pos[3]; t <= m; t++){
							if(max(max(max(i, j), k), t) == m){
								if(i == m)
									for(int s = 0; s < 4; s++)
										res += dp[i][j][k][t][s];
								continue;
							}
							for(int s = 1; s < 7; s++){
								int tmp = i+s;
								while(tmp == j || tmp == k || tmp == t) tmp++;
								tmp = min(tmp, m);
								dp[tmp][j][k][t][1] += dp[i][j][k][t][0] * p;
							}
							for(int s = 1; s < 7; s++){
								int tmp = j+s;
								while(tmp == i || tmp == k || tmp == t) tmp++;
								tmp = min(tmp, m);
								dp[i][tmp][k][t][2] += dp[i][j][k][t][1] * p;
							}
							for(int s = 1; s < 7; s++){
								int tmp = k+s;
								while(tmp == j || tmp == i || tmp == t) tmp++;
								tmp = min(tmp, m);
								dp[i][j][tmp][t][3] += dp[i][j][k][t][2] * p;
							}
							for(int s = 1; s < 7; s++){
								int tmp = t+s;
								while(tmp == j || tmp == k || tmp == i) tmp++;
								tmp = min(tmp, m);
								dp[i][j][k][tmp][0] += dp[i][j][k][t][3] * p;
							}
						}
							
					}
					else{     //有三个人 
						if(max(max(i, j), k) == m){
							if(i == m)
								for(int t = 0; t < 3; t++)
									res += dp[i][j][k][0][t];
							continue;
						}
						for(int s = 1; s < 7; s++){
							int tmp = i+s;
							while(tmp == j || tmp == k) tmp++;
							tmp = min(tmp, m);
							dp[tmp][j][k][0][1] += dp[i][j][k][0][0] * p;
						}
						for(int s = 1; s < 7; s++){
							int tmp = j+s;
							while(tmp == i || tmp == k) tmp++;
							tmp = min(tmp, m);
							dp[i][tmp][k][0][2] += dp[i][j][k][0][1] * p;
						}
						for(int s = 1; s < 7; s++){
							int tmp = k+s;
							while(tmp == i || tmp == j) tmp++;
							tmp = min(tmp, m);
							dp[i][j][tmp][0][0] += dp[i][j][k][0][2] * p;
						}
					}
				}
			}
			else{   //只有两个人 
				if(max(i, j) == m){
					if(i == m) 
						for(int t = 0; t < 2; t++)
							res += dp[i][j][0][0][t];
					continue;
				}
				for(int s = 1; s < 7; s++){
					if(i+s == j) dp[min(i+s+1, m)][j][0][0][1] += dp[i][j][0][0][0]*p;
					else dp[min(i+s, m)][j][0][0][1] += dp[i][j][0][0][0] * p;
				}	
				for(int s = 1; s < 7; s++){
					if(j+s == i) dp[i][min(j+s+1, m)][0][0][0] += dp[i][j][0][0][1]*p;
					else dp[i][min(j+s, m)][0][0][0] += dp[i][j][0][0][1] * p;
				}
			}
		}
	return res;
}

int main()
{
	int kase;
	scanf("%d", &kase);
	rep(1, kase+1)
		printf("Game %d:the probability that player 1 wins = %.3f\n", i, init());	
}
