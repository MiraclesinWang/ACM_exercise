#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 200000+5
#define ll long long
ll dfs[maxn*2],val[maxn];
int cnt=0,sn[maxn],to[maxn],t[maxn][2],fa[maxn],c=0;
int leaf[maxn];
ll dis[maxn];
bool chose[maxn];
ll s[maxn*2];
void addedge(int a,int b)
{
	if(sn[a]) to[b]=sn[a];
	sn[a]=b,fa[b]=a;
}
void dfs_build(int dex)
{
	dfs[++cnt]=val[dex];
	t[dex][0]=cnt;
	int lo=sn[dex];
	while(lo){
		dfs_build(lo);
		lo=to[lo];
	}
	dfs[++cnt]=-val[dex];
	t[dex][1]=cnt;
}
void maintain(int d)
{
	int dex=leaf[d];
	dex=fa[dex];
	while(dex){
		for(int i=1;i<=c;i++){
			if(chose[i] && t[leaf[i]][0]>t[dex][0] && t[leaf[i]][0]<t[dex][1])
				dis[i]-=val[dex];
		}
		dex=fa[dex];
	}
}
int main()
{
	memset(chose,true,sizeof(chose));
	memset(to,0,sizeof(to));
	memset(sn,0,sizeof(sn));
	int n,k,a,b,d;
	ll res=0,sm=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)
		if(!sn[i]) leaf[++c]=i;
	if(k>=c){
		for(int i=1;i<=n;i++) res+=val[i];
		printf("%lld\n",res);
		return 0;
	}
	dfs_build(1);
	for(int i=1;i<=2*n;i++){
		sm+=dfs[i];
		s[i]=sm;
	}
	dis[0]=-1,fa[1]=0;
	for(int i=1;i<=c;i++)
		dis[i]=s[t[leaf[i]][0]];
	for(int i=1;i<=k;i++){
		d=0;
		for(int j=1;j<=c;j++)
			if(chose[j] && dis[j]>dis[d]) d=j;
		chose[d]=false;
		res+=dis[d];
		maintain(d);
	}
	printf("%lld\n",res);
}
