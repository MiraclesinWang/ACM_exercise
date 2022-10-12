#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
int dp[10][12], num[10];
const int BOUND = 2e9-2;

void init()
{
    memset(dp, 0, sizeof(dp));
    rep(i, 0, 10) dp[0][i] = i+1;
    rep(i, 1, 10){
        rep(j, 0, 10){
            int l = max(j-1, 0), r = min(j+1, 9);
            if(l) dp[i][j] = dp[i-1][9] - (dp[i-1][r] - dp[i-1][l-1]); 
            else dp[i][j] = dp[i-1][9] - dp[i-1][r];

            if(j) dp[i][j] += dp[i][j-1];
        }
    }
}

int query(int n)
{
    int frs;
    for(int d = 0; n; d++, n/=10) num[d] = n%10, frs = d;
    int res = dp[frs][num[frs] -1] - dp[frs][0], pre=num[frs];
    for(int i = frs-1; ~i; i--){
        res += dp[i][9] - dp[i][0];

        if(pre < 0) continue;
        if(num[i]) res += dp[i][num[i]-1];

        int l = max(0, pre-1), r = min(num[i]-1, pre+1);
        if(l <= r){
            if(l) res -= dp[i][r] - dp[i][l-1];
            else if(r >= 0) res -= dp[i][r];
        }

        if(abs(num[i]-num[i+1]) < 2) pre = -1;
        else pre = num[i];
    }
    return res;
}

int main()
{
    init();
    int l, r;
    cin >> l >> r;
    l = min(BOUND, l), r = min(BOUND, r);
    cout << query(r+1) - query(l);
}