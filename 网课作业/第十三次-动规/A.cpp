#include<cstdio>
#include<cstring>
using namespace std;
double dp[1005][1005];
int main()
{
	memset(dp,0,sizeof(dp));
	int ss,nn;
	double i,j;
	scanf("%d%d",&ss,&nn);
	double s=ss,n=nn;
	dp[ss][nn]=0;
	for(int ii=ss;ii>=0;ii--){
		for(int jj=nn;jj>=0;jj--){
			if(ii==ss && jj==nn) continue;
			i=ii,j=jj;
			//dp[ii][jj]=(i*(s-j)*dp[ii][jj+1]+(n-i)*j*dp[ii+1][jj]+(n-i)*(s-j)*dp[ii+1][jj+1]+n*s)/(n*s-i*j);
			//printf("%f\n",dp[ii][jj]);
			dp[ii][jj]=(n*s+(n-i)*j*dp[ii+1][jj]+i*(s-j)*dp[ii][jj+1]+(n-i)*(s-j)*dp[ii+1][jj+1])/(n*s-i*j );
		}
	}
	printf("%.4f\n",dp[0][0]);
 } 
