#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
#define rep(i, x, y) for(int i = x; i < y; i++)

struct bar{
	int x, y, dir, step;
	// dir: 0: single cell; 1: downside; 2: rightside
};

char mp[maxn][maxn];
int r, c;
queue <bar> q;
bool vis[maxn][maxn][3];

void check(bar b){
	int x = b.x, y = b.y;
	if(vis[x][y][b.dir]) return;
	if(x < 0 || y < 0 || x >=r || y >= c) return;
	if(mp[x][y] == '#') return;
	else if(mp[x][y] == 'E' and !b.dir) return;
	if(b.dir == 1) x++;
	else if(b.dir == 2) y++;
	
	if(x < 0 || y < 0 || x >=r || y >= c) return;
	if(mp[x][y] == '#') return;
	
	q.push(b);
    vis[b.x][b.y][b.dir] = true;
	
}

void rotate(bar b){
	bar tmp;
	tmp.step = b.step + 1;
	if(!b.dir){
		tmp.dir = 1, tmp.x = b.x-2, tmp.y = b.y;
		check(tmp);
		tmp.x = b.x + 1;
		check(tmp);
		tmp.dir = 2, tmp.y = b.y-2, tmp.x = b.x;
		check(tmp);
		tmp.y = b.y + 1;
		check(tmp);
	}
	else if(b.dir == 1){
		tmp.dir = 1, tmp.y = b.y + 1, tmp.x = b.x;
		check(tmp);
		tmp.y = b.y - 1;
		check(tmp);
		tmp.dir = 0, tmp.y = b.y, tmp.x = b.x - 1;
		check(tmp);
		tmp.x = b.x + 2;
		check(tmp);
	}
	else{
		tmp.dir = 2, tmp.y = b.y, tmp.x = b.x+1;
		check(tmp);
		tmp.x = b.x - 1;
		check(tmp);
		tmp.dir = 0, tmp.x = b.x, tmp.y = b.y - 1;
		check(tmp);
		tmp.y = b.y + 2;
		check(tmp);
	}
}

int main()
{
	while(scanf("%d%d", &r, &c), r&&c){
		memset(vis, 0, sizeof(vis));
		int start_x, start_y;
		rep(i, 0, r){
			scanf("\n");
			rep(j, 0, c){
				scanf("%c", &mp[i][j]);
				if(mp[i][j] == 'X') start_x = i, start_y = j;
			}
		}
		while(!q.empty()) q.pop();
		bar start_bar = {start_x, start_y, 0, 0};
		if(mp[start_x-1][start_y] == 'X') start_bar.dir = 1, start_bar.x--;
		else if(mp[start_x][start_y-1] == 'X') stat_bar.dir = 2, start_bar.y--;
		q.push(start_bar);
		bool flag = false;
        bar tmp;
		while(!q.empty()){
			tmp = q.front();
			q.pop();
			if(mp[tmp.x][tmp.y] == 'O' && !tmp.dir) {
				printf("%d\n", tmp.step);
				flag = true;
				break;
			}
			rotate(tmp);
		}
		if(!flag) printf("Impossible\n");
	}

}
