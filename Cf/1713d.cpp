#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define query(a, b) {cout << "? " << a << ' ' << b << '\n'; cout.flush();}
queue <int> q;
int tmp[5];

void solve()
{
    int n, m, res;
    cin >> n;
    while(!q.empty()) q.pop();
    rep(i, 1, (1<<n)+1) q.push(i);
    for(;n>=2; n-=2){
        rep(i, 0, 1<<(n-2)){
            rep(j, 1, 5) tmp[j] = q.front(), q.pop();
            query(tmp[1], tmp[3]);
            cin >> m;
            if(!m){
                query(tmp[2], tmp[4]);
                cin >> m;
                if(m == 1) q.push(tmp[2]);
                else q.push(tmp[4]);
            }
            else{
                int d = (m==1?tmp[1]:tmp[3]), t = (m==1?tmp[4]:tmp[2]);
                // cout << d << "vs:" << t << '\n';
                // cout << m << d << t << '\n';
                query(d, t);
                cin >> m;
                if(m == 1) q.push(d);
                else q.push(t);
            }
        }
    }
    if(n==1){
        int d = q.front();
        q.pop();
        query(d, q.front());
        cin >> m;
        res = (m==1?d:q.front());
    }
    else res = q.front();
    cout << "! " << res << '\n';
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}