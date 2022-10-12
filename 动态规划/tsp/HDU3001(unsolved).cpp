/*虽然双重状压也是个方法，但是这里有个更稳为精妙的方法：
三进制，用0表示未访问，用1表示访问过一次，用2表示访问过两次，以此进行状压*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e8 + 5;
int m, n;
const int sze = 59049;
int dp[11][sze];
int cnct[11][11];
bool mod[11][3];

void solve()
{
	int res = INF;
	int a, b, v, tmp;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			cnct[i][j] = INF;
	int pos = pow(3, n);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d",&a ,&b ,&v);
		a -= 1, b -= 1;
		cnct[a][b] = cnct[b][a] =min(v, cnct[a][b]);
	}
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			cnct[i][j] = -1;
	if(n == 1) {printf("0\n");return ;}
	for(int i = 0; i < n; i++){
		bool flag = false;
		for(int j = 0; j < n; j++)
			if(cnct[i][j] < INF) flag = true;
		if(!flag) {printf("-1\n"); return ;}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < pos; j++)
			dp[i][j] = INF;
	for(int i = 0; i < n; i++)
		dp[i][(int)pow(3,i)] = 0;
	for(int s = 1; s < pos; s++){
		bool flag = true;
		tmp = s;
		memset(mod, false, sizeof(mod));
		for(int i = 0; i < n; i++)
			mod[i][tmp % 3] = true, tmp /= 3;
		for(int i = 0; i < n; i++)
			if(mod[i][1] ||  mod[i][2])
				for(int j = 0; j < n; j++)
					if(mod[j][1] || mod[j][2])
						if(cnct[i][j] != -1)
							dp[i][s] = min(dp[i][s], dp[j][s - (int)pow(3,i)] + cnct[i][j]);
		for(int i = 0; i < n ; i++)
			if(mod[i][0]) flag = false;
		if(flag){
			for (int i = 0; i < n; i++)
				res = min(res, dp[i][s]);		
		}
	}
	/*for(int s = 0; s < pos; s++){
		for(int i = 0; i < n; i++)
			printf("%12d",dp[i][s]);
		printf("%20d\n", s);
	}*/
	if(res >= INF) printf("-1\n"); 
	else printf("%d\n",res);
}

int main()
{
	while(scanf("%d%d",&n ,&m) != EOF)
		solve();
}
