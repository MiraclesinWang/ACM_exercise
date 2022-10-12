#include <cstdio>
#include <cstring>
using namespace std;

#define ll long long
ll dp[13][13][(1<<11)];

int main()
{
	int h, w;
	while(scanf("%d%d", &h, &w), h&&w){
		if(h*w%2) {printf("0\n");continue;}
		memset(dp, 0ll, sizeof(dp));
		dp[0][w-1][0] = 1;
		int s = (1<<w);
		for(int i = 1; i <= h; i++){
			for(int k = 0; k < s; k++){
				if(k&1) dp[i][0][k-1] += dp[i-1][w-1][k];
				else{
					dp[i][0][k+1] += dp[i-1][w-1][k];
					if(!(k&2)) dp[i][1][k] += dp[i-1][w-1][k];
				}
			}
			for(int j = 1; j < w; j++){
				for(int k = 0; k < s; k++){
					dp[i][j][k^(1<<j)] += dp[i][j-1][k];
					if(!(k&(1<<j)) && !(k&(1<<(j+1)))) dp[i][j+1][k] += dp[i][j-1][k];
				}
			}
		}
		printf("%lld\n", dp[h][w-1][0]);
	}
}
