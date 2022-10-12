#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int INF = 1e8 + 10;
const int BOUND = 1e6 + 1;
#define rep(i, x, y) for(int i =x; i <y; i++)
#define lowbit(x) x&(-x)

struct dool{
    int x, y, t, dis, type, dex;
}d[4][maxn], tmp[maxn];
int res[maxn], T[maxn], n, m;
queue <int> q;

inline void insert(int d, int val)
{
    for(int i = d; i <= maxn; i += lowbit(i)) T[i] = max(T[i], val);
}
inline int query(int d)
{
    int ans = 0;
    for(int i = d; i > 0; i -= lowbit(i)) ans = max(T[i], ans);
    return ans;
}
inline void erase(int d)
{
    for(int i = d; i <= maxn; i += lowbit(i)) T[i] = 0;
}

void CDQ(int l, int r, dool *A)
{
    if(l==r) return;
    int mid = (l+r) >> 1;
    CDQ(l, mid, A), CDQ(mid+1, r, A);
    for(int d1=l, d2=mid+1, i=l; i<=r; i++){
        if(d1 > mid || (d2 <= r && A[d1].x > A[d2].x)){
            tmp[i] = A[d2++];
            if(tmp[i].type == 2){
                int mx = query(tmp[i].y);
                if(mx) res[tmp[i].dex] = min(tmp[i].x + tmp[i].y - mx, res[tmp[i].dex]);
            }
        }
        else{
            tmp[i] = A[d1++];
            if(tmp[i].type == 1) insert(tmp[i].y, tmp[i].x+tmp[i].y);
        }
    }
    rep(i, l, r+1){
        A[i] = tmp[i];
        if(tmp[i].type == 1) erase(tmp[i].y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset(T, 0, sizeof(T));
    memset(res, INF, sizeof(res));

    cin >> n >> m;
    rep(i, 0, n){
        cin >> d[0][i].x >> d[0][i].y;
        d[0][i].y++;
        d[0][i].type = 1, d[0][i].t = 0;
        d[1][i] = d[0][i], d[2][i] = d[0][i], d[3][i] = d[0][i];
        d[1][i].x = BOUND-d[0][i].x;
        d[2][i].y = BOUND-d[0][i].y;
        d[3][i].x = BOUND-d[0][i].x, d[3][i].y = BOUND-d[0][i].y;
    }
    rep(i, n, m+n){
        cin >> d[0][i].type >> d[0][i].x >> d[0][i].y;
        d[0][i].y++;
        d[0][i].t = i-n+1, d[0][i].dex = i-n+1;
        d[1][i] = d[0][i], d[2][i] = d[0][i], d[3][i] = d[0][i];
        d[1][i].x = BOUND-d[0][i].x;
        d[2][i].y = BOUND-d[0][i].y;
        d[3][i].x = BOUND-d[0][i].x, d[3][i].y = BOUND-d[0][i].y;
        if(d[0][i].type == 2) q.push(i-n+1);
    }

    rep(i, 0, 4) CDQ(0, m+n, d[i]);
    while(!q.empty()){
        cout << res[q.front()];
        q.pop();
        if(!q.empty()) cout << '\n';
    }
}