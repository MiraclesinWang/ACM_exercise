#include<cstdio>
using namespace std;
#define maxn 300000+5
int clr[maxn];
int main()
{
	int n,l,r,temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&clr[i]);
	l=1,r=n,temp=clr[1];
	if(clr[l]!=clr[r]) printf("%d\n",n-1);
	else{
		while(r-l>1){
			if(clr[l+1]==temp && clr[r-1]==temp) r--,l++;
			else if(clr[l+1]!=temp) {printf("%d\n",n-l-1);return 0;}
			else {printf("%d\n",r-2);return 0;}
		}
	}
}
