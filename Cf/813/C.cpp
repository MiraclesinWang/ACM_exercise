#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define _(x) x << ' ';
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 10;
bool vis[maxn];
int a[maxn], b[maxn], c[maxn];

int solve()
{
    int n;
    cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    memset(vis, 0, sizeof(vis));
    for(int i = n; i; i--){
        if(c[a[i]]) b[i] = c[a[i]];
        c[a[i]] = i;
    }
    if(n == 1) return 0;
    
    int d = n-1;
    while(d && a[d] <= a[d+1]) d--;
    if(d ==0) return 0;
    for(int i = 1; i <= d; i++){
        d = max(d, b[i]);
        vis[a[i]] = true;
    }
    int res = 0;
    rep(i, 1, maxn) res += vis[i];
    return res;
}

int main()
{
    int kase, n;
    cin >> kase;
    while(kase--){
        cout << solve() << '\n';
    }
}