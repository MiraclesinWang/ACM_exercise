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
    int kase, n, m;
    cin >> kase;
    while(kase--){
        cin >> n >> m;
        if((n+m)%2) cout << "Burenka\n";
        else cout << "Tonya\n";
    }
}