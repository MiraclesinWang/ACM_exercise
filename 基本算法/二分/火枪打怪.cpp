#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 5e5 + 10;
#define rep(i, x, y) for(int i = x; i < y; i++)
LL m[maxn], cnt[maxn];

bool isValid(LL p, int n, LL k)
{
    memset(cnt, 0, sizeof(cnt));
    LL sd = 0, sm =0, sn = 0;
    LL mxd = sqrt(p);
    while(mxd*mxd < p) mxd++;

    for(int i = n-1; ~i; i--){
        LL dmg = sn * p - sd;
        if(m[i] >= dmg){
            LL bl = (m[i] - dmg) / p + 1;
            k -= bl, cnt[i] = bl, sn += cnt[i];
            if(k < 0) return false;
        }

        sd += 2*sm + sn, sm += sn;
        if(i-1+int(mxd) < n){
            int ed = i-1+int(mxd);
            sn -= cnt[ed], sd -= cnt[ed]*mxd*mxd, sm -= mxd*cnt[ed];
        }
    }
    return true;
}

int main()
{
    LL l=1, r=1e11, k;
    int n;
    cin >> n >> k;
    rep(i, 0, n) cin >> m[i];
    while(l < r){
        LL mid = (l+r) >> 1;
        if(isValid(mid, n, k)) r = mid;
        else l = mid+1;
    }
    cout << l;
}