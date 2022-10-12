#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e4 + 10;
LL dp[maxn];

int main()
{
	dp[1] = 0, dp[2] = 1;
	rep(i, 3, 50+1){
		dp[i] = LL(i-1) * dp[i-2] + LL(i-1) * dp[i-1];
	}
	int n, m;
	cin >> n;
	rep(i, 0, n){
		cin >> m;
		cout << dp[m] << "\n";
	}
	return 0;
}


