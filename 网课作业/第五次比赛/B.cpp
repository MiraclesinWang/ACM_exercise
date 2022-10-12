#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double x[100005];
double y[100005];
int d[100005];
#define INF 1000000000
int main()
{
	int n,m,loc,hght,k,res;
	scanf("%d %d",&n,&m);
	for(int c=0;c<m;c++){
		scanf("%d%d",&loc,&hght);
		x[loc]=hght/loc,res=0;
        for(int i=1;i<=n;i++) y[i]=INF;
        for(int i=0;i<n;i++){
            k=lower_bound(y+1,y+1+n,x[i])-y;
            d[i]=k;
            y[k]=x[i];
            if(d[i]>res) res=d[i];
        }
        if(x[0]==0){
        	if(res>0) res--;
        	printf("%d\n",res);
		}
        else printf("%d\n",res);
	}
}
