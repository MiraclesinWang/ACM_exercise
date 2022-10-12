#include<cstdio>
#include<cstring>
#include<iostream>
const long long mod=1e9;
#define ll long long
using namespace std;
int m,n;
ll dp[15][15],fld[15][15];
ll cpy[15][15];
void recur(int k,int cnt,ll dp[15][15],ll cpy[15][15],ll *res){
	if(k>cnt) return;
	cpy[1][1]=0;
	for(int i=2;i<=m;i++)
		cpy[i][1]=(fld[i-1][1]?cpy[i-2][1]:dp[i-1][1]);
	for(int i=2;i<=n;i++)
		cpy[1][i]=(fld[1][i-1]?dp[1][i-2]:dp[1][i-1]);
	for(int i=2;i<=m;i++){
		for(int j=2;j<=n;j++){
			if(!fld[i][j]){
				cpy[i][j]=(cpy[i-1][j]+cpy[i][j-1]-cpy[i-1][j-1]);
				if(cpy[i][j]<0) cpy[i][j]=0;
				cpy[i][j]%=mod;				
			}
			else{
				cpy[i][j]=(dp[i-2][j]+dp[i][j-2]-dp[i-2][j-1]-dp[i-1][j-2]+dp[i-1][j-1]);
				if(cpy[i][j]<0) cpy[i][j]=0;
				cpy[i][j]%=mod;
			}
		}
	}
	*res+=cpy[m][n];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) printf("%10lld",cpy[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	recur(k+1,cnt,cpy,dp,res);
}
int main()
{
	ll * ans=new ll;
	*ans=1;
	memset(dp,0,sizeof(dp));
	memset(cpy,0,sizeof(cpy));
	int res=1,tmp,cnt;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>dp[i][j];
			fld[i][j]=dp[i][j];
			if(dp[i][j]) *ans+=1;
		}
	}
	for(int i=1;i<=m;i++){
		tmp=0;
		for(int j=1;j<=n;j++){
			tmp+=dp[i][j];
			dp[i][j]=tmp;
		}
	}
	for(int j=1;j<=n;j++){
		tmp=0;
		for(int i=1;i<=m;i++){
			tmp+=dp[i][j];
			dp[i][j]=tmp;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) printf("%10lld",dp[i][j]);
		printf("\n");
	}
	printf("----------------------------\n");
	cnt=*ans-1;
	recur(2,cnt,dp,cpy,ans);
	printf("%d\n",*ans);
}
