#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
int dp[1005], t[505], tt[1005], t_all[1005], cnt[1005];

int main()
{
    memset(cnt, 0, sizeof(cnt));
    int n, m, res = 2e9, BOUND = 0;
    cin >> n >> m;
    tt[0] = 0, t_all[0] = -2e9, cnt[0] = 0;
    rep(i, 1, n+1) cin >> t[i], dp[i] = dp[i+n] = 2e9+10, t_all[i] = t[i], t_all[n+i] = t[i]+m;
    sort(t_all+1, t_all+2*n+1);
    int p = unique(t_all+1, t_all+1+2*n) - t_all - 1;

    rep(i, 1, n+1){
        int dex = lower_bound(t_all+1, t_all+1+p, t[i]) - t_all;
        cnt[dex]++;
        BOUND = max(BOUND, dex);
    }
    rep(i, 1, p+1) tt[i] = tt[i-1] + cnt[i] * t_all[i], cnt[i] += cnt[i-1];

    dp[0] = 0;
    rep(i, 1, p+1){
        rep(j, 0, i){
            if(t_all[i] - t_all[j] < m) break;
            dp[i] = min(dp[i], dp[j]+(cnt[i] - cnt[j])*t_all[i] - (tt[i] - tt[j]));
            if(i >= BOUND) res = min(res, dp[i]);
        }
    }
    cout << res;
}