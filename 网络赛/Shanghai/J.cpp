#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

#define ll long long
ll dp[300*500 + 100], a[300 + 10];
const ll mod = 1e9 + 7;
const int lmt = 300*500;

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sm = 0;
		ll res = 0;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sm += (int)a[i];
		sort(a+1, a+1+n, greater<ll>());
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = lmt; j >= 0; j--){
				if(dp[j]){
					if(2*j+a[i] <= sm && 2*(j+a[i]) >= sm) res = (res+dp[j]) % mod;
					dp[j+a[i]] += dp[j], dp[j+a[i]] %= mod;
				}
			}
			//printf("%lld\n", res);
		}
		printf("%lld\n", res);
	}
}
