#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 2e5 +5;

void solve()
{
    int n, q;
    LL mx = -1;
    vector <int> dv;
    cin >> n >> q;
    rep(i, 1, n+1)
        if(n%i == 0) dv.push_back(i);
    vector <vector <LL>> sm(dv.end()-dv.begin());
    vector <LL> a(n);
    //sm[i][j]: n和k的最大公因数为i且起点为j的和
    rep(i, 0, n) cin >> a[i];
    cout << "why?\n";
    rep(i, 0, dv.end() - dv.begin()){
        cout << i << ' ' << dv[i] << '\n';
        rep(j, 0, dv[i]){
            sm[i][j] = 0;
            for(int k = j; k < n; k+=dv[i])
                sm[i][j] += a[k];
            mx = max(mx, sm[i][j]);
        }
    }
    cout << mx << '\n';
    while(q--){
        int p, x;
        cin >> p >> x;
        p--;
        rep(i, 0, dv.end() - dv.begin()){
            sm[i][p%dv[i]] += x-a[p];
            mx = max(sm[i][p%dv[i]], mx);
        }
        a[p] = x;
        cout << mx << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        int n, q;
        LL mx = -1;
        vector <int> dv;
        cin >> n >> q;
        rep(i, 1, n)
            if(n%i == 0) dv.push_back(i);
        vector <vector <LL>> sm(dv.end()-dv.begin());
        vector <LL> a(n);
        //sm[i][j]: n和k的最大公因数为i且起点为j的和
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, int(dv.end() - dv.begin())){
            sm[i].resize(dv[i]);
            rep(j, 0, dv[i]){
                sm[i][j] = 0;
                for(int k = j; k < n; k+=dv[i]){
                    sm[i][j] += a[k];
                }
                sm[i][j] *= dv[i];
                mx = max(mx, sm[i][j]);
            }
        }
        cout << mx << '\n';
        while(q--){
            int p, x;
            LL mx = -1;
            cin >> p >> x;
            p--;
            rep(i, 0, dv.end() - dv.begin()){
                sm[i][p%dv[i]] += (x-a[p]) * dv[i];
                // mx = max(sm[i][p%dv[i]], mx);
                mx = max(mx, *max_element(sm[i].begin(), sm[i].end()));
            }
            a[p] = x;
            cout << mx << '\n';
        }
    }
    return 0;
}