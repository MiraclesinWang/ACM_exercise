#include <cstdio>
#include <cstring> 
#include <algorithm> 
using namespace std;
#define maxn 100000+5 
double num[maxn]; 
double sm[maxn];
int main()
{
	int n,k,m,t,k2;
	double tmp,res=0;
	scanf("%d%d%d",&n,&m,&k);
	double kk=k;
	for(int i=1;i<=n;i++) scanf("%lf",&num[i]);
	sort(num+1,num+1+n);
	tmp=0;
	for(int i=n;i>0;i--){
		tmp+=num[i];
		sm[i]=tmp;
	}
	for(int i=1;i<=n;i++){
		k2=k-(i-1);
		t=min((n-i+1)*m,k2);
		//printf("%d %d ",k2,t);
		tmp=t;
		//printf("%f\n",(tmp+sm[i])/(n-i+1));
		res=max(res,(tmp+sm[i])/(n-i+1));
	}
	printf("%f\n",res);
}
