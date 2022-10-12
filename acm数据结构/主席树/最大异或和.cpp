#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i < y; i++)
const int maxn = 6e5 + 5;

int a[maxn], cnt = 0, head[maxn];
struct query{
    int l, r, x;
    query(){}
    query(int _l, int _r, int _x):l(_l), r(_r), x(_x){}
};
queue <query> q;

struct node{
    int l, r, cnt;
}T[maxn*32];

int build(int val, int t)
{
    int rt = ++cnt, res = rt;
    //cout <<  "now build: " << val << ' ' << t << '\n';
    for(int i = 24; ~i; i--){
        if((1<<i)&val){
            T[rt].r = ++cnt;
            T[rt].l = T[t].l;
            t = T[t].r;
        }
        else{
            T[rt].l = ++cnt;
            T[rt].r = T[t].r;
            t = T[t].l;
        }
        //cout << rt << ' ' << T[rt].l << ' ' << T[rt].r << ' ' << T[rt].cnt << '\n';
        rt = cnt;
        T[rt].cnt = T[t].cnt + 1;
    }
    return res;
}

int ask(int l, int r, int x)
{
    int rt = head[r], t = head[l], res = 0;
    for(int i = 24; ~i; i--){
        if((1<<i)&x){
            //cout << rt << ' ' << t << ' ' << T[rt].l << ' ' << T[t].l << ' ' << T[T[rt].l].cnt << ' ' << T[T[t].l].cnt << '\n';
            if(T[T[rt].l].cnt > T[T[t].l].cnt) res += (1<<i), rt = T[rt].l, t = T[t].l;
            else rt = T[rt].r, t = T[t].r;
        }
        else{
            //cout << rt << ' ' << t << ' ' << T[rt].r << ' ' << T[t].r << ' ' << T[T[rt].r].cnt << ' ' << T[T[t].r].cnt << '\n';
            if(T[T[rt].r].cnt > T[T[t].r].cnt) res += (1<<i), rt = T[rt].r, t = T[t].r;
            else rt = T[rt].l, t = T[t].l;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    memset(T, 0, sizeof(T));
    int n, m;
    cin >> n >> m;
    a[0] = 0, head[0] = 0;
    rep(i, 1, n+1) cin >> a[i], a[i] ^= a[i-1], head[i] = build(a[i], head[i-1]);
    rep(i, 1, m+1){
        char c;
        cin >> c;
        if(c == 'A') cin >> a[++n], a[n] ^= a[n-1], head[n] = build(a[n], head[n-1]);
        else{
            int l, r, x;
            cin >> l >> r >> x;
            q.push(query(l, r, x^a[n]));
        }
    }

    while(!q.empty()){
        //cout << q.front().l << ' ' << q.front().r << ' ' << q.front().x << '\n';
        int res = ask(max(q.front().l-2, 0), q.front().r-1, q.front().x);
        if(q.front().l == 1) res = max(res, q.front().x);
        cout << res;
        q.pop();
        if(!q.empty()) cout << '\n';
    }
}
/*
l-1~r-1区间，选一个数，和x^a[N]的异或值最大
如果始终是全部区间，则trie树可解

*/