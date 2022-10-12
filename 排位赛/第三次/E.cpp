#include<cstdio>
using namespace std;
int main()
{
	int t;
	int lst[30]={1},res[30]={1};
	for(int i=1;i<=25;i++)
		lst[i]=lst[i-1]<<1;
	for(int i=0;i<=25;i++) lst[i]-=1;
	for(int i=1;i<=25;i++){
		t=lst[i]>>1;
		while(t>0){
			if(lst[i]%t==0){res[i]=t;break;}
			t--;
		}
	}
	int n,temp,dex;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		dex=0;
		while(lst[dex]<temp) dex++;
		if(lst[dex]!=temp) printf("%d\n",lst[dex]);
		else printf("%d\n",res[dex]);
	}
}
