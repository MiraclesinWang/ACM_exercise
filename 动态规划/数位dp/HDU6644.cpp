#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5e4 + 10;
#define ll long long
ll dp[40][10][25], tp[40][25];
const ll mod = 1e9 + 7;
const ll lmt = 1e18 + 10;
ll mm[maxn];
int n, m, q, cnt;
int num[maxn], d[maxn], t[maxn];

ll query(ll k, ll ans)
{
	if(cnt == 0){
		if(k==1 && tp[0][0]==1) return ans;
		return -1;
	}
    ll res = 0;
    int tmp = 0, a, b;
    for(int i = cnt; i > 0; i--){
    	a = -1, b = (m-tmp)%m;
        for(int j = 0; j < 10; j++){
            if(k > dp[i][j][b]) k -= dp[i][j][b];
            else {a = j;break;}
        }
        if(a == -1) return -1;
        tmp += t[d[i]]*a, tmp %= m;
        res += (ll)a * mm[d[i]], res %= mod;
    }
    return (res+ans)%mod;
}

void ddp(int tmp)
{
	tp[0][tmp] = 1;
	for(int i = 1; i <= cnt; i++){
		for(int j = 0; j < 10; j++){
			for(int p = 0; p < m; p++){
				int a = (p - j*t[d[i]]%m + m)%m;
				dp[i][j][p] += tp[i-1][a];
				tp[i][p] += tp[i-1][a];
				if(dp[i][j][p] > lmt) dp[i][j][p] = lmt;
				if(tp[i][p] > lmt) tp[i][p] = lmt;
			}
		}
	}
}

void solve()
{
	scanf("%d%d%d\n", &n, &m ,&q);	
	t[0] = 1;
	for(int i = 1; i < n; i++) t[i] = t[i-1]*10 % m;
	ll res = 0, k;
	memset(dp, 0, sizeof(dp));
	memset(tp, 0, sizeof(tp));
	char c;	cnt = 0;
	int tmp = 0;
	for(int i = n-1; i >= 0; i--){
		scanf("%c", &c);
		if(c=='?') num[i] = -1, d[++cnt] = i;
		else num[i]=c-'0', res += (ll)num[i]*mm[i], res %= mod,tmp = (tmp+t[i]*num[i])%m;
	}
	sort(d+1, d+1+cnt);
	cnt = min(cnt, 30);
	ddp(tmp);
	for(int i = 0; i < q; i++){
		scanf("%lld", &k);
		printf("%lld\n", query(k, res));
	}
}

int main()
{
    mm[0] = 1;
    for(int i = 1; i < maxn; i++)
        mm[i] = mm[i-1] * 10 % mod;
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();
} 
