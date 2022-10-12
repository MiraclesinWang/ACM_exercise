#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1000+5
int dp[maxn][maxn][12];
char s1[maxn],s2[maxn];
//dp[i][j][k]=dp[i-1][j-1][k]+1 if(s1[i]==s2[j])
//dp[i][j][k]=dp[i-1][j-1][k-1]+1 if(s1[i]==s2[j])
int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m,k,l1,l2,res=0;
	scanf("%d%d%d",&n,&m,&k);
	scanf("\n%s\n%s",&s1,&s2);
	l1=strlen(s1),l2=strlen(s2);
	for(int i=l1;i>0;i--) s1[i]=s1[i-1];
	for(int i=l2;i>0;i--) s2[i]=s2[i-1];
	dp[0][0][0]=0;
	for(int i=1;i<=l1;i++) dp[i][0][0]=0;
	for(int i=1;i<=l2;i++) dp[0][i][0]=0; 
	/*for(int i=1;i<=l1;i++)
		dp[i][1][0]*/
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			dp[i][j][0]=0;
			if(s1[i]==s2[j]){
				for(int t=1;t<=k;t++){
					//printf("%d %d\n",dp[i-1][j-1][t],dp[i-1][j-1][t-1]);
					if(dp[i-1][j-1][t]>=0 && s1[i-1]==s2[j-1])
						dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t]+1);
					if(dp[i-1][j-1][t-1]>=0)
						dp[i][j][t]=max(dp[i][j][t],dp[i-1][j-1][t-1]+1);
					//printf("%d %d %d:%d\n",i,j,t,dp[i][j][t]);
				}
			}
			else
				for(int t=1;t<=k;t++)
					dp[i][j][t]=max(dp[i-1][j][t],dp[i][j-1][t]);
			res=max(res,dp[i][j][k]);
		}
	}
	printf("%d\n",res);
}
/*
10 10 2
accdacootg
accefdactg
*/
