#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
const int maxn = 2e5 + 5;

LL T[maxn], res[maxn];
int L[maxn], R[maxn];

vector <vector <int>> v(maxn), qs(maxn);

inline void insert(int d, int val)
{
    for(int i = d; i < maxn; i += lowbit(i)) T[i] += val;
}
inline LL query(int d)
{
    LL ans = 0;
    for(int i = d; i > 0; i -= lowbit(i)) ans += T[i];
    return ans;
}

void solve()
{
    for(int i = 1; i < maxn; i++){
        for(int j = i*2; j < maxn; j+= i)
            v[j].push_back(i);
        for(auto j = v[i].begin(); j != v[i].end(); j++){
            insert(*j, v[i].end() - j - 1);
        }
        for(auto j = qs[i].begin(); j!=qs[i].end(); j++){
            int d = *j;
            res[*j] = LL(R[d]-L[d])*(R[d]-L[d]+1)*(R[d]-L[d]-1)/6;
            res[*j] -= query(i) - query(L[*j]-1);
            res[*j] -= max(i/15 - (L[d]+5)/6 +1, 0);
            res[*j] -= max(i/6 - (L[d]+2)/3 +1, 0);
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    MEM(T, 0);
    int kase;
    cin >> kase;
    rep(i, 0, kase){
        cin >> L[i] >> R[i];
        qs[R[i]].push_back(i);
    }
    solve();
    rep(i, 0, kase) cout << res[i] << '\n';
}