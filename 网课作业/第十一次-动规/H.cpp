#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 200+5
int dp[maxn][maxn];
int fa[maxn],val[maxn];
bool solve[maxn]
int main()
{
	int m,n,a,b,lft;
	while(scanf("%d%d",&n,&m),n||m){
		memset(solve,false,sizeof(solve));
		memset(dp,0,sizeof(dp));
		solve[0]=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			fa[i]=a,val[i]=b;
		}
		for(int i=0;i<=n;i++) dp[i][m]=0; 
		lft=m;
		while(lft){
			for(int i=1;i<=n;i++){
				if(!solve[fa[i]]) continue;
				solve[i]=true;
				for(int j=1;j<=n;j++){
					if(j==i || !solve[j]) continue;
					for(int k=0;k<=m;k++)
						dp[i][k]=max(dp[i][k],dp[j][k+1])
				}
			}
		}
	}
}
