#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(x, y) for(int i = x; i< y; i++)
ll gcd(ll a, ll b)
{
	if(a > b) swap(a, b);
	while(b%a){
		ll c = b %a ;
		b = a; a = c;
	}
	return a;
}

struct number{
	ll inte, u, d;
	number operator +(number &oth){
		number res;
		res.inte = inte + oth.inte;
		ll dd = oth.d*d, uu = oth.u*d + oth.d*u;
		if(!uu) {res.u = 0, res.d = 1;return res;}
		ll g = gcd(dd, uu);
		
		dd /= g, uu /= g;
		if(uu >= dd){
			res.inte += uu/dd;
			uu %= dd;
			if(!uu) dd = 1;
		}
		res.u = uu, res.d = dd;
		return res;
	}
} dp[50];


int main()
{
	int n; number tmp;
	while(scanf("%d", &n) != EOF){
		dp[n].inte = dp[n].u = 0, dp[n].d = 1;
		for(int i = n-1; ~i; i--){
			tmp.u = i, tmp.d = n-i, tmp.inte = 1;
			dp[i] = dp[i+1] + tmp;
		}
		if(dp[0].u){
			int len1 = log10(dp[0].inte)+1, len2 = log10(max(dp[0].u, dp[0].d))+1;
			rep(0, len1+1) printf(" ");
			printf("%lld\n", dp[0].u);
			printf("%lld ", dp[0].inte);
			rep(0, len2) printf("-");
			printf("\n");
			rep(0, len1+1) printf(" ");
			printf("%lld\n", dp[0].d);
		}
		else printf("%lld\n", dp[0].inte);
	}
 } 
