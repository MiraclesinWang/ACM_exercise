#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define DEBUG(a) cout << #a << ": " << a << '\n'
typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 25;
LL f[maxn], inv[maxn];

LL pow(LL a, LL b)
{
    LL res = 1;
    while(b){
        if(b&1) res = (res*a) %mod;
        b>>=1;
        a = (a*a)%mod;
    }
    return res;
}

LL C(LL a, LL b)
{
    if(a < 0 || b < 0 || a > b) return 0;
    LL res = 1;
    if(a==0 || b==0) return 1;
    b %= mod;
    for(LL c = 0; c < a; c++) res = res*(b-c) % mod;
    for(int i = 1; i <= a; i++) res = res*inv[i] % mod;
    return res;
}

int main()
{
    LL s, res = 0;
    int n;
    cin >> n >> s;
    rep(i, 0, n) cin >> f[i];
    rep(i, 1, n+1) inv[i]= pow(LL(i), mod-2);

    rep(i, 0, 1<<n){
        LL b = n+s-1;
        int cnt = 0;
        rep(j, 0, n){
            if((1<<j) & i) b -= f[j]+1, cnt++;
        }
        LL ans = C(n-1, b);

        if(cnt%2) res = (res-ans+mod)%mod;
        else res = (res+ans) % mod;
    }
    cout << (res+mod)%mod;
}