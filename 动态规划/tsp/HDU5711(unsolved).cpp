#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
struct dot{
	int a,b;
	bool operator <(const dot &oth) const{return a<oth.a;}
} d[20];
int m, n, k, l;
int dp[20][1 << 17];
int dis[20][20];

void solve()
{
	int a, b, c;
	scanf("%d%d%d%d",&n, &m, &k, &l);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].a);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].b);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dis[i][j] = INF;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		dis[a][b] = dis[b][a] = min(dis[a][b], c);
	}
	for(int i = 1; i < n; i++)
		if(dis[i][0])
			dp[i][1<<i]=dis[i][0];
	for(int s = 1; s < (1 << (n+1)); s++){
		for(int i = 0; i < n; i++)
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i = 0; i < t; i++)
		solve();
}
