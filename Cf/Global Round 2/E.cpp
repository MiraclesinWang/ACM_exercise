#include<cstdio>
using namespace std;
#define maxn 300000+5
int s[maxn],two[maxn],one[maxn];
int main()
{
	int n,r1=0,r2=0,l1=0,l2=0;
	long long res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=n;i>0;i--){
		res+=(long long)(s[i]/3);
		if(s[i]%3==2) two[r2++]=i;
		else if(s[i]%3==1) one[r1++]=i;
	}
	while(l1<r1 && l2<r2){
		while(l1<r1 && one[l1]>two[l2]) l1++;
		if(l1<r1) res++,l1++,l2++;
	}
	while(l2<r2){
		if(l2+2<r2) res++,res++,r2-=2;
		else break;
	}
	if(r2-l2==2){
		for(int i=two[l2];i>0;i--)
			if(s[i]>=3) {res++;break;}
	}
	printf("%lld\n",res);
}
