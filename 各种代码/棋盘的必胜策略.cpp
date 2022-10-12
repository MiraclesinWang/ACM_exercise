#include <cstdio>
using namespace std;

char map[60][60];
int r, c, k;

int update(int x, int y)
{
	if(map[x][y] == 'E') return -100;
	if(map[x][y] == '.') return 1;
	return 0;
}
int check(int x, int y)
{
	int e = 0;
	if(x > 1) e += map[x-1][y] == 'E';
	if(y > 1) e += map[x][y-1] == 'E';
	if(x < r) e += map[x+1][y] == 'E';
	if(y < c) e += map[x][y+1] == 'E';
	if(e > 0) return 0;
	return 1;
}

int main()
{
	int sx, sy, res = 0;
	scanf("%d%d%d", &r, &c, &k);
	for(int i = 1; i <= r; i++){
		scanf("\n");
		for(int j = 1; j <= c; j++){
			scanf("%c", &map[i][j]);
			//printf("%c\n", map[i][j]);
			if(map[i][j] == 'T') sx = i, sy = j;
		}
	}
	if(sx > 1) res += update(sx-1, sy);
	if(sy > 1) res += update(sx, sy-1);
	if(sx < r) res += update(sx+1, sy);
	if(sy < c) res += update(sx, sy+1);
	
	if(res < 0) {printf("niuniu\n");return 0;}
	if(res == 0) {printf("niumei\n");return 0;}
	
	res = 0;
	if(sx > 1) res += check(sx-1, sy);
	if(sy > 1) res += check(sx, sy-1);
	if(sx < r) res += check(sx+1, sy);
	if(sy < c) res += check(sx, sy+1);
	if(!res) {printf("niumei\n");return 0;}
	
	if(k %2) printf("niuniu\n");
	else printf("niumei\n");
}
