#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll out[12][12], dp[15][2048];

void update(int dex, int s, int lft, ll val, int k)
{
	if(lft == -1) {dp[dex][k] += val;return;}
	if((s & (1<<lft))) update(dex, s, lft-1, val, k);
	else{
		if(lft && !(s&(1<<(lft-1)))) update(dex, s, lft-2, val, k);
		update(dex, s, lft-1, val, k^(1<<lft));
	}
}
ll DP(int h, int w)
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int s = (1<<h);
	for(int i = 0; i < w; i++)
		for(int k = 0; k < s; k++)
			if(dp[i][k]) update(i+1, k, h-1, dp[i][k], 0);
	/*for(int i = 1; i <= w; i++){
		for(int k = 0; k < s; k++)
			printf("%d ", dp[i][k]);
		printf("\n");		
	}*/
	return dp[w][0];
}
void init()
{
	for(int i = 1; i < 12; i++){
		for(int j = 1; j < 12; j++){
			if((i*j)%2) out[i][j] = 0;
			else out[i][j] = DP(i, j);
		}		
	}
}

int main()
{
	init();
	int h, w;
	while(scanf("%d%d", &h, &w), h&&w)
		printf("%lld\n", out[h][w]);
}
