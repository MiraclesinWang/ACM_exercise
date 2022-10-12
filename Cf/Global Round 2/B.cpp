#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
#define maxn 1005
int h[maxn],temp[maxn];
int main()
{
	int n,k,now=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=n;i++){
		now=0;
		for(int j=1;j<=i;j++) temp[j]=h[j];
		sort(temp+1,temp+i+1,greater<int>());
		for(int j=1;j<=i;j++){
			if(j%2==1) now+=temp[j];			
		}
		//printf("%d\n",now);
		if(now>k) {printf("%d\n",i-1);return 0;}	
	}
	printf("%d\n",n);
}
