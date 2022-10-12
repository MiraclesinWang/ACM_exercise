#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
double dp[maxn][maxn][maxn];
double re(double i,double j,double k)
{return i*j+j*k+i*k;}
int main()
{
	memset(dp,0,sizeof(dp));
	int r,s,p;
	double i,j,k;
	scanf("%d%d%d",&r,&s,&p);
	double rr=r,ss=s,pp=p;
	dp[r][s][p]=1;
	//dp[r][s][p]/=1-(rr*rr+ss*ss+pp*pp-rr-ss-pp)/(rr+ss+pp)/(rr+ss+pp-1);
	printf("%d %d %d: %f\n",r,s,p,dp[r][s][p]);
	for(int ii=r;ii>=0;ii--){
		for(int jj=s;jj>=0;jj--){
			for(int kk=p;kk>=0;kk--){
				if(r==ii && s==jj && kk==p) continue;
				if(!ii && !jj && !kk) continue;
				k=kk,i=ii,j=jj;
				if(ii<r) dp[ii][jj][kk]+=(i+1)*k/re(i+1,j,k)*dp[ii+1][jj][kk];
				if(jj<s) dp[ii][jj][kk]+=(j+1)*i/re(i,j+1,k)*dp[ii][jj+1][kk];
				if(kk<p) dp[ii][jj][kk]+=(k+1)*j/re(i,j,k+1)*dp[ii][jj][kk+1];
				/*if(ii+kk+jj>1)
					if(i*k>0 || i*j>0 || j*k>0)
						dp[ii][jj][kk]/=(1-(i*i+j*j+k*k-i-j-k)/(i+j+k)/(i+j+k-1));*/
				printf("%d %d %d: %f\n",ii,jj,kk,dp[ii][jj][kk]);
			}
		}
	}
	double res=0;
	for(int i=1;i<=r;i++) res+=dp[i][0][0];
	printf("%.8f ",res);
	res=0;
	for(int i=1;i<=s;i++) res+=dp[0][i][0];
	printf("%.8f ",res);
	res=0;
	for(int i=1;i<=p;i++) res+=dp[0][0][i];
	printf("%.8f\n",res);		
}
