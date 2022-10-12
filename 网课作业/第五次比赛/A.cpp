#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define maxn 250000+5
int fa[maxn];
int clr[maxn];
int main()
{
	int n,m,a,b,res;
	char t;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		fa[b]=a;
	}
	for(int i=1;i<=n;i++) clr[i]=1;   //1表示黑色，0表示红色 
	scanf("%d",&m);
	for(int i=1;i<=n;i++) printf("%d ",clr[i]);
	printf("\n");
	for(int i=1;i<=m;){
		scanf("\n%c",&t);
		if(t=='A'){
			scanf("%d%d",&a,&b);
			if(a>b) swap(a,b);
			clr[b]=(clr[b]==1?0:1);
		}
		else{
			scanf("%d",&a);
			res=0;
			while(fa[a]!=1) res+=clr[a],a=fa[a];
			res+=clr[a];
			printf("%d\n",res);
			i++;
		}
	}
}
