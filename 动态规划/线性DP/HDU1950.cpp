#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 4e4 + 10;
int p[maxn], dp[maxn], n;

int bin_find(int dex)
{
	int l = 1, r = n;
	while(l != r){
		int mid = (l+r+1) >> 1;
		if(!dp[mid] || dp[mid] >= dex) r = mid-1;
		else l = mid;
	}
	return l;
} 

void solve()
{
	scanf("%d", &n);
	int res = n?1:0, dex;
	rep(1, n+1) scanf("%d", &p[i]);
	memset(dp, 0, sizeof(dp));
	dp[1] = p[1];
	rep(2, n+1){
		if(p[i] <= dp[1]) dp[1] = p[i];
		else dex = bin_find(p[i]), dp[dex+1] = p[i], res = max(res, dex+1);
	}
	printf("%d\n", res);
}

int main()
{
	int kase;
	scanf("%d", &kase);
	rep(0, kase) solve();
}
