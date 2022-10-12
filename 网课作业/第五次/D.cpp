#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
#define maxn 50000+5
#define INF 0x3f3f3f3f
struct Node{
	int h,w;
	int dex;
};
//int hgt[maxn],wdth[maxn];
Node s[maxn];
int sm[maxn]={0};
int minn[4*maxn]={INF,0};
int build(int l,int r,int dex)        //线段树为某段区间的最小值所在的dex 
{
	if(l==r) {minn[dex]=l;return s[l].h;}
	else if(r-l==1){
		minn[dex]=(build(l,l,2*dex)<build(r,r,2*dex+1)?l:r);
		return s[minn[dex]].h;
	}
	else{
		int mid=(l+r)/2;
		minn[dex]=(build(l,mid,2*dex)<build(mid+1,r,2*dex+1)?minn[2*dex]:minn[2*dex+1]);
		//printf("%d %d %d\n",l,r,minn[dex]);
		return s[minn[dex]].h;
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
		return(s[a].h>s[b].h?b:a);
	}
}
void solve(int l,int r,int *res,int split,int n)
{
	//printf("%d %d %d\n",l,r,split);
	if(l>r) return;
	else if(l==r){
		if(s[l].h*s[l].w>*res)
			*res=s[l].w*s[l].h;
	}
	else if(l==r-1){
		if(min(s[l].h,s[r].h)*(s[l].w+s[r].w)>*res)
			*res=min(s[l].h,s[r].h)*(s[l].w+s[r].w);
		if(s[l].h*s[l].w>*res) *res=s[l].h*s[l].w;
		if(s[r].h*s[r].w>*res) *res=s[r].h*s[r].w;
	}
	else{
		if(s[split].h*(sm[r]-sm[l-1])>*res) *res=s[split].h*(sm[r]-sm[l-1]);
		int dex=check(1,n,l,split-1,1);
		if(dex && split>=2) solve(l,split-1,res,dex,n);
		dex=check(1,n,split+1,r,1);
		if(dex && split<=n-1) solve(split+1,r,res,dex,n);
	}
}
int main()
{
	s[0].h=INF;
	int* res=new int;
	int n,w,h,temp=0,dex;
	while(scanf("%d",&n),n!=-1){
		temp=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&w,&h);
			s[i].dex=i,s[i].h=h,s[i].w=w;
			temp+=w,sm[i]=temp;
		}
		build(1,n,1);
		dex=minn[1],*res=sm[n]*s[dex].h;
		solve(1,n,res,dex,n);
		printf("%d\n",*res);
	}
 } 
