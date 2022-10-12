#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 200000+5
int s[maxn],tree[4*maxn],cnt;
int build(int l,int r,int dex)
{
	if(l==r) tree[dex]=s[++cnt];
	else if(l==r-1) tree[dex]=max(build(l,l,2*dex),build(r,r,2*dex+1));
	else{
		int mid=(l+r)/2;
		tree[dex]=max(build(l,mid,2*dex),build(mid+1,r,2*dex+1));
	} 
	return tree[dex];
}
void change(int l,int r,int x,int dex,int v)
{
	if(l<=x && r>=x){
		tree[dex]=max(v,tree[dex]);
		if(l==r-1) change(l,l,x,dex*2,v),change(r,r,x,2*dex+1,v);
		else if(l!=r){
			int mid=(l+r)/2;
			change(l,mid,x,2*dex,v),change(mid+1,r,x,2*dex+1,v);
		}
	}
}
int query(int l,int r,int x,int y,int dex)
{
	if(l>=x && r<=y) return tree[dex];
	else if(l>y || r<x) return 0;
	else{
		if(l==r-1) return max(query(l,l,x,y,dex*2),query(r,r,x,y,2*dex+1));
		else{
			int mid=(l+r)/2;
			return max(query(l,mid,x,y,dex*2),query(mid+1,r,x,y,2*dex+1));
		}
	}
}
int main()
{
	int n,m,a,b;
	char cmd;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		cnt=0;
		build(1,n,1);
		for(int i=0;i<m;i++){
			scanf("\n%c%d%d",&cmd,&a,&b);
			if(cmd=='U') change(1,n,1,a,b);
			else printf("%d\n",query(1,n,a,b,1));
		}
	}
}
