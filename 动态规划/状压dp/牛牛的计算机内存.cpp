#include <bits/stdc++.h>
using namespace std;

int code[50], dp[2][(1<<20) + 10], k[(1<<20) + 10];
char s[50];
const int INF = 0x3f3f3f3f;

int cost(int pre, int now)
{
	int res = 0;
	for(int i = 0; i < 20; i++)
		if(now & (1<<i) && !(pre & (1<<i))) res++;
	return res*res;
}

int main()
{
	memset(code, 0, sizeof(code));
	memset(dp, INF, sizeof(dp));
	int n, len;
	scanf("%d%d",&n, &len);
	for(int i = 0; i < n; i++){
		scanf("\n%s", s);
		int tmp = 1;
		for(int j = 0; j < len; j++) code[i] += tmp * (s[j] == '1'), tmp <<= 1;
	}
	for(int i = 0; i < (1<<n); i++){
		int tmp = 0;
		for(int j = 0; j < n; j++) 
			if((1<<j) & i) tmp |= code[j];
		k[i] = tmp; 
	}
	dp[0][0] = 0, dp[0][1] = cost(0, k[1]);
	printf("%d\n", cost(0, k[1]));
	int now = 0;
	for(int i = 1; i < n*n; i++){
		int dex = i%n; now ^= 1;
		for(int j = 0; j < (1<<n); j++)
			if(dp[now^1][j] < INF)
				dp[now][j|(1<<dex)] = min(dp[now][j|(1<<dex)], dp[now^1][j] + cost(k[j], code[dex]));
	}
	int out = 0;
	for(int i = 0; i < n; i++) out |= code[i];
	printf("%d\n", dp[now][out]);
}
