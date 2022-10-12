#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define maxn 100000+5
int dfs[2*maxn],tree[8*maxn];
int u[2*maxn],v[2*maxn],to[maxn*2];
int chang[maxn];
int sn[maxn],t[maxn][2];
int color[maxn],cnt=0;
int dpt[maxn],st[maxn][20];
void addedge(int a,int b)
{
	u[++cnt]=a,v[cnt]=b;
	if(sn[a]){
		to[cnt]=sn[a];
		sn[a]=cnt;
	}
	else sn[a]=cnt;
}
void init()
{
	memset(sn,0,sizeof(sn));
	memset(chang,0,sizeof(chang));
}
void dfs_build(int dex,int fa,int dep)
{
	dfs[++cnt]=(color[dex]==color[fa]?0:1);
	t[dex][0]=cnt;
	dpt[dex]=dep;
	int lo=sn[dex];
	while(lo){
		if(v[lo]!=fa)
			st[v[lo]][0]=dex,
			dfs_build(v[lo],dex,dep+1);
		lo=to[lo];
	}
	dfs[++cnt]=-dfs[t[dex][0]];
	t[dex][1]=cnt;
}
int build(int l,int r,int dex)
{
	if(l==r) tree[dex]=color[++cnt];
	else if(l==r-1){
		build(l,l,dex*2),build(r,r,dex*2+1);
		tree[dex]=color[l]+color[r];
	}
	else{
		int mid=(l+r)/2;
		tree[dex]=build(l,mid,dex*2)+build(mid+1,r,2*dex+1);
	}
	return tree[dex];
}
void change(int l,int r,int x,int y,int t,int dex)
{
	if(l>=x && r<=y) chang[dex]=t,tree[dex]=1;
	else if(l>y || r<x) return;
	else{
		if(l==r-1) change(l,l,x,y,t,dex*2),change(r,r,x,y,t,dex*2+1);
		else{
			int mid=(l+r)/2;
			change(l,mid,x,y,t,dex*2),change(mid+1,r,x,y,t,dex*2+1);
		}
	}
}
void t_change(int x,int y)
{
	int fa=lca(x,y);
	if(t[x][0]>t[y][0]) swap(x,y);
	change(1,n,)
}
int lca(int x,int y)
{
	if(t[x][0]>t[y][0]) swap(x,y);
	if(t[x][1]<t[y][0]){
		if(dpt[x]>dpt[y]) swap(x,y);
		int t=19;
		while(t>=0){
			if((1<<t)<=dpt[y]-dpt[x]) y=st[y][t];
			t-=1;
		}
		t=19;
		while(t>=0){
			if(st[x][t]!=st[y][t]) x=st[x][t],y=st[y][t];
			t-=1;
		}
		return st[x][0];
	}
	else return x;
}
int query(int x,int y)
{
	int fa=lca(x,y);
}
int main()
{
	init();
	int n,m,a,b,v;
	char cmd;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&color[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);addedge(b,a);
	}
	cnt=0;
	dfs_build(1,1,1);
	cnt=0;
	build(1,n,1);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	while(scanf("%d%d",&a,&b)!=EOF) printf("%d\n",lca(a,b));
	/*cnt=0;
	for(int i=1;i<=m;i++){
		scanf("\n%c",&cmd);
		if(cmd=='C'){
			scanf("%d%d%d",&a,&b,&v);
			if(t[a][0]>t[b][0]) swap(a,b);
			if(t[a][1]<t[b][0]) change(t[a][1],t[b][0],++cnt);
			else change(1,n,t[a][0],t[b][0],++cnt,1),change(l,r,t[b][1],t[a][1],++cnt,1);
		}
		else{
			scanf("%d%d",&a,&b);
			if(t[a][0]>t[b][0]) swap(a,b);
			if(t[a][1]<t[b][0]) printf("%d\n",query(t[a][1],t[b][0]));
			else printf("%d\n",query(t[a][0],t[b][0]));			
		}
	}*/
}
