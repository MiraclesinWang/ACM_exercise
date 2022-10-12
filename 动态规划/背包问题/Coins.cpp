#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxm = 1e5 + 10;
bool dp[maxm];
int a[maxn], c[maxn];
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m), n||m){
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		for(int i = 1; i <= n; i++)
			for(int j = m; j; j--)
				for(int k = 1; k <= c[i]; k++){
					if(dp[j] || j - k*a[i] < 0) break;
					dp[j] = dp[j-k*a[i]];
				}
		int res = 0;
		for(int i = 1; i <= m; i++)
			if(dp[i]) res++;
		printf("%d\n", res);
	}
}
