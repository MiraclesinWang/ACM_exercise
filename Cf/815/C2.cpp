#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f

int mp[505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        int n, m, res = 0, sm = 0;
        cin >> n >> m;
        rep(i, 1, n+1){
            string s;
            cin >> s;
            rep(j, 1, m+1) {
                mp[i][j] = s[j-1] == '1';
                if(mp[i][j]) sm++;
            }
        }
        rep(i, 1, n){
            rep(j, 1, m){
                if(mp[i][j]+mp[i+1][j]+mp[i][j+1]+mp[i+1][j+1] > 1)
                    res = max(sm -(mp[i][j]+mp[i+1][j]+mp[i][j+1]+mp[i+1][j+1])+2, res);
                else res = max(res, sm);
            }
        }
        cout << res << '\n';
    }
}