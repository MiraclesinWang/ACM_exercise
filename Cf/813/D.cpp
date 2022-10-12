#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 10;

template <typename t> class lazy_tree{
    public:
        int n;
        vector <t> T, lzy;
        lazy_tree(int _n):n(_n){T.resize(n*16), lzy.resize(n*16);}
        void build(int l, int r, int dex, t* a)
        {
            if(l == r) T[dex] = a[l];
            else{
                int mid=(l+r) >> 1;
                build(l, mid, dex*2, a), build(mid+1, r, dex*2+1, a);
                T[dex] = T[dex*2] + T[dex*2+1];
            }
        }
        void pushdown(int l, int r, int dex)
        {
            int mid = (l+r) >> 1;
            T[dex*2] += (mid-l+1) * lzy[dex];
            T[dex*2+1] += (r-mid) * lzy[dex];
            lzy[dex*2] += lzy[dex], lzy[dex*2+1] += lzy[dex];
            lzy[dex] = 0;
        }
        void update(int l, int r, int dex, int x, int y, t val)
        {
            if(l > y || r < x) return;
            if(l>=x && r<=y){
                lzy[dex] += val;
                T[dex] += (r-l+1) * val;
            }
            else{
                int mid = (l+r) >> 1;
                pushdown(l, r, dex);
                update(l, mid, dex*2, x, y, val), update(mid+1, r, dex*2+1, x, y, val);
                T[dex] = T[dex*2] + T[dex*2+1];
            }
        }
        t query(int l, int r, int dex, int x, int y)
        {
            if(l > y || r < x) return 0;
            if(l>=x && r<=y) return T[dex];
            int mid = (l+r) >> 1;
            pushdown(l, r, dex);
            return query(l, mid, dex*2, x, y) + query(mid+1, r, dex*2+1, x, y);
        }
        void BD(t* a) {build(1, n, 1, a);}
        void UP(int l, int r, t v) {update(1, n, 1, l, r, v);}
        t QR(int l, int r) {return query(1, n, 1, l, r);}
};
lazy_tree <LL> T();

LL a[maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    
    rep(i, 1, n+1) cin >> a[i];
    T.BD(a);
    while(m--){
        int l, r, ty, k;
        cin >> ty >> l >> r;
        if(ty == 1){
            cin >> k;
            T.UP(l, r, k);
        }
        else cout << T.QR(l, r) << '\n';
    }
}