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
    int kase, n, k;
    cin >> kase;
    while(kase--){
        cin >> n >> k;
        if(k%2 == 0){
            if(k%4 == 2){
                cout << "YES\n";
                for(int i =1; i + 1 <= n; i+=2){
                    if((i+1) % 4 == 0) cout << i << ' ' << i+1 << '\n';
                    else cout << i+1 << ' ' << i << '\n';
                }
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
            for(int i = 1; i +1 <= n; i+=2)
            // cout << i << ' ' << i+1 << ' ' << n << '\n';
                cout << i << ' ' << i+1 << '\n';
        }
    }
}