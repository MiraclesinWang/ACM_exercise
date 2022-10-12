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
queue <ath> q;
int a[maxn];

int main()
{
    // ios::sync_with_stdio(false);
    int kase, n, qr, t;
    cin >> kase;
    while(kase--){
        cin >> n >> qr;
        
        // while(!q.empty()) q.pop();
        vector <vector<int> > v(n+1);
        rep(i, 1, n+1) cin >> a[i], q.push(ath(i, t));
        for(int i = 1; !q.empty(); i++){
            ath x = q.front();
            q.pop();
            if(q.empty()) {q.pop();break;}
            ath y = q.front();
            q.pop();
            if(x.a > y.a){
                q.push(x);
                v[x.d].push_back(i);
                cout << x.d << ' ' << i << '\n';
            }
            else{
                q.push(y);
                v[y.d].push_back(i);
                cout << y.d << ' ' << i << '\n';
            }
        }
        while(qr--){
            int p, k;
            cin >> p >> k;
            for(auto i= v[p].begin();i < v[p].end(); i++) cout << *i << ' ';
            cout << '\n';
            cout << upper_bound(v[p].begin(), v[p].end(), k) - v[p].begin() << '\n';
        }
    }
}