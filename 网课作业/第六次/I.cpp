#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
#define maxn 100000+5
ll mod;
struct Node{
	ll mtply,tms;
	ll val;
};
Node tree[4*maxn];
ll num[maxn];
void push_down(int dex,int l,int r,int mid)
{
	ll m=tree[dex].mtply,t=tree[dex].tms;
	tree[2*dex].mtply*=m,tree[2*dex+1].mtply*=m;
	tree[2*dex].mtply%=mod,tree[2*dex+1].mtply%=mod;
	tree[2*dex].tms*=m,tree[2*dex+1].tms*=m;
	tree[2*dex].tms+=t,tree[2*dex+1].tms+=t;	
	tree[2*dex].tms%=mod,tree[2*dex+1].tms%=mod;
	tree[2*dex].val*=m,tree[2*dex+1].val*=m;
	tree[2*dex].val+=t*(mid-l+1),tree[2*dex+1].val+=t*(r-mid);
	tree[2*dex].val%=mod,tree[2*dex+1].val%=mod;
	tree[dex].tms=0,tree[dex].mtply=1;	
}
ll build(int l,int r,int dex)
{
	tree[dex].tms=0,tree[dex].mtply=1;
	if(l==r) {tree[dex].val=num[l];return num[l];}
	else if(r-l==1){
		tree[dex].val=build(l,l,2*dex)+build(r,r,2*dex+1);
		return tree[dex].val;
	}
	else{
		int mid=(l+r)/2;
		tree[dex].val=build(l,mid,2*dex)+build(mid+1,r,2*dex+1);
		//printf("%d %d %lld %lld %lld\n",l,r,tree[dex].tms,tree[dex].mtply,tree[dex].val);
		return tree[dex].val;
	}
}
void change1(int l,int r,int x,int y,int dex,ll value)          //l,r表示当前;x,y表示目标 
{
	if(l>=x && r<=y) tree[dex].tms+=value,tree[dex].val=(tree[dex].val+(r-l+1)*value)%mod;
	else if(r<x || l>y) return;
	else{
		int mid=(l+r)/2;
		push_down(dex,l,r,mid);
		change1(l,mid,x,y,2*dex,value);
		change1(mid+1,r,x,y,2*dex+1,value);
		tree[dex].val=(tree[2*dex].val+tree[2*dex+1].val)%mod;
		//printf("%d %d %lld %lld %lld\n",l,r,tree[dex].tms,tree[dex].mtply,tree[dex].val);
	}
}
void change2(int l,int r,int x,int y,int dex,ll value)          //l,r表示当前;x,y表示目标 
{
	if(l>=x && r<=y)
		tree[dex].tms*=value,tree[dex].mtply*=value,
		tree[dex].tms%=mod,tree[dex].mtply%=mod,
		tree[dex].val*=value,tree[dex].val%=mod;
		//printf("%d %d %lld %lld %lld\n",l,r,tree[dex].tms,tree[dex].mtply,tree[dex].val);
	else if(r<x || l>y) return;
	else{
		int mid=(l+r)/2;
		push_down(dex,l,r,mid);
		change2(l,mid,x,y,2*dex,value);
		change2(mid+1,r,x,y,2*dex+1,value);
		tree[dex].val=(tree[2*dex].val+tree[2*dex+1].val)%mod;
		//printf("%d %d %lld %lld %lld\n",l,r,tree[dex].tms,tree[dex].mtply,tree[dex].val);
	}
}
ll check(int l,int r,int x,int y,int dex)
{
	if(l>=x && r<=y) return tree[dex].val;
	else if(r<x || l>y) return (ll)0;
	else{
		int mid=(l+r)/2;
		push_down(dex,l,r,mid);
		ll res=(check(l,mid,x,y,2*dex)+check(mid+1,r,x,y,2*dex+1))%mod;
		tree[dex].val=(tree[dex*2].val+tree[2*dex+1].val)%mod;
		//printf("%d %d %lld %lld %lld\n",l,r,tree[dex].tms,tree[dex].mtply,tree[dex].val);
		return res;
	}
}
int main()
{
	int n,m,s,e,tpy;
	ll v;
	scanf("%d%lld",&n,&mod);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tpy,&s,&e);
		if(tpy==3) printf("%lld\n",check(1,n,s,e,1));
		else{
			scanf("%lld",&v);
			if(tpy==2) change1(1,n,s,e,1,v);
			else change2(1,n,s,e,1,v);
		}
	}
}
