#include <cstdio>
using namespace std;
#define ll long long
const ll mod = 998244353;

int pow(int b, int n)
{
	ll res = 1;
	ll a = b;
	while(n){
		if(n&1) res *= a, res %= mod;
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return (int)res;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int tmp = n + m;
	printf("%d\n", pow(2, tmp));
}
