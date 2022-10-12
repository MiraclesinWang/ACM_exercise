#include <bits/stdc++.h>
using namespace std;

#define rep(i,x, y) for(int i = x; i < y; i++)
const int maxn = 1e8 + 5;
int tot, x[25];

bool isPrime(int n)
{
    if(n ==2) return true;
    rep(i, 2, sqrt(n)+1){
        if(n%i == 0) return false;
    }
    return true;
}

int dfs(int d, int n, int m, int k, int sm)
{
    if(d == n){
        if(m != k || !(isPrime(sm))) return 0;
        return 1;
    }
    if(m > k) return 0;
    return dfs(d+1, n, m, k, sm) + dfs(d+1, n, m+1, k, sm + x[d]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) cin >> x[i];
    cout << dfs(0, n, 0, k, 0);
}