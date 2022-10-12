#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 5e4 + 10;
int yr[maxn], dr[maxn], T[16*maxn];

void build(int l, int r, int dex)
{
    if(l == r){
        T[dex] = dr[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, dex*2), build(mid+1, r, dex*2 + 1);
    T[dex] = max(T[dex*2], T[dex*2+1]);
}

int query(int l, int r, int dex, int x, int y)
{
    if(l >= x && r <= y) return T[dex];
    if(l > y || r < x) return -2e9;
    int mid = (l+r) >> 1;
    return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
}

string solve(int n)
{
    //Z < X <= Y
    int x, y;
    cin >> y >> x;
    if(y > x) return "false";
    if(x == y) return "true";
    int xd = lower_bound(yr, yr+n, x) - yr, yd = lower_bound(yr, yr+n, y) - yr;
    // if(yr[xd] != x) return "maybe";

    if(yr[yd] == y && yr[xd] == x && dr[xd] > dr[yd]) return "false";
    int l = yd, r = xd-1;
    if(yr[yd] == y) l++;
    if(l > r){
        if(yr[yd] == y && yr[xd] == x && dr[xd] <= dr[yd]){
            if(x-y <= 1) return "true";
            else return "maybe";
        }
        else return "maybe";
    }
    int z = query(0, n-1, 1, l, r);
    if(yr[xd] == x && dr[xd] <= z) return "false";
    if(yr[yd] == y && dr[yd] <= z) return "false";
    if(y-x == yd-xd && yr[xd] == x && yr[yd] == y) return "true";
    else return "maybe";
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    rep(i, 0, n) cin >> yr[i] >> dr[i];
    yr[n] = 2e9;
    build(0, n-1, 1);

    cin >> m;
    while(m--){
        cout << solve(n);
        if(m) cout << '\n';
    }
}
