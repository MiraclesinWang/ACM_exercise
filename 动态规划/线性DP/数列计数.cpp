#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
int a[305], b[305];
#define rep(i, x, y) for(int i =x; i < y; i++)
ll dp[305][10000+5];
int n;

ll solve()
{
    rep(i, 1, n+1) scanf("%d", &a[i]);
    rep(i, 1, n+1){
        scanf("%d", &b[i]);
        if(a[i] > b[i]) return 0;
    }
    memset(dp, 0, sizeof(dp));
    rep(i, a[1], b[1]+1) dp[1][i] = dp[1][i-1] + 1;
    rep(i, 2, n+1){
        rep(j, 2, 10001){
            if(j < a[i]) continue;
            if(j > b[i]) break;
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
        }
    }
    return dp[n][10000];
}

int main()
{
    while(scanf("%d", &n), n){
        printf("%lld\n", solve());
    }
}
