#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 1e5 + 10;
double dp[maxn], cnt[maxn];

void init()
{
	dp[1] = 0.0;
	memset(cnt, 0, sizeof(cnt));
	rep(2, maxn){
		dp[i] += double(cnt[i] + 2), dp[i] /= double(cnt[i]+1);
		int tmp = 2*i;
		while(tmp < maxn){
			dp[tmp] += dp[i], cnt[tmp]++;
			tmp += i;
		}
	}
}

int main()
{
	init();
	int kase, n;
	scanf("%d", &kase);	
	for(int k = 1; k <= kase; k++){
		scanf("%d", &n);
		printf("Case %d: %.8f\n",k, dp[n]);
	}
}
