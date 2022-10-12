#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 200000+5
/*用sum(s)作为数组的dex，记录的是对应的sum(f)*/ 
int dp[maxn];
int f[105],s[105];
int change_d[maxn],change_v[maxn];
int dex[maxn];
int cnt=0;
int main()
{
	memset(dp,-1,sizeof(dp));
	ios::sync_with_stdio(false);
	int n,tmp,res=0,c;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]>>f[i];
	dp[100000]=0,dex[++cnt]=100000;
	for(int i=1;i<=n;i++){
		tmp=cnt,c=0;
		for(int j=1;j<=tmp;j++){
			//printf("%d %d->",dex[j]-100000,dp[dex[j]]);
			if(dp[dex[j]+s[i]]!=-1){
				if(dp[dex[j]+s[i]]<dp[dex[j]]+f[i])
					change_d[++c]=dex[j]+s[i],change_v[c]=dp[dex[j]]+f[i];			
			}
			else dex[++cnt]=dex[j]+s[i],dp[dex[j]+s[i]]=dp[dex[j]]+f[i];
			//printf("%d %d\n",dex[j]+s[i]-100000,dp[dex[j]+s[i]]);
		}
		for(int j=1;j<=c;j++) dp[change_d[j]]=change_v[j];
	}
	for(int i=1;i<=cnt;i++)
		if(dex[i]>=100000 && dp[dex[i]]>=0)
			res=max(res,dp[dex[i]]+dex[i]-100000);
	cout<<res<<endl;
 } 
