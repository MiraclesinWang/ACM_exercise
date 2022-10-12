#include <cstdio>
using namespace std;

#define ll long long
const int maxn = 1e7 + 10;
const ll mod = 998244353;
ll a[maxn], d[maxn];
struct matrix{
	ll lu, ru, ld, rd;
	matrix operator * (matrix &oth) const{
		matrix res;
		res.lu = (lu*oth.lu + ru*oth.ld)%mod;
		res.ru = (lu*oth.ru + ru*oth.rd)%mod;
		res.ld = (ld*oth.lu + rd*oth.ld)%mod;
		res.rd = (ld*oth.ru + rd*oth.rd)%mod;
		return res;
	} 
} mt[80];

matrix qp(ll n)
{
	matrix res;
	res.lu = res.rd = 1, res.ld = res.ru = 0;
	int dex = 0;
	while(n){
		if(n&1) res = res* mt[dex];
		n >>= 1, dex++;
	}
	return res;
}

int main()
{
	mt[0].lu = 3, mt[0].ru = 2, mt[0].ld = 1, mt[0].rd = 0;
	for(int i = 1; i < 70; i++) mt[i] = mt[i-1]*mt[i-1];
	int q; ll n;
	scanf("%d%lld", &q, &n);
	d[0] = n, a[0] = 0;
	for(int i = 1; i <= q; i++){
		d[i] = d[i-1]^(a[i-1]*a[i-1]);
		if(d[i] == 0ll) a[i] = 0;
		else if(d[i] == 1ll) a[i] = 1;
		else a[i] = qp(d[i]-1).lu;
	}
	/*for(int i = 1; i <= q; i++) printf("%lld ", a[i]);
	printf("\n");*/
	ll res = 0;
	for(int i = 1; i <= q; i++) res ^= a[i];
	printf("%lld\n", res);
}
/*
1000000 1000000000000000000
*/
