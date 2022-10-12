#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 32*3e5 + 10;

int T[maxn][2], ex[maxn][2], cnt;

void solve()
{
    int n;
    cin >> n;
    vector <int> a(n), b(n), res(n, 0);
    MEM(T, 0);
    MEM(ex, -1);
    cnt = 0;
    rep(i, 0, n){
        cin >> a[i], b[i] = (i^a[i]);
        for(int j = 5, d = 0; ~j; j--){
            int v = (b[i]>>j)&1, x = (i>>j)&1, y = (a[i]>>j)&1;

            // cout << i << ' ' << d << ' ' << j << ' ' << v << ' ' << x << '\n';
            // cout << T[d][y^1] << ' ' << ex[T[d][v^1]][y^1] << '\n';

            if(T[d][v^1] && ~ex[T[d][y^1]][y^1]) 
                res[i] = max(res[i], res[ex[T[d][y^1]][y^1]]+1);
                // cout << "get res: " << i << ' ' << ex[T[d][y^1]][y^1] << ' ' << y << ' ' << res[i] << '\n';

            if(!T[d][v]) T[d][v] = ++cnt;
            d = T[d][v];
            if((~ex[d][x] && res[i] >= res[ex[d][x]]) || ex[d][x]==-1){
                ex[d][x] = i;
            }
            // cout << d << ' ' << x << ' ' << i << '\n';
        }
    }
    // rep(i, 0, n) cout << res[i] << ' ';
    cout << *max_element(res.begin(), res.end())+1 << '\n';
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--) solve();
}