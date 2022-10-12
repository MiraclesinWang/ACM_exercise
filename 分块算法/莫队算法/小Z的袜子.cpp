#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 5e4 + 10;
const int maxb = 250;

typedef long long LL;
#define rep(i, x, y) for(int i =x; i < y; i++)

struct question{
    int l, r, dex;
    LL res;
    bool operator < (const question &oth) {return l < oth.l;}
}q[maxn];
int c[maxn], c_all[maxn], cnt[maxn];
LL res[maxn];

bool cmp_r(question &a, question &b) {return a.r < b.r;}
bool cmp_d(question &a, question &b) {return a.dex < b.dex;}

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

void prepro(int b, int bl, int t, int m)
{
    rep(i, 0, b+1){
        int r = i==b?m:(i+1)*bl, l = i*bl;
        sort(q+l, q+r, cmp_r);
    }
}

void MD(int l, int r)
{
    rep(i, l+1, r){
        q[i].res = q[i-1].res;
        //cout << i << ' ' << q[i].res << '\n';
        if(q[i].l > q[i-1].l){
            rep(j, q[i-1].l, q[i].l){
                if(cnt[c[j]] > 1) q[i].res -= cnt[c[j]]-1;
                cnt[c[j]]--;
            }
        }
        else{
            rep(j, q[i].l, q[i-1].l){
                cnt[c[j]]++;
                //cout << "left add: " << j <<  ' ' << c[j] <<' ' << cnt[c[j]] << '\n';
                if(cnt[c[j]] > 1) q[i].res += cnt[c[j]]-1;
            }
        }
        rep(j, q[i-1].r+1, q[i].r+1){
            cnt[c[j]]++;
            //cout << "right add: " << j << ' ' << c[j] << ' ' << cnt[c[j]] << '\n';
            if(cnt[c[j]] > 1) q[i].res += cnt[c[j]]-1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) cin >> c[i], c_all[i] = c[i];
    sort(c_all, c_all+n);
    int t = unique(c_all, c_all +n) - c_all;
    rep(i, 0, m) cin >> q[i].l >> q[i].r, q[i].dex = i, q[i].l--, q[i].r--;
    sort(q, q+m);

    int b = sqrt(n), bl = m/b;
    prepro(b, bl, t, m);
    //rep(i, 0, m) cout << q[i].dex << ' ' << q[i].l << ' ' << q[i].r << '\n';

    rep(i, 0, b+1){
        memset(cnt, 0, sizeof(cnt));
        int l = i*bl, r = i==b?n:(i+1)*bl;
        q[l].res = 0;
        //cout << q[l].l << ' ' << q[l].r << '\n';
        rep(j, q[l].l, q[l].r+1){
            cnt[c[j]]++;
            //cout << j << ' ' << c[j] << ' ' <<  cnt[c[j]] << '\n';
            if(cnt[c[j]] > 1) q[l].res += cnt[c[j]]-1;
        }
        MD(l, r);
    }
    sort(q, q+m, cmp_d);
    rep(i, 0, m){
        LL g = gcd(q[i].res, (LL)(q[i].r-q[i].l)*(LL)(q[i].r-q[i].l+1)/2);
        cout << q[i].res / g << '/' << (LL)(q[i].r-q[i].l)*(LL)(q[i].r-q[i].l+1)/2/g;
        if(i< m-1) cout << '\n';
    }
}
