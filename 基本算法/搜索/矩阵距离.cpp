#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1005;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

int m, n, dis[maxn][maxn];

struct node{
	int x, y, d;
	node(int _x, int _y, int _d):x(_x), y(_y), d(_d){}
};
queue <node> q;

void init()
{
	memset(dis, -1, sizeof(dis));
	while(!q.empty()) q.pop();
}

void check(node now)
{
	//if(dis[now.x][now.y] >= 0) return;
	rep(i, -1, 2)
		rep(j, -1, 2){
			if(i&j) continue;
			int x = now.x + i, y = now.y + j;
			if(!x || x > n || !y || y > m) continue;
			if(dis[x][y] < 0){
				dis[x][y] = now.d + 1;
				q.push(node(x, y, dis[x][y])); 
			}
			
		}
}

int main()
{
	init();
	scanf("%d%d", &n, &m);
	rep(i, 1, n+1){
		scanf("\n");
		rep(j, 1, m+1){
			char c;
			scanf("%c", &c);
			if(c == '1') q.push(node(i, j, 0)), dis[i][j] = 0;
		}
	}
	while(!q.empty()){
		node tmp = q.front();
		q.pop();
		check(tmp);
	}
	rep(i, 1, n+1)
		rep(j, 1, m+1)
			printf("%d", dis[i][j]), printf(j==m?"\n":" ");
}


