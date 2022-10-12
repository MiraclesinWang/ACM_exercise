#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
typedef long long LL;
const int maxn = 1e5 + 10;
const int INF = 2e9;

LL dp[maxn][20][2][3];
int h[maxn], na[maxn], nb[maxn], T[maxn], rT[maxn], h_all[maxn], dis[10];

void update(int d, int val)
{
    for(int i =d; i<maxn; i+=lowbit(i)) T[i] = min(T[i], val);
    for(int i = maxn-d; i<maxn; i+=lowbit(i)) rT[i] = max(rT[i], val);
}
int query(int d, bool mx)
{
    int res = INF;
    if(mx)
        for(d = maxn -d, res=-INF; d; d-=lowbit(d)) res = max(res, T[i]);
    else
        for(; d; d-=lowbit(d)) res = min(res, T[i]);
    return res
}

int init(int n, int x)
{
    rep(i, 0, maxn) T[i] = INF, rT[i] = -INF;
    rep(i, 1, n+1) h_all[i] = h[i];
    sort(h_all+1, h_all+1+n);

    na[n] = nb[n] = nb[n-1] = -1
    na[n-1] = abs(h[n] - h[n-1]);
    update(lower_bound(h_all+1, h_all+1+n, h[n]) - h_all, h[n]);
    update(lower_bound(h_all+1, h_all+1+n, h[n-1]) - h_all, h[n-1]);
    for(int i = n-2; i; i--){
        int h_mn = query(lower_bound(h_all+1, h_all+1+n, h[i]), false),
            h_mx = query(lower_bound(h_all+1, h_all+1+n, h[i]), true),
            h_mn2 = query(h_mn, false), h_mx2 = query(h_mx, true);
        dis[0] = abs(h_mn-h[i]), dis[1] = abs(h_mx-h[i]), 
        dis[2] = abs(h_mn2-h[i]), dis[3] = abs(h_mx2-h[i]);
        sort(dis, dis+4);
        nb[i] = dis[0], na[i] = dis[1];
    }

    rep(i, 1, i<<=1){
        
    }
}

int main()
{
    memset(dp, 0ll, sizeof(dp));
    int n, x;
    rep(i, 1, n+1) cin >> h[i];
    cin >> x;
    init(n, x);
}