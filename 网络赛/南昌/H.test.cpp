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
};
matrix mt[70];

matrix qp(matrix m, ll n)
{
	matrix res;
	res.lu = res.rd = 1, res.ld = res.ru = 0;
	while(n){
		if(n&1) res = res* m;
		n >>= 1, m =m* m;
	}
	return res;
}

int main()
{
	matrix m;
	m.lu = 3, m.ru = 2, m.ld = 1, m.rd = 0;
	int q; ll n;
	scanf("%d%lld", &q, &n);
	d[0] = n, a[0] = 0;
	for(int i = 1; i <= q; i++){
		d[i] = d[i-1]^(a[i-1]*a[i-1]);
		if(d[i] == 0ll) a[i] = 0;
		else if(d[i] == 1ll) a[i] = 1;
		else a[i] = qp(m, d[i]-1).lu;
	}
	/*for(int i = 1; i <= q; i++) printf("%lld ", a[i]);
	printf("\n");*/
	int res = 0;
	for(int i = 1; i <= q; i++) res ^= a[i];
	printf("%lld\n", res);
}
