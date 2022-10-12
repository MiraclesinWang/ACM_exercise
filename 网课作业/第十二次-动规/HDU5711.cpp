#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 20000
int dp[1<<17+5][20];
int a[20],b[20];
int cnnct[20][20];
int res;
priority_queue <int> pq;
void init()
{
	res=0;
	memset(cnnct,-1,sizeof(cnnct));
	memset(dp,INF,sizeof(dp));
}
void tsp(int n)
{
	int dex,tmp;
	for(int i=1;i<=(1<<n)-1;i++){
		dex=1,now=1,tmp=i;
		while(tmp){
			if(tmp&1){
				if(cnnct[dex][i]>=0)
					dp[tmp][dex]=min(dp[tmp-now][dex]+cnnct[dex][i],dp[tmp][dex]);
			}
			dex+=1,now<<=1,tmp>>=1;
		}
	}
}
int cacu(int n)
{
	int dex=1;
	while(n){
		if(n&1)
	}
}
int main()
{
	int t,n,k,m,l,p,q,v;
	scanf("%d",&t);
	for(int c=1;c<=T;c++){
		scanf("%d%d%d%d",&n,&m,&k,&l);
		init();
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&p,&q,&v);
			cnnct[p][q]=cnnct[q][p]=min(v,cnnct[p][q]);
			if(p==0) dp[1<<(q-1)][q]=cnnct[p][q];
			if(q==0) dp[1<<(p-1)][p]=cnnct[p][q];
		}
		tsp(n);
		for(int i=1;i<=(1<<n)-1;i++)
			res=max(res,cacu(i));
	}
}
