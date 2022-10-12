#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, s[50];
ll dp[50][50];
char c[50];

int main()
{
	ll res = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	scanf("%s", c);
	n = strlen(c);
	int tot = 0;
	for(int i  = 0; i < n; i++){
		if(c[i] == 'x') s[i] = 0;
		else s[i] = 1, tot++;
	}
	if(tot%2) {printf("0\n");return 0;}
	for(int k = 0; k < (1<<(n/2)); k++){
		int cnt = 0;
		for(int i = 0; i < n/2; i++)
			if(k & (1<<i)) cnt++;
		if(cnt != tot/2) continue;
		//printf("-----------------------\n%d\n", k);
		for(int i = 0; i <= n/2; i++){
			for(int j = 0; j <= n/2; j++){
				if(!(i+j)) continue;
				dp[i][j] = 0;
				if(i){
					int tmp = (k & (1<<(i-1)));
					if((tmp && s[i+j-1]) || (!tmp && !s[i+j-1])) dp[i][j] += dp[i-1][j]; 
				}
				if(j){
					int tmp = (k & (1<<(j-1)));
					if((tmp && s[i+j-1]) || (!tmp && !s[i+j-1])) dp[i][j] += dp[i][j-1];
				}
				//printf("%d %d %lld\n", i, j, dp[i][j]);
			}
		}
		res += dp[n/2][n/2];
	}
	printf("%lld\n", res);
}
