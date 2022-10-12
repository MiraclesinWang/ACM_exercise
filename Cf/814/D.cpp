#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
const int maxn = 1e5 + 5;

int a[maxn], b[maxn];
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase, n;
    cin >> kase;
    while(kase--){
        cin >> n;
        mp.clear();
        rep(i, 0, n){
            cin >> a[i];
            b[i] = a[i];
            if(i){
                a[i] ^= a[i-1];
                b[i] = b[i-1] ^ a[i];
            }
        }
        int res = n, d = -1;
        rep(i, 0, n){
            if(a[i] == 0){
                res--;
                d = i;
            }
            else if(mp.find(b[i]) != mp.end()){
                if(mp[b[i]] > d){
                    res--;
                    d = i;
                }
            }
            mp[b[i]] = i;
        }
        cout << res << '\n';
    }

}