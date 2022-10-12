#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 2e5 + 10;

template <typename t> class seg_tree
{
    public:
        vector <t> seg;
        int n;
        bool mx;

        seg_tree(int _n):n(_n){seg.resize(n*16);}
        void update(int l, int r, int dex, int d, t v){
            if(l > d || r < d) return;
            if(l == r) seg[dex] = v;
            else{
                int mid = (l+r) >> 1;
                update(l, mid, dex*2, d, v), update(mid+1, r, dex*2+1, d, v);
                if(mx) seg[dex] = max(seg[dex*2], seg[dex*2+1]);
                else seg[dex] = min(seg[dex*2], seg[dex*2+1]);
            }
        }
        t query(int l, int r, int dex, int x, int y){
            if(l > y || r < x){
                if(mx) return -1;
                else return 1e9;
            }
            if(l>=x && r<=y) return seg[dex];
            int mid = (l+r) >> 1;
            if(mx) return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
            else return min(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
        }
        void UP(int d, t v) {update(1, n, 1, d, v);};
        t QR(int x, int y) {return query(1, n, 1, x, y);}
};

int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase, n;
    cin >> kase;
    while(kase--){
        cin >> n;
        seg_tree<int> mx(2*n), mn(2*n);
        mx.mx = true, mn.mx = false;
        rep(i, 1, n+1){
            cin >> a[i], a[i+n] = a[i];
            mx.UP(i, a[i]), mx.UP(i+n, a[i]);
            mn.UP(i, a[i]), mn.UP(i+n, a[i]);
        }
        int mnv = *min_element(a+1, a+1+n), l, r, res = 0;
        int mxv = *max_element(a+1, a+1+n);
        rep(i, 1, n+1){
            if(a[i] == mnv){
                l = r= i;
                break;
            }
        }
        for(int i = 0; i < n; r++, i++){
            if(a[r] == mnv) l = r;
            res = max(res, mx.QR(l, r)+mx.QR(r+1, l+n-1) - mn.QR(l, r) - mn.QR(r+1, l+n-1));
        }
        for(int i = 2*n; i; i--){
            if(a[i] == mnv){
                l = r = i;
                break;
            }
        }
        for(int i = 0; i < n; l--, i++){
            if(a[l] == mnv) r = l;
            res = max(res, mx.QR(l, r)+mx.QR(r+1, l+n-1) - mn.QR(l, r) - mn.QR(r+1, l+n-1));
        }


        rep(i, 1, n+1){
            if(a[i] == mxv){
                l = r= i;
                break;
            }
        }
        for(int i = 0; i < n; r++, i++){
            if(a[r] == mxv) l = r;
            res = max(res, mx.QR(l, r)+mx.QR(r+1, l+n-1) - mn.QR(l, r) - mn.QR(r+1, l+n-1));
        }

        for(int i = 2*n; i; i--){
            if(a[i] == mxv){
                l = r = i;
                break;
            }
        }
        for(int i = 0; i < n; l--, i++){
            if(a[l] == mxv) r = l;
            res = max(res, mx.QR(l, r)+mx.QR(r+1, l+n-1) - mn.QR(l, r) - mn.QR(r+1, l+n-1));
        }
        cout << res << '\n';
    }
}

//    mx .. mt mc . mn  mb  ma
//    mx - mn + mb - ma
//    mx - mt + max(mb, mc) - mn

//    mb -ma ? max(mb, mc) - mt

//    最大化最小值所在区间的最大值
//    最小化最大值所在区间的最小值
//    次大值，次小值

//    理想
//    mn ... mb .... (mx, ma)