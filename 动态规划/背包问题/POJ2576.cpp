#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 450*100 + 500; 
bool dp[maxn][60];
int w[105];

int main()
{
	int n, sm = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]), sm += w[i];
	int m = n >> 1, res = 1e9;
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for(int i = 1; i <= n; i++){
		for(int j = maxn-1; j >= 0; j--){
			for(int k = 0; k <= m; k++){
				if(dp[j][k]) dp[j+w[i]][k+1] = dp[j][k] = true;
			}
		}
	}
	for(int i = 0; i < maxn; i++)
		if(dp[i][m])
			if(abs(2*i-sm) < abs(2*res-sm)) res = i;
	printf("%d %d\n", min(res, sm-res), max(res, sm-res));
}
