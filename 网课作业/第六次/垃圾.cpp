#include<cstdio>
#include<cmath>
using namespace std;
#define maxn 20+2
int n,k;
int num[maxn];
int dex[maxn]={0};
bool IsPrime(int n)
{
	if (n == 2)return true;
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0) return false;
	return true;
}
void advance(int temp,int d,int *res)
{
	printf("%d ",temp);
	if(IsPrime(temp)) *res+=1;
	if (dex[1]==n-k+1) return;
	if(dex[d]==n-k+d)
		temp-=num[dex[d-1]],dex[d-1]+=1,temp+=num[dex[d-1]],advance(temp,d-1,res);
	else
		temp-=num[dex[d]],dex[d]+=1,temp+=num[dex[d]],advance(temp,d,res);
}
int main()
{
	int temp=0;
	int *res = new int;
	*res=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=k;i++) temp+=num[i],dex[i]=i;
	advance(temp,k,res);
	printf("%d\n",*res);
}
