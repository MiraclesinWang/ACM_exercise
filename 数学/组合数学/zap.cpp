#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;
const int maxn = 5e4 + 5;
int mu[maxn], smu[maxn], prim[maxn], cnt = 0;
bool vis[maxn];

void get_mu()
{
    memset(vis, false, sizeof(vis));
    cnt = 0;
    mu[1]=1, smu[0] = 0;
    rep(i, 2, maxn)
    {
        if(!vis[i]){prim[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&prim[j]*i<maxn;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    rep(i, 1, maxn) smu[i] = smu[i-1] + mu[i];
 }

int main()
{
    get_mu();
    int a, b, d, n;
    cin >> n;
    while(n--){
        cin >> a >> b >> d;
        a/=d, b/=d;
        if(a > b) swap(a, b);
        LL res = 0;
        int l, r = a+1;
        for(int i=1, j=1; i <= sqrt(a) && j <= sqrt(b);){
            int ni = i, nj = j;
            if(a/(i+1) == b/(j+1)) i++, l = b/++j+1;
            else if(a/(i+1) < b/(j+1)) l = b/++j+1;
            else l = a/++i +1;
            if(l >= r) continue;
            res += LL(smu[r-1]-smu[l-1]) * ni*nj;
            r = l;
        }
        rep(i, 1, r) res += (LL)mu[i] * (a/i) * (b/i);
        cout << res;
        if(n) cout << '\n';
    }
}