#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn  = 5e4 + 10;
int mm[maxn], tmp[maxn];
int cnt[maxn];
char rub;
int n, m;

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("%d%d", &n, &m);
	//printf("%d%d\n", n, m);
	int c, res = 0, r;
	for(int i = 1; i <= n; i++){
		scanf("\n");
		c = 0;
		for(int j = 1; j <= m; j++){
			scanf("%c", &rub);
			//printf("%c ", rub);
			if(rub == '*') tmp[j] = 1, c++, cnt[j]++;
			else tmp[j] = 0;			
		}
		//printf("%d %d\n", c, res);
		if(res < c){
			res = c;
			for(int j = 1; j <= m; j++)
				mm[j] = tmp[j];
		}
		else if(res == c){
			for(int j = 1; j <= m; j++)
				mm[j] = (mm[j] & tmp[j]);
		}
		//printf("aaaa\n");
	}
	/*for(int j =1; j <= m; j++)
		printf("%d ",mm[j]);
	printf("\n");*/
	/*for(int j =1; j <= m; j++)
		printf("%d ",cnt[j]);*/
	int cpy = res;
	//printf("%d\n", res);
	c = 0;
	res = 100000;
	int t = 0;
	for(int i = 1; i <= m; i++){
		if(cnt[i] >= c){
			c = cnt[i];
			//printf("%d %d\n", m+n, (c+cpy));
			t = m + n - 1 -(c + cpy);
			if(mm[i]) t++;
			res = min(res, t);
			//printf("%d\n", t);
		}
	}
	printf("%d\n", res);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve();
}
/*
1
2 2
.*
*.
*/
