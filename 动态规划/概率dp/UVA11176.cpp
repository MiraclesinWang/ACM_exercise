
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 510;
int n;
double p, dp[maxn][maxn], pi[maxn];

int main()
{
	while(scanf("%d%lf", &n, &p) && n){
		pi[0] = 1.0;
		rep(0, maxn)
			for(int j = 0; j < maxn; j++)
				dp[i][j] = 1.0;
		rep(0, n+1) pi[i+1] = pi[i]*p;
		rep(1, n+1){
			for(int j = 1; j < i; j++){
				if(i-1 == j) dp[i][j] = dp[i-1][j] - pi[j+1];
				else dp[i][j] = dp[i-1][j] - dp[i-2-j][j] *(1.0-p) * pi[j+1];
			}
			dp[i][i] = 1.0, dp[i][0] = dp[i-1][0]*(1.0-p);
		}
		double res = 0.0;
		rep(1, n+1)
			res += (dp[n][i]-dp[n][i-1])*double(i);
		printf("%f\n", res);
	}
 }

