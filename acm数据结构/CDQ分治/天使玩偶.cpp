#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
const int INF = 1e8 + 10;
#define rep(i, x, y) for(int i =x; i <y; i++)

struct dool{
    int x, y, t, dis, type, dex;
}d[4][maxn], tmp[maxn], smp[maxn];
int res[maxn];
queue <int> q;

void InCDQ(int l, int r, dool *A)
{
    if(l==r) return;
    int mid = (l+r) >> 1, mx = -INF;
    InCDQ(l, mid, A), InCDQ(mid+1, r, A);
    for(int d1=l, d2=mid+1, i=l; i<=r; i++){
        if(d1 > mid || (d2 <= r && tmp[d1].y > tmp[d2].y)){
            if(tmp[d2].t == 1 && tmp[d2].type == 2 && mx != -INF){
                res[tmp[d2].dex] = min(res[tmp[d2].dex], tmp[d2].x+tmp[d2].y - mx);
            }
            smp[i] = tmp[d2++];
        }
        else{
            if(tmp[d1].t == 0 && tmp[d1].type == 1){
                mx = max(mx, tmp[d1].x + tmp[d1].y);
            }
            smp[i] = tmp[d1++];
        }
    }
    rep(i, l, r+1) tmp[i] = smp[i];
}

void CDQ(int l, int r, dool *A)
{
    if(l==r) return;
    int mid = (l+r) >> 1;
    CDQ(l, mid, A), CDQ(mid+1, r, A);
    for(int d1=l, d2=mid+1, i=l; i<=r; i++){
        if(d1 > mid || (d2 <= r && A[d1].x > A[d2].x)){
            tmp[i] = A[d2++];
            tmp[i].t = 1;
        }
        else{
            tmp[i] = A[d1++];
            tmp[i].t = 0;
        }
    }
    rep(i, l, r+1) A[i] = tmp[i];
    InCDQ(l, r, A);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, 0, n){
        cin >> d[0][i].x >> d[0][i].y;
        d[0][i].type = 1, d[0][i].t = 0;
        d[1][i] = d[0][i], d[2][i] = d[0][i], d[3][i] = d[0][i];
        d[1][i].x = -d[0][i].x;
        d[2][i].y = -d[0][i].y;
        d[3][i].x = -d[0][i].x, d[3][i].y = -d[0][i].y;
    }
    rep(i, n, m+n){
        cin >> d[0][i].type >> d[0][i].x >> d[0][i].y;
        d[0][i].t = i-n+1, d[0][i].dex = i-n+1;
        d[1][i] = d[0][i], d[2][i] = d[0][i], d[3][i] = d[0][i];
        d[1][i].x = -d[0][i].x;
        d[2][i].y = -d[0][i].y;
        d[3][i].x = -d[0][i].x, d[3][i].y = -d[0][i].y;
        if(d[0][i].type == 2) q.push(i-n+1);
    }

    memset(res, INF, sizeof(res));
    rep(i, 0, 4) CDQ(0, m+n, d[i]);
    while(!q.empty()){
        cout << res[q.front()];
        q.pop();
        if(!q.empty()) cout << '\n';
    }
}