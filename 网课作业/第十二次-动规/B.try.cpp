#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[35][35][2];     //第几位，1的个数，选0还是1 
int a[35],b[35];
int m,n;
int cacu(int n)
{
	int res=0;
	int cnt[35]={0};
	int num[35]={0},dex=1,tmp=n;
	while(tmp){
		if(tmp&1) num[dex]=1;
		dex+=1,tmp>>=1;
	}
	dex-=1;
	printf("dex:%d\n",dex);
	tmp=1;
	for(int i=dex-1;i>0;i--){
		cnt[i]=tmp;
		if(num[i]) tmp+=1;		
	}
	if(tmp<=dex/2) res+=1; 
	for(int i=1;i<=dex;i++) cout<<cnt[i]<<" ";
	printf("\n");
	printf("-------\n");
	for(int i=1;i<dex;i++){
		if(num[i]){
			for(int j=cnt[i];j<=dex/2;j++)
				cout<<dp[i][j-cnt[i]][0]<<endl,
				res+=dp[i][j-cnt[i]][0];
		}
	}
	printf("-------\n");
	printf("%d\n",res);
	printf("----------\n");
	printf("%d\n",dex);
	for(int i=1;i<=dex-1;i++){
		for(int j=0;j<=i/2;j++)
			printf("%d ",dp[i][j][1]),res+=dp[i][j][1];
		printf("\n");
	}
	return res;
}
int main()
{
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	dp[1][0][0]=1;
	dp[1][1][1]=1;
	for(int i=2;i<=32;i++){
		dp[i][0][0]=dp[i-1][0][0];
		for(int j=1;j<=32;j++)
			dp[i][j][1]+=dp[i-1][j-1][1]+dp[i-1][j-1][0],
			dp[i][j][0]+=dp[i-1][j][1]+dp[i-1][j][0];
			//dp[i][j]+=dp[i-1][j-1]+dp[i-1][j];
	}
	/*for(int i=0;i<=5;i++){
		for(int j=1;j<=5;j++) printf("%d ",dp[j][i][0]);
		printf("\n");
	}
	printf("-----------------------\n");
	for(int i=0;i<=5;i++){
		for(int j=1;j<=5;j++) printf("%d ",dp[j][i][1]);
		printf("\n");
	}*/
	//scanf("%d%d",&m,&n);
	//cout<<cacu(n)<<" "<<cacu(m-1)<<endl;
	cout<<cacu(31);
	/*for(int i=1;i<=50;i++)
		printf("%d:%d\n",i,cacu(i));*/
}
