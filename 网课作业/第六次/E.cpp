#include<cstdio>
using namespace std;
#define ll long long
#define maxn 100000+5
struct Node{
	ll value;
	ll tms;
};
Node tree[4*maxn];
ll num[maxn];
ll build(int l,int r,int dex)
{
	tree[dex].tms=0;
	if(l==r) {tree[dex].value=num[l];return num[l];}
	else if(r-l==1){
		tree[dex].value=build(l,l,2*dex)+build(r,r,2*dex+1);
		return tree[dex].value;
	}
	else{
		int mid=(l+r)/2;
		tree[dex].value=build(l,mid,2*dex)+build(mid+1,r,2*dex+1);
		return tree[dex].value;
	}
}
void change(int l,int r,int x,int y,int dex,ll value)          //l,r表示当前;x,y表示目标 
{
	if(x>y) return;
	if(l>=x && r<=y) tree[dex].tms+=value,tree[dex].value+=value*(r-l+1);
	else if(r<x || l>y) return;
	else{
		int mid=(l+r)/2;
		tree[2*dex].tms+=tree[dex].tms,tree[2*dex+1].tms+=tree[dex].tms;
		tree[2*dex].value+=tree[dex].tms*(mid-l+1);
		tree[2*dex+1].value+=tree[dex].tms*(r-mid);
		tree[dex].tms=0;
		change(l,mid,x,y,2*dex,value);
		change(mid+1,r,x,y,2*dex+1,value);
		tree[dex].value=tree[2*dex].value+tree[2*dex+1].value;
	}
}
ll check(int l,int r,int x,int y,int dex)
{
	if(l>=x && r<=y) return tree[dex].value;
	else if(r<x || l>y) return (ll)0;
	else{
		int mid=(l+r)/2;
		tree[2*dex].tms+=tree[dex].tms,tree[2*dex+1].tms+=tree[dex].tms;
		tree[2*dex].value+=tree[dex].tms*(mid-l+1);
		tree[2*dex+1].value+=tree[dex].tms*(r-mid);
		tree[dex].tms=0;
		ll res=check(l,mid,x,y,2*dex)+check(mid+1,r,x,y,2*dex+1);
		tree[dex].value=tree[dex*2].value+tree[2*dex+1].value;
		return res;
	}
}
int main()
{
	int n,q,s,e;
	ll v;
	char typ;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
	build(1,n,1);
	for(int i=1;i<=q;i++){
		scanf("\n%c%d%d",&typ,&s,&e);
		if(typ=='C'){
			scanf("%lld",&v);
			change(1,n,s,e,1,v);
		}
		else printf("%lld\n",check(1,n,s,e,1));
	}
}
