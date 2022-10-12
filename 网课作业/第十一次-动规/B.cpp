#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
#define maxn 45000+5
bool dp[maxn];
int w[maxn],dex[maxn];
int cnt=0;
int main()
{
	ios::sync_with_stdio(false);
	memset(dp,false,sizeof(dp));
	int n,tmp,ldex,sm=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i],sm+=w[i];
	dp[0]=true;dex[++cnt]=0;
	for(int i=1;i<=n;i++){
		tmp=cnt;
		for(int j=1;j<=tmp;j++)
			if(!dp[dex[j]+w[i]]) dp[dex[j]+w[i]]=true,dex[++cnt]=dex[j]+w[i];
	}
	if(sm%2) ldex=sm/2;
	else ldex=sm/2;
	while(true){
		if(dp[ldex]) {printf("%d %d\n",ldex,sm-ldex);break;}
		ldex--;
	}
}
