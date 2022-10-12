#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 100000+10
#define ll long long
const ll mod=1e9+7;
ll dp[15][maxn];
ll sm[15][maxn];
//ll pre[maxn],now[maxn];
int main()
{
	int m,n,k;
	ll res=0;
	scanf("%d%d%d",&n,&k,&m);
	memset(dp[1],1,sizeof(dp[1]));
	for(int i=1;i<=n;i++)
		sm[1][i]=(ll)i;
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(j-m<=1) dp[i][j]=sm[i-1][n];
			else{
				dp[i][j]=sm[i-1][n]-sm[i-1][j-m-1];
				if(dp[i][j]<0) dp[i][j]+=mod;
			}
			if(j==1) sm[i][j]=dp[i][j];
			else sm[i][j]=(sm[i][j-1]+dp[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++) res+=dp[k][i];
	printf("%lld\n",res);
}
