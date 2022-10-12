#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
int prime[maxn], tot = 0, n;
bool vis[maxn];
#define rep(x, y) for(int i = x; i < y; i++)

void init()
{
	memset(vis, false, sizeof(vis));
	rep(2, n+1){
		if(!vis[i]) prime[tot++] = i;
		for(int j = 0; j < tot; j++){
			if(prime[j] > i || prime[j] > n/i) break;
			vis[i*prime[j]] = true;
		}
	}
}

int main()
{
	scanf("%d", &n);
	init();
	rep(0, tot){
		ll j = prime[i];
		int cnt = 0;
		while(j <= (ll)n){
			cnt += n / j;
			j *= prime[i];
		}
		if(cnt) printf("%d %d\n", prime[i], cnt);
	}
 } 
