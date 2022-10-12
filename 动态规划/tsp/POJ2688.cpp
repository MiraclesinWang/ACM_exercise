#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn 11

const int INF = 1e8;

int dp[maxn][(1 << 10) + 5];
int dis[maxn][maxn];
char c;
int maze[22][22];
bool vis[22][22];

struct dot {
	int x, y;
	int cnt;
} d[maxn];
queue <dot> q;

int n, m;       //n是行，m是列 
int dis_get(dot s ,dot e)
{
	int x,y,c;
	dot nw;
	while (!q.empty()) q.pop();
	memset(vis, false, sizeof(vis));
	s.cnt = 0;
	q.push(s);
	while(!q.empty()){
		x = q.front().x, y = q.front().y ,c = q.front().cnt;
		if(x == e.x && y == e.y) return c;
		q.pop();
		nw.x = x, nw.y = y ,nw.cnt = c+1;
		if(x>1 && !vis[x-1][y] && maze[x-1][y]) nw.x -= 1,vis[x-1][y]=true, q.push(nw), nw.x += 1;
		if(y>1 && !vis[x][y-1] && maze[x][y-1]) nw.y -= 1,vis[x][y-1]=true, q.push(nw), nw.y += 1;
		if(x<n && !vis[x+1][y] && maze[x+1][y]) nw.x += 1,vis[x+1][y]=true, q.push(nw), nw.x -= 1;
		if(y<m && !vis[x][y+1] && maze[x][y+1]) nw.y += 1,vis[x][y+1]=true, q.push(nw), nw.y -= 1;
	}
	return -1;
}

void init(int len,int sx,int sy)
{
	dot nw;
	nw.x = sx, nw.y = sy;
	for (int i = 0; i <= len; i++)
		for (int j = 0; j < (1 << (len + 1)); j++)
			dp[i][j] = INF;
	for (int i = 0; i <= len; i++)
		dp[i][1 << i] = dis_get(nw,d[i]);
}

void solve()
{
	memset(dis, 0, sizeof(dis));
	int tmp, len = -1, sx, sy;
	for (int i = 1; i <= n; i++) {
		scanf("\n");
		for (int j = 1; j <= m; j++) {
			scanf("%c", &c);
			if (c == '*') d[++len].x = i, d[len].y = j, maze[i][j] = 1;
			else if (c == 'o')  sx = i, sy = j, maze[i][j] = 1;
			else if (c == '.') maze[i][j] = 1;
			else maze[i][j] = 0;
		}
	}
	if (len == -1) {printf("0\n"); return ;}
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= len; j++)
			dis[i][j] = dis_get(d[i],d[j]);
	for(int i = 0; i <= len; i++)
		for (int j = 0; j <= len; j++)
			if(dis[i][j]==-1)
				{printf("-1\n");return ;}
	init(len,sx,sy);
	for (int s = 1; s < (1 << (len + 1)); s++) {
		for (int i = 0; i <= len; i++) {
			if (s&(1 << i)) {
				for (int j = 0; j <= len; j++)
					if (j != i && s&(1 << j))
						dp[i][s] = min(dp[i][s], dp[j][s ^ (1 << i)] + dis[j][i]);
			}
		}
	}
	int res = 0x3f3f3f3f;
	for(int i = 0; i <= len ;i++)
		res = min(res, dp[i][(1 << (len + 1)) - 1]);
	printf("%d\n", res);
}
int main()
{
	while (scanf("%d%d", &m, &n), m && n)
		solve();
}
