#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1005
double dp[2*maxn][2*maxn];
//double pp[2*maxn][maxn];
int main()
{
	memset(dp,0,sizeof(dp));
	//memset(pp,0,sizeof(pp));
	double p1,p2;
	double p,q,res=0;
	int k;
	scanf("%d%lf%lf",&k,&p1,&p2);
	p=p1/(p1+p2),q=p2/(p1+p2);
	dp[0][0]=0,pp[0][0]=1;
	for(int i=1;i<=k;i++){
		dp[i][0]=0;
		pp[i][0]=pp[i-1][0]*q;
		for(int j=1;j<=i;j++){
			dp[i][j]=q*(dp[i-1][j]+j)+p*dp[i-1][j-1];
			pp[i][j]=q*pp[i-1][j]+p*pp[i-1][j-1];
		}
	}
	for(int i=1;i<=k;i++) res+=dp[k][i]*pp[k][i];
	printf("%.6f\n",res);
}
