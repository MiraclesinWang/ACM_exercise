#include<cstdio>
#include<cmath>
using namespace std;
#define maxn 100000+5
#define ll long long
struct Node{
	ll value;
	int tms;
	ll &operator =(const ll l) {value=l;return value;}
};
ll dot[maxn];
Node tree[4*maxn];
ll build(int l,int r,int dex)        //线段树为某段区间的最小值所在的dex 
{
	tree[dex].tms=0;
	if(l==r) {tree[dex]=dot[l];return dot[l];}
	else if(r-l==1){
		tree[dex]=build(l,l,2*dex)+build(r,r,2*dex+1);
		//printf("%d %d %d\n",l,r,minn[dex]);
		return tree[dex].value;
	}
	else{
		int mid=(l+r)/2;
		tree[dex]=build(l,mid,2*dex)+build(mid+1,r,2*dex+1);
		//printf("%d %d %d\n",l,r,minn[dex]);
		return tree[dex].value;
	}
}
void change(int l,int r,int x,int y,int dex)          //l,r表示当前;x,y表示目标 
{
	if(x>y) return;
	if(l>=x && r<=y) tree[dex].tms+=1;
	else if(r<x || l>y) return;
	else{
		int mid=(l+r)/2;
		change(l,mid,x,y,2*dex);
		change(mid+1,r,x,y,2*dex+1);
	}
}
ll check(int l,int r,int x,int y,int dex)
{
	if(x>y) return 0;
	if(l>=x && r<=y) {
		for(int i=0;i<tree[dex].tms;i++)
			tree[dex].value=sqrt(tree[dex].value);
		tree[dex].tms=0;
		return tree[dex].value;
	}
	else if(r<x || l>y) return 0;
	else{
		int mid=(l+r)/2;
		tree[2*dex].tms+=tree[dex].tms,tree[2*dex+1].tms+=tree[dex].tms;
		tree[dex].tms=0;
		tree[dex].value=check(l,mid,x,y,2*dex)+check(mid+1,r,x,y,2*dex+1);
		return tree[dex].value;
	}
}
int main()
{
	int n,m,l,r,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&dot[i]);
	build(1,n,1);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&t,&l,&r);
		if(t==2){
			change(1,n,l,r,1);
			for(int i=1;i<2*n;i++) printf("%lld ",tree[i].value);
			printf("\n");
		}
		else printf("%lld\n",check(1,n,l,r,1));
	}
 } 
