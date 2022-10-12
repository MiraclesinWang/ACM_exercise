#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 450 * 51 / 2 + 10;
bool dp[55][maxn];
int w[105];

int main()
{
	int n;
	while(~scanf("%d", &n)){
		int sm = 0, cp;
		memset(dp, false, sizeof(dp));
		rep(i, 1, n+1) scanf("%d", &w[i]), sm += w[i];
		cp = sm, dp[0][0] = true, sm /= 2;
		rep(i, 1, n+1){
			for(int j = (n+1)/2-1; ~j; j--)
				rep(k, 0, sm-w[i]+1){
					dp[j+1][k+w[i]] |= dp[j][k];
				}
		}
		int res = -1;
		for(int i = sm; ~i; i--)
			if(dp[n/2][i]) {res =i; break;}
		if(n%2)
			for(int i = sm; ~i; i--)
				if(dp[n/2+1][i]) {res = max(res, i); break;}
		printf("%d %d\n", res, cp-res);		
	}

}
