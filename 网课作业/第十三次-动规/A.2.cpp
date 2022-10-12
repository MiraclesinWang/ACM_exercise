#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1000+5
double dp[maxn][maxn];
int main()
{
	memset(dp,0,sizeof(dp)); 
	int ss,nn;
	scanf("%d%d",&nn,&ss);
	double s=ss,n=nn;
	dp[ss][nn]=0;
	for(int ii=ss;ii>=0;ii--){
		for(int jj=nn;jj>=0;jj--){
			if(ii==ss && jj==nn) continue;
			double i=ii,j=jj;
			dp[ii][jj]=((s-i)*j*(dp[ii+1][jj]+1)+i*(n-j)*(dp[ii][jj+1]+1)+(s-i)*(n-j)*(dp[ii+1][jj+1]+1)+i*j)/(s*n-i*j);
		}
	}
	printf("%.4f\n",dp[0][0]);
}
