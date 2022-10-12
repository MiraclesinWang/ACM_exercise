#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f

int mp[505][505], p[505][505];

int get_ans(int n, int m)
{
    memcpy(p, mp, sizeof(mp));
    int res = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            if(p[i][j]+p[i+1][j]+p[i][j+1]+p[i+1][j+1] == 0)
                continue;
            else if(p[i][j]+p[i+1][j]+p[i][j+1]+p[i+1][j+1] == 1)
                res += 1;
            else res += 2;
            p[i][j] = p[i+1][j] = p[i][j+1] = p[i+1][j+1] = 0;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int kase;
    cin >> kase;
    while(kase--){
        int n, m, res = 0;
        cin >> n >> m;
        rep(i, 1, n+1){
            string s;
            cin >> s;
            rep(j, 1, m+1) {
                mp[i][j] = s[j-1] == '1';
            }
        }
        res = max(res, get_ans(n, m));

        rep(i, 1, n/2+1){
            rep(j, 1, m+1) swap(mp[i][j], mp[n+1-i][j]);
        }
        res = max(res, get_ans(n, m));

        rep(i, 1, n+1){
            rep(j, 1, m/2+1) swap(mp[i][j], mp[i][m+1-j]);
        }
        res = max(res, get_ans(n, m));

        rep(i, 1, n/2+1){
            rep(j, 1, m+1) swap(mp[i][j], mp[n+1-i][j]);
        }
        res = max(res, get_ans(n, m));
        cout << res << '\n';
    }
}