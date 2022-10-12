#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL n, k, res = 0;
    cin >> n >> k;
    if(n > k){
        res += k*(n-k);
    }
    n = min(n+1, k);
    for(LL i = 2; i<= sqrt(k); i++){
        LL m = k/i + 1;
        if(m >= n) continue;
        res += (n-m)*k - (i-1) * (m+n-1) * (n-m) / 2;
        n = m;
    }
    for(LL i = 1; i < n; i++) res += k%i;
    cout << res;
}