#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
ll dp[maxn][3];
ll a[maxn], b[maxn];

int main()
{
	int n;
	ll ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	dp[1][0] = 0, dp[1][1] = a[1], dp[1][2] = b[1];
	ans = max(a[1], b[1]);
	for(int i = 2; i <= n; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][0] = max(dp[i][0], dp[i-1][2]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + b[i];
	}
	for(int i = 2; i <= n; i++){
		ans = max(ans, dp[i][1]);
		ans = max(ans, dp[i][2]);
	}	
	printf("%lld\n", ans);
}
