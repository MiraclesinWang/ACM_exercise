#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;
const int maxn = 5e4 + 10;
const int rsrv = 40;
int c[maxn], c_all[maxn];
LL cnt[50][maxn], pc[50][50];

LL gcd(LL a, LL b)
{
    if(a > b) swap(a, b);
    if(!a) return b;
    LL d;
    while(d=b%a){
        b = a, a = d;
    }
    return a;
}

void prepro(int b, int bl, int t)
{
    memset(cnt[0], 0, sizeof(cnt[0]));
    memset(pc, 0, sizeof(pc));
    memset(cnt[rsrv], 0, sizeof(cnt[rsrv]));

    rep(i, 1, b){
        memcpy(cnt[i], cnt[i-1], sizeof(cnt[i]));
        rep(j, i*bl, (i+1)*bl) cnt[i][c[j]]++;
    }
    rep(i, 1, b){
        rep(j, i, b){
            rep(k, 0, t){
                if(cnt[j][k]-cnt[i-1][k] >= 2){
                    pc[i][j] += (cnt[j][k]-cnt[i-1][k]) * (cnt[j][k]-cnt[i-1][k]-1) / 2;
                }
            }
        }
    }
}

LL query(int l, int r, int dex, int pre, int val)
{
    LL res = 0;
    rep(i, l, r+1){
        cnt[dex][c[i]] += val;
        if(cnt[dex][c[i]] - cnt[pre][c[i]] >= 2){
            res += cnt[dex][c[i]] - cnt[pre][c[i]]-1;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) cin >> c[i], c_all[i] = c[i];
    sort(c_all, c_all +n);
    int t = unique(c_all, c_all +n) - c_all;
    rep(i, 0, n) c[i] = lower_bound(c_all, c_all+t, c[i]) - c_all;

    int b = pow(n, 1.0/3.0), bl = n/b;
    prepro(b, bl, t);

    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ld = l/bl, rd = r/bl;
        LL res;
        if(rd-ld < 2){
            res = query(l, r, rsrv, 0, 1);
            query(l, r, rsrv, 0, -1);
        }
        else{
            res = pc[ld+1][rd-1];
            res += query(l, bl*(ld+1)-1, rd-1, ld, 1);
            res += query(bl*rd, r, rd-1, ld, 1);
            query(l, bl*(ld+1)-1, rd-1, ld, -1);
            query(bl*rd, r, rd-1, ld, -1);
        }
        LL g = gcd(res, (LL)(r-l)*(LL)(r-l+1)/2);
        cout << res/g << '/' << (r-l)*(r-l+1)/2/g;
        if(m) cout << '\n';
    }
}