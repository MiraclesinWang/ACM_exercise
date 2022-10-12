#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100000+5
#define ll long long
#define INF 0x3f3f3f3f
ll emt[maxn];
ll minn[4*maxn];
ll sm[maxn];
ll build(int l,int r,int dex)        //线段树为某段区间的最小值所在的dex 
{
	if(l==r) {minn[dex]=l;return emt[l];}
	else if(r-l==1){
		minn[dex]=(build(l,l,2*dex)<build(r,r,2*dex+1)?l:r);
		//printf("%d %d %d\n",l,r,minn[dex]);
		return emt[minn[dex]];
	}
	else{
		int mid=(l+r)/2;
		minn[dex]=(build(l,mid,2*dex)<build(mid+1,r,2*dex+1)?minn[2*dex]:minn[2*dex+1]);
		//printf("%d %d %d\n",l,r,minn[dex]);
		return emt[minn[dex]];
	}
}
int check(int l,int r,int x,int y,int dex)         //l,r表示当前;x,y表示目标 
{
	if(x>y) return 0;
	if(l>=x && r<=y) return minn[dex];
	else if(r<x || l>y) return 0;
	else{
		//printf("split\n");
		int mid=(l+r)/2;
		int a=check(l,mid,x,y,2*dex),b=check(mid+1,r,x,y,2*dex+1);
		return(emt[a]>emt[b]?b:a);
	}
}
void solve(int l,int r,ll* res,int split,int n,int *z,int *y)
{
	//printf("%d %d %d\n",l,r,split);
	if(l>r) return;
	else if(l==r){
		if(emt[l]*(sm[l]-sm[l-1])>*res)
			*res=emt[l]*(sm[l]-sm[l-1]),*z=l,*y=r;
	}
	else if(l==r-1){
		if((min(emt[l],emt[r]))*(sm[r]-sm[l-1])>*res)
			*res=(min(emt[l],emt[r]))*(sm[r]-sm[l-1]),*z=l,*y=r;
		if(emt[l]*emt[l]>*res) *res=emt[l]*emt[l],*z=l,*y=l;
		if(emt[r]*emt[r]>*res) *res=emt[r]*emt[r],*z=r,*y=r;
	}
	else{
		if((sm[r]-sm[l-1])*emt[split]>*res)
			*res=(sm[r]-sm[l-1])*emt[split],*z=l,*y=r;
		int dex=check(1,n,l,split-1,1);
		if(dex) solve(l,split-1,res,dex,n,z,y);
		dex=check(1,n,split+1,r,1);
		if(dex) solve(split+1,r,res,dex,n,z,y);
	}
}
int main()
{
	int n,dex;
	ll* res=new ll;
	int *x=new int;
	int *y=new int;
	scanf("%d",&n);
	*res=0,*x=1,*y=n;
	for(int i=1;i<=n;i++) scanf("%lld",&emt[i]),*res+=emt[i],sm[i]=*res;
	sm[0]=0,minn[0]=INF,emt[0]=INF;
	build(1,n,1);
	dex=minn[1],*res=sm[n]*emt[dex];
	solve(1,n,res,dex,n,x,y);
	printf("%lld\n%d %d\n",*res,*x,*y);
 } 
