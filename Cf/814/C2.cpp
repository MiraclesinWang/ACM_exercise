#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
const int maxn = 1e5 + 5;

struct ath{
    int d, a;
    ath(){}
    ath(int _d, int _a):a(_a), d(_d){}
};
deque <ath> q;
int a[maxn], res[maxn][2];

int main()
{
    // ios::sync_with_stdio(false);
    int kase, n, qr;
    cin >> kase;
    while(kase--){
        cin >> n >> qr;
        q.clear();
        MEM(res, 0);
        rep(i, 1, n+1) cin >> a[i], q.push_back(ath(i, a[i]));
        rep(i, 1, n+1){
            ath x = q.front(); q.pop_front();
            ath y = q.front(); q.pop_front();
            ath w;
            if(x.a > y.a){
                q.push_front(x);
                q.push_back(y);
                w = x;
            }
            else{
                q.push_front(y);
                q.push_back(x);
                w = y;
            }
            if(res[w.d][0] == 0){
                res[w.d][0] = i, res[w.d][1] = 1;
            }
            else res[w.d][1]++;
        }
        int d = max_element(a+1, a+1+n) -a;
        res[d][1] = int(1e9);
        while(qr--){
            int p, k;
            cin >> p >> k;
            // if(p == d){
            //     if(k < res[p][0]) cout << "0\n";
            //     else cout << k - res[p][0]+1 << '\n';
            // }
            int l = res[p][0], r = min(res[p][0]+res[p][1]-1, k);
            if(l == 0 || l > r) cout << "0\n";
            else cout << r-l+1 << '\n';
        }
    }
}