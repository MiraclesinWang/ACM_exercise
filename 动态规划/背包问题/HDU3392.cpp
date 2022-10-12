#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int n, m;
double dp[maxn][105], b[maxn], g[maxn];
#define rep(i, x, y) for(int i = x; i < y; i++)

void init()
{
	rep(i, 0, maxn) rep(j, 0, 105) dp[i][j] = 1e18;
	dp[0][0] = 0;
}

int main()
{
	while(scanf("%d%d", &n, &m), n&&m){
		rep(i, 1, n+1) scanf("%lf", &b[i]);
		rep(i, 1, m+1) scanf("%lf", &g[i]);
		if(n<m) swap(n, m), swap(b, g);  // n > m is certain
		sort(b+1, b+1+n);
		sort(g+1, g+1+m, greater<double>());
		init();
	}
}
