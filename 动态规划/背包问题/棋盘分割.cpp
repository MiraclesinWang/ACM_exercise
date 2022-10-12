#include <bits/stdc++.h>
using namespace std;

int dp[10][10][10][10][16],  kp[10][10][10][10], kkp[10][10];
#define INF 0x3f3f3f3f

int main()
{
	memset(kkp, 0, sizeof(kkp));
	int n, tmp;
	scanf("%d", &n);
	for(int i = 1; i < 9; i++)
		for(int j = 1; j < 9; j++)
			scanf("%d", &tmp), dp[i][j][i][j][1] = tmp*tmp, kp[i][j][i][j] = tmp;		
	for(int i = 1; i < 9; i++)
		for(int j = 1; j < 9; j++)
			kkp[i][j] = kkp[i][j-1] + kp[i][j][i][j] + kkp[i-1][j]-kkp[i-1][j-1];
	for(int x1 = 1; x1 < 9; x1++)
		for(int y1 = 1; y1 < 9; y1++)
			for(int x2 = x1; x2 < 9; x2++)
				for(int y2 = y1; y2 < 9; y2++)
					kp[x1][y1][x2][y2] = kkp[x2][y2]+kkp[x1-1][y1-1]-kkp[x2][y1-1]-kkp[x1-1][y2],
					dp[x1][y1][x2][y2][1] = kp[x1][y1][x2][y2]*kp[x1][y1][x2][y2];
	for(int k = 2; k <= n; k++){
		for(int x1 = 1; x1 < 9; x1++){
			for(int y1 = 1; y1 < 9; y1++){
				for(int x2 = x1; x2 < 9; x2++){
					for(int y2 = y1; y2 < 9; y2++){
						dp[x1][y1][x2][y2][k] = INF;
						if((x2-x1+1)*(y2-y1+1) < k) continue;
						for(int m = 1; m < k; m++){
							for(int t = x1; t < x2; t++){
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][t][y2][1]+dp[t+1][y1][x2][y2][k-1]);
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][t][y2][k-1]+dp[t+1][y1][x2][y2][1]);								
							}
							for(int t = y1; t < y2; t++){
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][x2][t][1]+dp[x1][t+1][x2][y2][k-1]);
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][x2][t][k-1]+dp[x1][t+1][x2][y2][1]);								
							}

							/*for(int t = x1; t < x2; t++)
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][t][y2][m]+dp[t+1][y1][x2][y2][k-m]);
							for(int t = y1; t < y2; t++)
								dp[x1][y1][x2][y2][k] = min(dp[x1][y1][x2][y2][k], dp[x1][y1][x2][t][m]+dp[x1][t+1][x2][y2][k-m]);	*/						
						}
						//printf("%d %d %d %d %d %lld\n", x1, y1, x2, y2, k, dp[x1][y1][x2][y2][k]);
					}
				}
			}
		}
	}
	double ss = kkp[8][8], nn = n, p = dp[1][1][8][8][n];
	printf("%.3f\n", sqrt(p/nn - ss*ss/nn/nn));
}
//dp[i1][j1][i2][j2][i]=min(dp[i1][j1][i2][j2][i], min(dp[i1][j1][i2][k][i-1]+dp[i1][k+1][i2][j2][0], dp[i1][j1][i2][k][0]+dp[i1][k+1][i2][j2][i-1]));
