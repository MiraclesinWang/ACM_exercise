#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;

#define ll long long
const ll mod = 1e9 + 7; 
ll dp[20][10][7][7], tp[20][10][7][7], cnt[20][10][7][7]; //位数，首位数字，数%7，总和%7
//数组分别是平方和、sum、方案数 
ll tb[20]; 
int num[20]; 

void init()
{
	for(int i = 0; i < 10; i++)
		if(i != 7)
			dp[0][i][i%7][i%7] = (ll)i*(ll)i, tp[0][i][i%7][i%7] = (ll)i, cnt[0][i][i%7][i%7] = 1; 
	for(int i = 1; i < 18; i++){
		for(int j = 0; j < 10; j++){
			if(j == 7) continue; 
			for(int k = 0; k < 7; k++){
				for(int m = 0; m < 7; m++){
					int c = ((ll)j * tb[i]) % 7, a = (k- c + 7) % 7, b = (m-j+14) % 7; 
					for(int p = 0; p < 10; p++){
						if(p == 7) continue; 
						cnt[i][j][k][m] += cnt[i-1][p][a][b];  
						tp[i][j][k][m] += (cnt[i-1][p][a][b]*tb[i]%mod*(ll)j%mod + tp[i-1][p][a][b]) % mod; 
						dp[i][j][k][m] += (((ll)(j*j)*tb[i] % mod *tb[i]%mod*cnt[i-1][p][a][b] % mod + tb[i]*tp[i-1][p][a][b] % mod*(ll)(2*j) %mod)%mod + dp[i-1][p][a][b]) % mod;
						cnt[i][j][k][m] %= mod, tp[i][j][k][m] %= mod, dp[i][j][k][m] %= mod; 
					}
				}
			}
		}
	}
} 

ll query(ll a)
{
	a++;
	ll res = 0;
	if(a > (ll)1e18) {a-- ;res = (a%mod)*(a%mod)%mod;}
	if(a == (ll)1e18) {a--; res += (a%mod)*(a%mod)%mod;}
	ll b = a, c = 0; 
	memset(num, 0, sizeof(num));
	int dex = 0, m1 = 0, m2 = 0; 
	while(a){
		num[dex++] = (int)(a % 10);
		a /= 10; 
	} 
	dex--;
	//printf("%lld ", res);
	while(dex >= 0){
		int p = (7-m1)%7, q = (7-m2) % 7;
		for(int i = 0; i < num[dex]; i++){
			if(i == 7) continue;
			for(int j = 0; j < 7; j++){
				if(j == p) continue; 
				for(int k = 0; k < 7; k++){
					if(k == q) continue; 
					res += ((dp[dex][i][j][k] + 2*tp[dex][i][j][k]%mod*c%mod)%mod + cnt[dex][i][j][k]*c%mod*c%mod) % mod;
					res %= mod;
				} 
			} 
		}
		//printf("%lld ", res);
		m1 = (m1 + tb[dex]*num[dex]) % 7;
		m2 = (m2 + num[dex]) % 7; 
		if(num[dex] == 7) break; 
		c += tb[dex] * (ll)num[dex] % mod, c %= mod ,dex--;
	}
	return res; 
} 

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(tp, 0, sizeof(tp)); 
	memset(cnt, 0, sizeof(cnt)); 
	tb[0] = 1;
	for(int i = 1; i < 20; i++)
		tb[i] = tb[i-1] * 10 % mod;
	init(); 
	/*ll t = 0;	
	while(scanf("%lld", &t), t)
		printf("%lld\n", query(t));*/
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		ll s, e;
		scanf("%lld%lld", &s, &e);
		printf("%lld\n", (query(e) - query(s-1) + mod) % mod); 	
	}
}
