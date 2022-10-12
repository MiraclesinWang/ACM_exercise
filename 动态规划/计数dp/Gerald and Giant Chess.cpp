#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2e5;
const int maxm = 2e3 + 5;
ll jc[maxn], jcinv[maxn], dp[maxm];
#define rep(i, x, y) for(int i = x; i < y; i++)
int h, w, n;

ll quick_pow(ll a, int b)
{
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		b >>= 1; a = (a*a)%mod;
	}
	return res;
}

ll C(int a, int b){
	if(a < b) swap(a, b);
	return jc[a]*jcinv[b]%mod*jcinv[a-b]%mod;
}

void init()
{
	jc[0] = jc[1] = 1;
	jcinv[0] = jcinv[1] = 1;
	rep(i, 2, maxn){
		jc[i] = (jc[i-1]*(ll)i)%mod;
		jcinv[i] = quick_pow(jc[i], (int)mod-2);
	}
	memset(dp, 0, sizeof(dp));
}

struct dot{
	int x, y;
	bool operator < (const dot &oth){
//		if(x <= oth.x && y <= oth.y) return true;
//		else return false;
		if(x == oth.x) return y < oth.y;
		else return x < oth.x;
	}
} d[maxm];

int main()
{
	init();
	scanf("%d%d%d", &h, &w, &n);
	rep(i, 1, n+1) scanf("%d%d", &d[i].x, &d[i].y);
	sort(d+1, d+1+n);
	d[n+1].x = h, d[n+1].y = w;
	ll res = 0;
	rep(i, 1, n+1){
		dp[i] = C(d[i].x+d[i].y-2, d[i].x-1);
		rep(j, 1, i){
			if(d[j].x <= d[i].x && d[j].y <= d[i].y)
				dp[i] -= (C(d[i].x - d[j].x + d[i].y - d[j].y, d[i].x - d[j].x) * dp[j])%mod,
				dp[i] = (dp[i] + mod) % mod;
		}
		res = (res + dp[i] * C(h-d[i].x + w - d[i].y, h - d[i].x)) % mod;
	}
	printf("%lld\n", (C(h+w-2, h-1)-res+mod)%mod);
}
