#include<cstdio>
#include<string>
using namespace std;
int left(int i,int p,int q,int n) {return (i*p+q)%n+1;}
int right(int i,int p,int q,int n) {return (i*q+p)%n+1;}
int flower[1000010];
int trans[1000010]={0};
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int n,m,p,q,l,r,count=0;
	scanf("%d %d %d %d",&n,&m,&p,&q);
	for(int i=m;i>0;i--){
		if(count==m) break;
		l=left(i,p,q,n),r=right(i,p,q,n);
		if(l>r) swap(l,r);
		if(r>n) r=n;
		if(l<1) l=1;
		while(l<=r){
			if(trans[l]==0) flower[l]=i,trans[l]=r+1,l++,count++;
			else l=trans[l];
		}
	}
	for(int i=1;i<=n;i++) printf("%d\n",flower[i]);
}
