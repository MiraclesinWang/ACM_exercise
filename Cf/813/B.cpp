#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define _(x) x << ' ';
typedef long long LL;
#define INF 0x3f3f3f3f

int main()
{
    int kase, n;
    cin >> kase;
    while(kase--){
        cin >> n;
        int s = 1;
        if(n%2) cout << 1 << ' ', s = 2;
        for(int i = 1; i <= n/2; s+=2, i++) {
            cout << s+1 << ' ' << s << ' ';
        }
        cout << '\n';
    } 
}
