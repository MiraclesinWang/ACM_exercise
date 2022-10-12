#include <cstdio>
#include <iostream>
using namespace std;
#define maxn 2*50000+5
int tree[maxn*4];
int p[maxn];
int cnt;
char cmd,tmp;
int build(int l,int r,int dex)
{
	if(l==r) {tree[dex]=p[cnt++];return tree[dex];}
	else if(l==r-1) {tree[dex]=build(l,l,2*dex)+build(r,r,2*dex+1);return tree[dex];}
	else{
		int mid=(l+r)/2;
		tree[dex]=build(l,mid,2*dex)+build(mid+1,r,2*dex+1);
		return tree[dex];
	}
}
int change(int l,int r,int dex,int t,int v)
{
	if(l<=t && r>=t){
		tree[dex]+=v;
		if(l==r) return 0;
		if(l==r-1) change(l,l,dex*2,t,v),change(r,r,2*dex+1,t,v); 
		else{
			int mid=(l+r)/2;
			change(l,mid,dex*2,t,v),change(mid+1,r,dex*2+1,t,v);
		}		
	}
}
int query(int l,int r,int dex,int x,int y)
{
	if(l>=x && r<=y) return tree[dex];
	else if(l>y || r<x) return 0;
	else{
		if(l==r-1) return query(l,l,dex*2,x,y)+query(r,r,dex*2+1,x,y);
		int mid=(l+r)/2;
		return query(l,mid,dex*2,x,y)+query(mid+1,r,dex*2+1,x,y);
	}
}
int main()
{
	int t,n,a,b;
	cin>>t;
	for(int kase=1;kase<=t;kase++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		cnt=1;
		printf("Case %d:\n",kase);
		build(1,n,1);
		while(scanf("\n%c",&cmd),cmd!='E'){
			//while(cin>>tmp,tmp>='a' && tmp<='z') continue;
			for(int i=1;i<=2;i++) scanf("%c",&tmp);
			if(cmd=='Q'){
				for(int i=1;i<=2;i++) scanf("%c",&tmp);
			}
			cin>>a>>b;
			//printf("%c %d %d\n",cmd,a,b);
			if(cmd=='Q') printf("%d\n",query(1,n,1,a,b));
			else if(cmd=='A') change(1,n,1,a,b);
			else if(cmd=='S') change(1,n,1,a,-b);
		}
		for(int i=1;i<=2;i++) scanf("%c",&tmp);
	}
 } 
