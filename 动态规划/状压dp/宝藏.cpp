#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

int n, m;
ll dp[12][1<<12], dis[12][12];
int mp[12][12];

void floyd()
{
	memset(mp, INF, sizeof(mp));
	rep(i, 0, n) rep(j, 0, n) if(dis[i][j] < (INF>>1)) mp[i][j] = 1; 
	rep(k, 0, n)
		rep(i, 0, n)
			rep(j, 0, n)
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}

int main()
{
	memset(dp, (ll)INF, sizeof(dp));
	memset(dis, (ll)INF, sizeof(dis));
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		int u, v;
		ll l;
		scanf("%d%d%lld", &u, &v, &l);
		u--; v--;
		dis[u][v] = dis[v][u] = min(dis[u][v], l);
	}
	floyd();
	rep(i, 0, n) dp[i][(1<<i)] = 0;
	rep(s, 1, (1<<n)-1){
		rep(i, 0, n){
			if(!(s&(1<<i))) continue;
			rep(j, 0, n){
				if(s&(1<<j)) continue;
				rep(k, 0, n) 
					dp[k][s^(1<<j)] = min(dp[k][s^(1<<j)], dp[k][s] + (ll)mp[k][j] * dis[i][j]);
			}
		}
	}
	ll ans = INF;
	rep(i, 0, n) ans = min(ans, dp[i][(1<<n)]);
	printf("%lld\n", ans);
}


