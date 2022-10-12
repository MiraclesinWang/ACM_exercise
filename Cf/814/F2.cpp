#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 2e5 +5;

bool isPrime[maxn];
int prim[maxn];
int m;

void get_prime()
{
    memset(isPrime, false, sizeof(isPrime));
    m = 0;
    rep(i, 2, maxn){
        if(!isPrime[i]) prim[++m] = i;
        rep(j, 1, m+1){
            if(LL(prim[j])*LL(i) >= LL(maxn)) break;
            isPrime[prim[j]*i] = true;
            if(i%prim[j] == 0) break;
        }
    }
}

template <typename t> class seg_tree
{
    public:
        vector <t> seg;
        int n;
        seg_tree(){}
        seg_tree(int _n):n(_n){seg.resize(n*16);}
        void update(int l, int r, int dex, int d, t v){
            if(l > d || r < d) return;
            if(l == r) seg[dex] = v;
            else{
                int mid = (l+r) >> 1;
                update(l, mid, dex*2, d, v), update(mid+1, r, dex*2+1, d, v);
                seg[dex] = max(seg[dex*2], seg[dex*2+1]);
            }
        }
        t query(int l, int r, int dex, int x, int y){
            if(l > y || r < x) return -1;
            if(l>=x && r<=y) return seg[dex];
            int mid = (l+r) >> 1;
            return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
        }
        void UP(int d, t v) {update(1, n, 1, d, v);};
        t QR(int x, int y) {return query(1, n, 1, x, y);}
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int kase;
    cin >> kase;
    get_prime();
    while(kase--){
        int n, q;
        LL mx = -1;
        cin >> n >> q;
        vector <int> dv;
        dv.push_back(1);
        rep(i, 2, n){
            if(n%i == 0) dv.push_back(i);
        }
        vector <vector <LL>> sm(dv.size());
        vector <LL> a(n);
        vector <seg_tree<LL> > T(dv.size());
        //sm[i][j]: n和k的最大公因数为i且起点为j的和
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, dv.size()){
            sm[i].resize(dv[i]);
            T[i] = seg_tree<LL>(dv[i]);
            rep(j, 0, dv[i]){
                sm[i][j] = 0;
                for(int k = j; k < n; k+=dv[i]){
                    sm[i][j] += a[k];
                }
                sm[i][j] *= LL(dv[i]);
                T[i].UP(j+1, sm[i][j]);
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
                T[i].UP(p%dv[i]+1, sm[i][p%dv[i]]);
                mx = max(mx, T[i].QR(1, dv[i]));
            }
            a[p] = x;
            cout << mx << '\n';
        }
    }
    return 0;
}