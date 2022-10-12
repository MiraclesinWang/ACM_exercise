#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 12
int abs(int x) { return x > 0 ? x : -x; }

const int INF = 1e8;

int dp[maxn][(1 << 11) + 5];
int dis[maxn][maxn];

struct dot {
	int x, y;
} d[maxn];

int n, m;
void init(int len)
{
	for (int i = 0; i <= len; i++)
		for (int j = 0; j < (1 << (len + 1)); j++)
			dp[i][j] = INF;
	for (int i = 1; i <= len; i++)
		dp[i][1 << i] = dis[0][i];
}
void solve()
{
	memset(dis, 0, sizeof(dis));
	int tmp, len = 0;
	d[0].x = 1, d[0].y = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &tmp);
			if (i == 1 && j == 1) continue;
			if (tmp) d[++len].x = i, d[len].y = j;
		}
	}
	if(len == 0) {printf("0\n");return ;}
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= len; j++)
			dis[i][j] = abs(d[i].x - d[j].x) + abs(d[i].y - d[j].y);
	init(len);
	for (int s = 1; s < (1 << (len + 1)); s++) {
		for (int i = 0; i <= len; i++) {
			if (s&(1 << i)) {
				for (int j = 0; j <= len; j++)
					if (j != i && s&(1 << j))
						dp[i][s] = min(dp[i][s], dp[j][s ^ (1 << i)] + dis[j][i]);
			}
		}
	}
	printf("%d\n", dp[0][(1 << (len + 1)) - 1]);
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
		solve();
}
