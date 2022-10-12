#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 13;
const ll INF = 5e8;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

ll dp[maxn][1<<12], dis[maxn][maxn];
int n, m, st[maxn];


void init()
{
	rep(i, 0, maxn) rep(j, 0, 1<<12) dp[i][j] = INF;
	rep(i, 0, maxn) rep(j, 0, maxn) dis[i][j] = INF; 
}

ll cost(int s, int k)
{
	ll res = 0, tmp;
	st[0] = 0;
	rep(i, 0, n)
		if((1<<i) & s) st[++st[0]] = i;
	k = k^s;
	rep(i, 0, n){   //每个要去的点 
		if(!((1<<i) & k)) continue;
		tmp = INF;
		rep(j, 1, st[0]+1) tmp = min(tmp, dis[i][st[j]]);
		res += tmp; 
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	init();
	int u, v;
	ll l;
	rep(i, 0, m) scanf("%d%d%lld", &u, &v, &l), u--, v--,dis[u][v] = dis[v][u] = min(dis[u][v], l);
	rep(i, 0, n) dp[0][1<<i] = 0;
	rep(d, 0, n-1){   //深度 
		rep(i, 1, (1<<n)){  //起始状态 
			rep(j, 1, (1<<n)){  //转移后的状态 
				if((i&j) != i) continue;
				dp[d+1][j] = min(dp[d+1][j], dp[d][i] + (ll)(d+1)*cost(i, j));
			}
		}
	}
	ll res = INF;
	rep(d, 0, n) res = min(res, dp[d][(1<<n)-1]);
	printf("%lld\n", res);
}


