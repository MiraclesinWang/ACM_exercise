#include <cstdio>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

ll qp(ll a, ll n)
{
	ll res = 1;
	while(n){
		if(n&1) res= a*res%mod;
		n >>= 1, a = a*a%mod;
	}
	return res;
}

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	printf("%lld\n", (qp(m, n) - (m*qp(m-1, n-1))%mod + mod)%mod);
}
