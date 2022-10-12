#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;


int main()
{
	ll n,k;
    scanf("%lld%lld", &n, &k);
    ll tmp = (((ll)sqrt(9+((n+k)<<3))-3)>>1);
    printf("%lld\n", n-tmp);
}
