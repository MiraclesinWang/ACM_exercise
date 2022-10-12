#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 2e5 +5;

template<typename T> class fenwick{
    #define lowbit(x) x&(-x)
    public:
        vector <T> v, a;
        int n;
        fenwick() {}
        fenwick(int _n):n(_n) {v.resize(n+1);a.resize(n+1);}
        void update(int d, T val){
            // cout << "start: " << d << ' ' << val << '\n';
            // cout << a.end() - a.begin();
            a[d] = val;
            for(; d<= n; d+=lowbit(d)){
                v[d] =val;
                // cout << "UPD: " << d << ' ' <<  v[d] << ' ' << val << '\n';
                for(int i = 1; i < lowbit(d); i <<= 1)
                    v[d] = max(v[d], v[d-i]);
                    // cout << "UPD: " << i << ' ' <<  v[d] << ' ' << val << '\n';
            }
        }
        T query(int l, int r){
            T res = -1;
            while(r >= l){
                res = max(res, a[r]);
                r--;
                for(; r-lowbit(r) >= l; r-=lowbit(r))
                    res = max(res, v[r]);
            }
            return res;
        }
};

int main()
{
    // ios::sync_with_stdio(false);
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
        vector <fenwick<LL> > T(dv.end()-dv.begin());
        //sm[i][j]: n和k的最大公因数为i且起点为j的和
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, int(dv.end() - dv.begin())){
            sm[i].resize(dv[i]);
            T[i] = fenwick<LL>(dv[i]);
            // T[i].n = dv[i]+1;
            // T[i].v.resize(T[i].n);
            // T[i].a.resize(T[i].n);
            cout << "build:" << dv[i] << ' '  << T[i].n << ' ' << T[i].v.end() - T[i].v.begin() << '\n';
            rep(j, 0, dv[i]){
                sm[i][j] = 0;
                for(int k = j; k < n; k+=dv[i]){
                    sm[i][j] += a[k];
                }
                sm[i][j] *= dv[i];
                T[i].update(j+1, sm[i][j]);
                // cout << i << ' ' << j+1 << ' ' << sm[i][j] << '\n';
                mx = max(mx, sm[i][j]);
            }
            // cout << "origin: " << T[i].query(1, dv[i]) << '\n';
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
                T[i].update(p%dv[i]+1, sm[i][p%dv[i]]);
                // cout << p%dv[i]+1 << ' ' << sm[i][p%dv[i]] << '\n';
                mx = max(mx, T[i].query(1, dv[i]));
            }
            a[p] = x;
            cout << mx << '\n';
        }
    }
    return 0;
}