#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[20][11][2], Ten[20];
#define rep(x, y) for(int i = x; i < y; i++) 

void init()
{
	Ten[0] = 1;
	rep(1, 19) Ten[i] = Ten[i-1] * 10;
	memset(dp, 0, sizeof(dp));
	rep(0, 11) dp[0][i][1] = 0, dp[0][i][0] = 1;
	dp[0][10][0] = 10;
	rep(1, 20){
		for(int j = 0; j < 10; j++){
			dp[i][j][1] = dp[i-1][10][1];
			if(j == 4){
				dp[i][j][1] += dp[i-1][9][0];
				dp[i][j][0] = dp[i-1][10][0] - dp[i-1][9][0];
			}
			else dp[i][j][0] = dp[i-1][10][0];
			for(int k = 0; k < 2; k++)
				dp[i][10][k] += dp[i][j][k];
		}
	}
}

ll query(ll n)
{
	bool flag = false;
	ll res = 0;
	int num[25], ct = 0;
	rep(0, 20) num[i] = n % 10, n /= 10;
	for(int i = 19; ~i; i--){
		for(int j = 0; j < num[i]; j++)
			res += (flag?Ten[i]:dp[i][j][1]);
		if(num[i] == 9 && num[i+1] == 4) flag = true;
	}
	return res + flag;
}

int main()
{
	init();
	int kase;
	ll n;
	scanf("%d", &kase);
	while(kase--){
		scanf("%lld", &n);
		printf("%lld\n", query(n));
	}
} 
