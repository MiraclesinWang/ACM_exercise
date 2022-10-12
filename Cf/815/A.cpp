#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f

LL gcd(LL a, LL b)
{
    if(a > b) swap(a, b);
    if(!a) return b;
    LL c;
    while(c = b%a){
        b = a, a = c;
    }
    return a;
}

int get_ans(LL a, LL b, LL c, LL d)
{
    LL l = a*d, r = b*c;
    LL g = max(gcd(l, r), 1ll);
    l /=g, r/=g;
    if(l == r) return 0;
    if(min(l, r) == 0) return 1;
    if(max(l, r)%min(l, r) == 0) return 1;
    return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase;
    cin >> kase;
    while(kase--){
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << get_ans(a, b, c, d) << '\n';
    }
}