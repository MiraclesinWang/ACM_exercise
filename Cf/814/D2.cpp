#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase, n;
    cin >> kase;
    rep(k, 1, kase+1){
        cin >> n;
        vector <int> a(n+1), b(n+1);
        map <int, int> mp;
        a[0] = b[0] = 0;
        rep(i, 1, n+1){
            cin >> a[i];
            b[i] = b[i-1] ^ a[i];
        }
        int res = n, d = -1;
        mp[0] = 0;
        rep(i, 1, n+1){
            if(a[i] == 0) res--, d = i;
            else if(mp.find(b[i]) != mp.end()){
                if(mp[b[i]] >= d) 
                res--, d = i;
            }
            mp[b[i]] = i;
        }
        cout << res << '\n';
    }
}
// 18
// 0 0 3134 3134 3980 4127 1145 4374 392 2932 0 1741 2273 1028 4147 0 4445 2886 