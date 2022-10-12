#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define _(x) x << ' ';
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 2e5 + 5;
LL res[maxn], ans[maxn];
bool vis[maxn];
int prime[maxn];
int m = 0;

void init()
{
    memset(vis, false, sizeof(vis));
    m = 0;
    rep(i, 2, maxn){
        if(!vis[i]) prime[++m] = i;
        rep(j, 1, m+1){
            if(LL(prime[j])*LL(i) >= LL(maxn)) break;
            vis[prime[j]*i] = true;
            if(i%prime[j] == 0) break;
        }
    }
    rep(i, 3, maxn){
        if(i%2 == 0) res[i] = ans[i] = 0;
        else{
            res[i] = 1;
            rep(j, 1, m+1){
                LL cnt = 1;
                for(int ni = i; ni%j ==0; ni%=j, cnt++) {}
                res[i] *= cnt;
            }
            res[i] -= 1;
            res[i] *= 2;
            ans[i] = res[i] * (res[i]-1)/2;
        }
    }
    ans[3] = 1, ans[5] = 1, ans[7] = 1, ans[1] = 1, ans[13] = 1;
    ans[9] = 5;
    ans[2] = 0;

    rep(i, 4, maxn) ans[i] += ans[i-1];
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << ans[r] - ans[l-1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    int kase;
    cin >> kase;
    while(kase--) solve();
}