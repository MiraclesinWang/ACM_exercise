#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1500+5 
int sn[maxn][11],fa[maxn],sn_cnt[maxn],dp[maxn][2];
void init()
{
	memset(sn_cnt,0,sizeof(sn_cnt));
	memset(sn,0,sizeof(sn));
	memset(fa,-1,sizeof(fa));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<maxn;i++) dp[i][1]=1;
}
void recur(int dex)
{
	if(!sn_cnt[dex]) return;
	for(int i=0;i<sn_cnt[dex];i++){
		recur(sn[dex][i]);
		//printf("%d %d %d\n",sn[dex][i],dp[sn[dex][i]][0],dp[sn[dex][i]][1]);
		dp[dex][0]+=dp[sn[dex][i]][1];
		dp[dex][1]+=min(dp[sn[dex][i]][0],dp[sn[dex][i]][1]);
	}
}
int main()
{
	int n,dex,s,cnt,rt;
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d:(%d)",&dex,&cnt);
			sn_cnt[dex]=cnt;
			for(int j=0;j<cnt;j++)
				scanf("%d",&sn[dex][j]),fa[sn[dex][j]]=dex;
		}
		for(int i=0;i<n;i++)
			if(fa[i]==-1) rt=i;
		recur(rt);
		/*for(int i=0;i<n;i++) printf("%d ",dp[i][0]);
		printf("\n");
		for(int i=0;i<n;i++) printf("%d ",dp[i][1]);
		printf("\n");*/
		printf("%d\n",min(dp[rt][0],dp[rt][1]));
	}
}
