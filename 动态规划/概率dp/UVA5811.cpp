#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i< y; i++)
double dp[20][20][20][20][25];
int a, b, c, d;

void init()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(max(a-13, 0) + max(b-13, 0) + max(c-13, 0) + max(d-13, 0) > 2) {dp[0][0][0][0][0] = -1.0;return;}
	memset(dp, 0.0, sizeof(dp));
	//printf("%f %f\n", dp[a][b][c][d][2], dp[a+1][b+1][c+1][d+1][0]);
	for(int i = 13; ~i; i--)
		for(int j = 13; ~j; j--)
			for(int k = 13; ~k; k--)
				for(int p = 13; ~p; p--)
					for(int m = 25; ~m; m--){
						if(m > 4 && !(m%5)) continue;
						int ii = i, jj = j, kk = k, pp = p;
						if(m%5 == 1) ii++;
						else if(m%5 == 2) jj++;
						else if(m%5 == 3) kk++;
						else if(m%5 == 4) pp++;
						if(m/5 == 1) ii++;
						else if(m/5 == 2) jj++;
						else if(m/5 == 3) kk++;
						else if(m/5 == 4) pp++;
						
						if(ii >= a && jj >= b && kk >= c && pp >= d) continue;
						double tot = double(54-i-j-k-p);
						if(m) tot -= 1.0;
						if(m > 4) tot -= 1.0;
						if(abs(tot) < 1e-5) continue; 
						
						dp[i][j][k][p][m] = dp[i+1][j][k][p][m] * double(13-i)/ tot+
										dp[i][j+1][k][p][m] * double(13-j) / tot + 
										dp[i][j][k+1][p][m] * double(13-k) / tot +
										dp[i][j][k][p+1][m] * double(13-p) / tot + 1.0;
						
						double tmp = 1e9;
						if(!m){
							for(int s = 1; s < 5; s++)
								if(dp[i][j][k][p][s] < tmp)
									tmp = dp[i][j][k][p][s];
							tmp *= 2.0 / tot;
						}
						else if(m < 5){
							for(int s = 1; s < 5; s++)
								if(dp[i][j][k][p][s*5+m] < tmp)
								 	tmp = dp[i][j][k][p][s*5+m];
							tmp /= tot;
						}
						if(m < 5) dp[i][j][k][p][m] += tmp;
						
						//printf("%d %d %d %d %d %f\n", i, j, k, p, m, dp[i][j][k][p][m]);
						 
					}
}

int main()
{
	int kase;
	scanf("%d", &kase);
	rep(1, kase+1){
		init();
		printf("Case %d: %.3f\n", i, dp[0][0][0][0][0]);
	}
}
