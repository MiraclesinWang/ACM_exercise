#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define _(x) x << ' ';
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 5;

LL T[maxn*16], a[maxn], lzy[maxn*16];

void build(int l, int r, int dex)
{
    if(l == r) T[dex] = a[l];
    else{
        int mid=(l+r) >> 1;
        build(l, mid, dex*2), build(mid+1, r, dex*2+1);
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

void update(int l, int r, int dex, int x, int y, int val)
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

LL query(int l, int r, int dex, int x, int y)
{
    if(l > y || r < x) return 0;
    if(l>=x && r<=y) return T[dex];
    int mid = (l+r) >> 1;
    pushdown(l, r, dex);
    return query(l, mid, dex*2, x, y) + query(mid+1, r, dex*2+1, x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    MEM(T, 0);
    MEM(lzy, 0);
    rep(i, 1, n+1) cin >> a[i];
    build(1, n, 1);
    while(m--){
        int x, y, k, typ;
        cin >> typ >> x >> y;
        if(typ==1){
            cin >> k;
            update(1, n, 1, x, y, k);
        }
        else cout << query(1, n, 1, x, y) << '\n';
    }
}