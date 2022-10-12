#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
const int maxk = 5e6 + 5;
#define rep(i, x, y) for(int i =x; i < y; i++)
#define lowbit(x) x&(-x)

struct Edge{
    int v, val, t;
    Edge(int _v, int _val, int _t): v(_v), val(_val), t(_t){}
} E[maxn];
int head[maxn], cnt = 0, T[maxk], res[maxn], sn[maxn], nc[maxn];

void addedge(int u, int v, int l)
{
    E[++cnt] = Edge(v, l, head[u]);
    head[u] = cnt;
}

inline void insert(int d)
{
    for(; d < maxk; d++) T[i]++;
}
inline void erase(int d)
{
    for(; d < maxk; d++) T[i]--;
}
inline void query(int d)
{
    int res = 0;
    for(; d > 0; d--) res += T[i];
    return res;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(T, 0, sizeof(T));
    memset(res, 0, sizeof(res));
    memset(sn, 0, sizeof(sn));
    cnt = 0;
}

int node_cnt(int rt)
{
    int cnt = 0;
    for(int i = head[rt]; ~i; i = E[i].t){
        if(E[i].v == rt) continue;
        cnt += node_cnt(E[i].v);
    }
    nc[rt] = cnt;
    return cnt;
}

void solve(int rt, int e)
{
    int mx = 0, md = -1;
    for(int i = head[rt]; ~i; i = E[i].t){
        if(E[i].v == rt) continue;
        if(nc[E[i].v] > mx) md = E[i].v;
    }
    for(int i = head[rt]; ~i; i = E[i].t){
        if(E[i].v == rt) continue;
        solve(E[i].v, 1);
    }
    solve(md, 0);

}

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    while(cin >> n >> k, n&&k){
        init();
        rep(i, 1, n){
            int u, v, l;
            cin >> u >> v >> l;
            addedge(u, v, l), addedge(v, u, l);
        }
        solve(0, 0);
    }
}