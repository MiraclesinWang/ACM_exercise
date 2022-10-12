#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
int dp[9][10][5130];

void init()
{
	memset(dp, 0, sizeof(dp));
	rep(0, 10) dp[0][i][i] = 1;
	rep(1, 9){
		for(int j = 0; j < 10; j++){
			int val = j*(1<<i);
			for(int k = val; k < 4600; k++)
				for(int p = 0; p < 10; p++)
					 dp[i][j][k] += dp[i-1][p][k-val];				
		}
	}
	rep(0, 9)
		for(int j = 0; j < 10; j++)
			for(int k = 1; k < 4600; k++)
				dp[i][j][k] += dp[i][j][k-1];
}

int query(int a, int b)
{
	int num[12];
	int val = 0, tmp = 1, res = 0;
	while(a){
		val += (a%10) * tmp;
		tmp <<= 1, a/=10;
	}
	rep(0, 9) num[i] = b%10, b/=10;
	for(int i = 8; ~i; i--){
		for(int j = 0; j < num[i]; j++) if(val >= 0) res += dp[i][j][val];
		val -= num[i] * (1<<i);
	}
	int v = 0;tmp = 1;
	while(b){
		v += (b%10) * tmp;
		tmp <<= 1, b /= 10;
	}
	if(v <= val) res++;
	return res;
}

int main()
{
	init();
	int kase, a, b;
	scanf("%d", &kase);
	rep(1, kase+1) 
		scanf("%d%d", &a, &b),
		printf("Case #%d: %d\n", i, query(a, b));
}
