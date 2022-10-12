// x b g
// x*b/g

// x*b*p/g
// x*b*p/(g*p)
    
// 可行公约数集合为a1乘上任意其他不为a0因子的质数
// am: 记录可用的因子，即a1不包含的其他因子

// 公约数乘上b的任何其他约数，公倍数不变
// 否则公倍数变成乘上的数倍

// 1. 将a1/gcd分解，寻找可用因子
// 2. 计算gcd和b的最小公倍数
// 3. 如果最小公倍数已大于lcm，则为0;
//     如果等于lcm，就在可用因子中统计哪些是b/gcd(b, gcd)的其他约数;
//     如果小于lcm，就要有lcm/lcm(b,gcd)的每个因子，
//     且数量为lcm/b本身该因子的数量+b仍多余的该因子数量
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;
const int maxn = 1e5;
bool vis[maxn], am[maxn];
int prime[maxn], m;

LL _gcd(LL a, LL b)
{
    LL c;
    if(a > b) swap(a, b);
    while(c=b%a){
        b = a, a = c;
    }
    return a;
}

void init()
{
    memset(vis, false, sizeof(vis));
    m = 0;
    rep(i, 2, maxn){
        if(!vis[i]) prime[++m] = i;
        rep(j, 1, m+1){
            if(LL(prime[j])*LL(i) >= LL(maxn)) break;
            vis[prime[j]*i] = true;
            if(i%prime[j] == 0) break;
        }
    }
}

LL solve()
{
    memset(am, false, sizeof(am));
    LL a, b, gcd, lcm;
    cin >> a >> gcd >> b >> lcm;
    if(a%gcd || lcm%b || lcm%gcd) return 0;
    LL ag = a/gcd, bg = _gcd(gcd, b);
    for(int i = 1; i <= m && prime[i] <= sqrt(ag)+1; i++){
        if(ag%prime[i]) am[i] = true;
    }

    if(b/bg*gcd > lcm) return 0;
    LL res = 1;
    int lb = b/bg;
    cout << b/bg*gcd << ' ' << lcm << '\n';
    if(b/bg*gcd < lcm){
        if(lcm%(b/bg*gcd)) return 0;
        int mr = lcm / (b/bg*gcd);
        for(int i = 1; i <= m && prime[i] <= max(mr, lb); i++){
            if(!am[i]){
                if(mr%prime[i] == 0) return 0;
                else continue;
            }
            int cnt = 0;
            while(lb%prime[i] == 0) cnt++, lb/=prime[i];
            if(mr%prime[i] != 0) res *= cnt +1;

        }
        if(lb > 1) res *= 2;
    }
    else{
        for(int i = 1; i <= m && prime[i] <= lb; i++){
            if(!am[i]) continue;
            int cnt = 0;
            while(lb%prime[i] == 0) cnt++, lb/=prime[i];
            res *= cnt+1;
        }
        if(lb > 1) res *= 2;
    }
    return res;
}

int main()
{
    init();
    int n;
    cin >> n;
    while(n--){
        cout << solve();
        if(n) cout << '\n';
    }
}