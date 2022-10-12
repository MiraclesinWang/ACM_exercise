#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 200000+5
int tree[8*maxn];
int t[maxn][2];
int u[2*maxn],v[2*maxn],to[2*maxn],sn[2*maxn];
int dfs[maxn*2];
int cnt,ctt,ll=1;
char cmd;
void init()
{
	memset(tree,0,sizeof(tree));
	memset(to,0,sizeof(to));
	memset(sn,0,sizeof(sn));
	cnt=ctt=0;
}
void addedge(int a,int b)
{
	u[++cnt]=a,v[cnt]=b;
	if(sn[a]){
		to[cnt]=sn[a];
		sn[a]=cnt;
	}
	else sn[a]=cnt;
}
void erect(int dex,int fa)
{
	int lo=sn[dex];
	dfs[++ctt]=1;
	t[dex][0]=ctt;
	while(lo){
		if(v[lo]==fa) {lo=to[lo];continue;}
		erect(v[lo],dex);
		lo=to[lo];
	}
	dfs[++ctt]=0;
	t[dex][1]=ctt;
}
void build(int l,int r,int dex)
{
	if(l==r) tree[dex]=dfs[ll++];
	else if(r==l+1)
		build(l,l,2*dex),build(r,r,2*dex+1),tree[dex]=tree[2*dex]+tree[2*dex+1];
	else{
		int mid=(l+r)>>1;
		build(l,mid,2*dex),build(mid+1,r,2*dex+1);
		tree[dex]=tree[2*dex]+tree[2*dex+1];
		//printf("%d %d:%d\n",l,r,tree[dex]);
	}	
}
void change(int l,int r,int dex,int x,int d)
{
	if(l<=x && r>=x){
		tree[dex]+=d;
		if(l==r-1) change(l,l,dex*2,x,d),change(r,r,dex*2+1,x,d);
		else if(l!=r){
			int mid=(l+r)/2;
			change(l,mid,dex*2,x,d),change(mid+1,r,dex*2+1,x,d);
		}
	}
}
int query(int l,int r,int dex,int x,int y)
{
	if(l>=x && r<=y) return tree[dex];
	else if(l>y || r<x) return 0;
	else{
		if(l==r-1) return query(l,l,2*dex,x,y)+query(r,r,2*dex+1,x,y);
		else{
			int mid=(l+r)/2;
			return query(l,mid,dex*2,x,y)+query(mid+1,r,dex*2+1,x,y);
		}
	}
}
int main()
{
	int n,a,b,m,tmp;
	init();
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b),addedge(b,a);
	}
	erect(1,1);
	cnt=1;
	build(1,2*n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("\n%c%d",&cmd,&tmp);
		if(cmd=='Q') printf("%d\n",query(1,2*n,1,t[tmp][0],t[tmp][1]-1));
		else{
			if(dfs[t[tmp][0]]==0){
				dfs[t[tmp][0]]=1;
				change(1,2*n,1,t[tmp][0],1);
			}
			else{
				dfs[t[tmp][0]]=0;
				change(1,2*n,1,t[tmp][0],-1);
			}
		}
	}
}
