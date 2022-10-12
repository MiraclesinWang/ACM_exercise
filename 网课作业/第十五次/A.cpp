#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 20;
const int maxm = 8*17+10;
int dp[20][1<<16+5];
int cnct[maxn][maxn];
struct dot{
	int a,b;
	bool operator <(const dot &oth) const{return a>oth.a;}
} d[maxn];
priority_queue <dot> pq;
int n,m,k,l;
void solve()
{
	int a,b,c;
	scanf("%d%d%d%d",&n,&m,&k,&l);
	memset(cnct,0,sizeof(cnct));
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++) scanf("%d",&d[i].a);
	for(int i=1;i<=n;i++) scanf("%d",&d[i].b);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a,&b,&c),
		cnct[a][b]=cnct[b][a]=c;
	dp[0][0]=l;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++) solve();
}
