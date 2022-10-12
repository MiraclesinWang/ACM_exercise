#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int m, n;
int dp[250][25][1000], pre[250][25][1000], p[250], v[250];
const int BASE = 410;
#define INF 0x3f3f3f3f
#define rep(x, y) for(int i = x; i < y; i++)
stack <int> out;

int main()
{
	int kase = 0;
	while(scanf("%d%d", &n, &m), m||n){
		printf("Jury #%d\n", ++kase);
		memset(dp, -1, sizeof(dp));
		dp[0][0][BASE] = 0;
		rep(0, n){
			int a, b;
			scanf("%d%d", &a, &b);
			p[i] = a, v[i] = b;
			for(int j = 0; j <= m; j++){
				for(int k = 1; k < BASE*2; k++){
					if(dp[i][j][k] < 0) continue;
					if(dp[i+1][j+1][k+a-b] < dp[i][j][k]+a+b)
						dp[i+1][j+1][k+a-b] = dp[i][j][k]+a+b,
						//printf("%d %d %d\n", i+1, j+1, k+a-b-BASE),
						pre[i+1][j+1][k+a-b] = 1;
					if(dp[i+1][j][k] < dp[i][j][k])
						dp[i+1][j][k] = dp[i][j][k],
						//printf("%d %d %d %d\n", i+1, j, k-BASE, dp[i][j][k]),
						pre[i+1][j][k] = 0;
				}				
			}
		}
		int s, x = n, y = m;
		rep(0, 401){
			//printf("%d\n", dp[n][m][BASE+i]);
			if(dp[n][m][BASE+i]>=0 && dp[n][m][BASE-i]>=0){
				if(dp[n][m][BASE+i] > dp[n][m][BASE-i]) {s = BASE+i; break;}
				else {s = BASE-i; break;}
			}
			if(dp[n][m][BASE+i] >= 0) {s = BASE+i; break;}
			if(dp[n][m][BASE-i] >= 0) {s = BASE-i; break;}
		}
		//printf("%d %d\n", s-BASE, dp[n][m][s]);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", (s+dp[n][m][s]-BASE)/2, (dp[n][m][s]-s+BASE)/2);
		while(x){
			if(pre[x][y][s]) out.push(x), y--, s -= p[x-1]-v[x-1];
			x--;
		}
		while(!out.empty()) printf(" %d", out.top()), out.pop();
		printf("\n");
	}
 } 
