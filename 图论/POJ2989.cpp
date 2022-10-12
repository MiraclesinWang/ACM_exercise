#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 130;
#define rep(i, x, y) for(int i = x; i < y; i++)
bool mp[maxn][maxn];
int m, n, res;
int all[maxn][maxn], nn[maxn][maxn], sm[maxn][maxn];

void dfs(int d)
{
	if(!sm[d][0] && !nn[d][0]) {res++;return;}
	int first = sm[d][1];
	rep(i, 1, sm[d][0]+1){
		if(res > 1000) break;
		int v = sm[d][i];
		if(mp[v][first]) continue;
		rep(j, 0, all[d][0]+1) all[d+1][j] = all[d][j];
		all[d+1][++all[d+1][0]] = v;
		
		sm[d+1][0] = nn[d+1][0] = 0;
		rep(j, 1, sm[d][0]+1) 
			if(mp[v][sm[d][j]]) sm[d+1][++sm[d+1][0]] = sm[d][j];
		rep(j, 1, nn[d][0]+1)
			if(mp[v][nn[d][j]]) nn[d+1][++nn[d+1][0]] = nn[d][j];
		dfs(d+1);
		nn[d][++nn[d][0]] = v, sm[d][i] = 0;
	}
	
}

int main()
{
	while(~scanf("%d%d", &n,&m)){
		int a, b;
		memset(mp, 0, sizeof(mp));
		memset(all, 0, sizeof(all));
		memset(nn, 0, sizeof(nn));
		memset(sm ,0, sizeof(sm));
		rep(i, 0, m) scanf("%d%d", &a, &b), mp[a][b] = mp[b][a] = 1;
		
		res = 0;
		sm[0][0] = n;
		rep(i, 1, n+1) sm[0][i] = i;
		dfs(0);
		if(res <= 1000) printf("%d\n", res);
		else printf("Too many maximal sets of friends.\n");
	}
	
}


