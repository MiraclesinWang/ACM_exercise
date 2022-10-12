#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5;
const int INF = 0x7f3f3f3f;
int prime[20] = {2,3,5,7,11,13,17,19,23,29,31}, res[maxn], p[maxn][12], t[maxn];
#define DEBUG(a) cout << #a << ": " << a << '\n'

int main()
{
    LL n;
    cin >> n;
    int ans = 1, mx = 0;
    for(int i = 0; i < maxn; i++) res[i] = INF;
    memset(p, 0, sizeof(p));
    res[1] = 1, res[2] = 2;
    p[2][0] = 1;
    for(int i = 2; i < maxn; i++){
        if(res[i] == INF) continue;
        if(res[i] >= n) break;
        for(int j = 0; j <= 10; j++){
            if(j){
                if(p[i][j] == p[i][j-1]) continue;
                if(!p[i][j-1]) break;
            }
            
            if(LL(res[i]) * LL(prime[j]) > LL(n)) break;
            if((LL)res[i / (p[i][j]+1) * (p[i][j]+2)] > (LL)res[i] * prime[j]){
                int dst = i / (p[i][j]+1) * (p[i][j]+2);
                if(dst >= maxn) break;
                mx = max(mx, dst);
                res[dst] = res[i] * prime[j];
                memcpy(p[dst], p[i], sizeof(p[i])),
                p[dst][j]++;
            }

        }
    }
    for(int i = mx; i; i--){
        if(res[i] < INF){
            cout << res[i];
            return 0;
        }
    }
}