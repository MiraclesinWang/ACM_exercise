#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
typedef long long LL;
const LL INF = 1e12;

vector<LL> fibo, s;

void init()
{
    fibo.push_back(1); s.push_back(1);
    fibo.push_back(1); s.push_back(2);
    for(int i = 2; fibo[i-1]+fibo[i-2] < INF; i++){
        fibo.push_back(fibo[i-1]+fibo[i-2]);
        s.push_back(s[i-1]+fibo[i]);
    }
}

string solve()
{
    int n;
    cin >> n;
    LL t, sm = 0;
    vector <LL> v;
    rep(i, 0, n){
        cin >> t;
        v.push_back(t);
        sm += t;
    }
    int d = lower_bound(s.begin(), s.end(), sm) - s.begin(), p = -1;
    if(s[d] != sm) return "NO";
    for(int i = d; ~i; i--){
        int md = max_element(v.begin(), v.end()) - v.begin(), mp = -1;
        rep(j, 0, v.end()-v.begin()){
            if(v[md] == v[j] && p != j) mp = j;
        }
        if(mp < 0 || v[mp] < fibo[i]) return "NO";
        v[mp] -= fibo[i], p = mp;
    }
    return "YES";
}

int main()
{
    ios::sync_with_stdio(false);
    int kase;
    cin >> kase;
    init();
    while(kase--){
        cout << solve() << '\n';
    }
}

// 1 1 2 3 5 8