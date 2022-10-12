#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define _(x) x << ' ';
typedef long long LL;
#define INF 0x3f3f3f3f
const int maxn = 200;
int a[maxn];

int main()
{

    int n, k, kase;
    cin >> kase;
    while(kase--){
        int res = 0;
        cin >> n >> k;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, k) res += a[i] > k;
        cout << res << '\n';
    }
}