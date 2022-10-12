#include<iostream>
using namespace std;
#define maxn 1000+5
int cnt[maxn]={0}; 
int main()
{
	bool can=true;
	ios::sync_with_stdio(false);
	int k,m,tmp,dex=0,rdex=0;
	cin>>k>>m;
	for(int i=1;i<=m;i++)
		cin>>tmp,cnt[tmp]+=1;
	if(cnt[1]==cnt[2]) tmp=cnt[1];
	else if(cnt[1]==cnt[3]) tmp=cnt[1];
	else if(cnt[2]==cnt[3]) tmp=cnt[2];
	else {printf("*\n");return 0;}
	for(int i=1;i<=k;i++){
		if(cnt[i]!=tmp){
			if(cnt[i]-tmp>1 || cnt[i]-tmp<-1) {printf("*\n");return 0;}
			if(dex==0) dex=i;
			else if(!can) {printf("*\n");return 0;}
			else if(cnt[i]+cnt[dex]==tmp*2) rdex=i,can=false;
			else {printf("*\n");return 0;}
		}
	}
	if(rdex!=0){
		if(cnt[dex]<tmp) printf("-%d +%d\n",rdex,dex);
		else printf("-%d +%d\n",dex,rdex);
	}
	else{
		if(cnt[dex]<tmp) printf("+%d\n",dex);
		else printf("-%d\n",dex);
	}
}
