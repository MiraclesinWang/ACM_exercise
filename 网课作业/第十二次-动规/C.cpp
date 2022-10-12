#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
int cnct[12][12];
int dp[1<<12+5][12];
int n;
int can[12];
void tsp()
{
	int tmp,dex,len;
	tmp=2;
	for(int i=1;i<=n;i++){
		dp[tmp][i]=cnct[0][i];
		tmp<<=1;
	}
	for(int i=1;i<=(1<<(n+1))-1;i++){
		tmp=i,dex=0,len=0;
		while(tmp){
			if(tmp&1) can[len++]=dex;
			tmp>>=1,dex++;
		}
		for(int j=0;j<len;j++)
			for(int k=0;k<len;k++)
				//printf("%d %d %d\n",dp[i][can[j]],dp[i-(1<<can[j])][can[k]],cnct[can[k]][can[j]]),
				dp[i][can[j]]=min(dp[i-(1<<can[j])][can[k]]+cnct[can[k]][can[j]],dp[i][can[j]]);			
		for(int k=1;k<=len;k++)
			for(int j=0;j<len;j++)
				for(int p=0;p<len;p++)
					dp[i][can[j]]=min(dp[i][can[j]],dp[i][can[p]]+cnct[can[p]][can[j]]);	
	}
}
int main()
{
	while(scanf("%d",&n),n){
		memset(dp,INF,sizeof(dp));
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				scanf("%d",&cnct[i][j]);
		tsp();
		cout<<dp[(1<<(n+1))-1][0]<<endl;		
	}
}
