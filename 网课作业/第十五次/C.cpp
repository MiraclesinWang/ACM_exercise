#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1005
using namespace std;
struct h{
	int fa;
	int w,b;
	bool operator <(const h oth) {return fa<oth.fa;}
} hst[2*maxn];
int dp[maxn][maxn],fa[maxn];
int frt(int i) {
	if(fa[i]==i) return i;
	fa[i]=frt(fa[i]);
	return fa[i];
}
//{return  fa[i]==i?i:fa[i]=frt(fa[i]);}
int main()
{
	int n,m,w,x,y,dex=1,lo,tw=0,tb=0,d=1;
	int res=0;
	scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<=n;i++) fa[i]=i;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) scanf("%d",&hst[i].w);
	for(int i=1;i<=n;i++) scanf("%d",&hst[i].b);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		if(fa[x]==x) fa[x]=y;
		else if(fa[y]==y) fa[y]=x;
		else fa[frt(x)]=frt(y);
	}
	for(int i=1;i<=n;i++) frt(i);
	for(int i=1;i<=n;i++) hst[i].fa=fa[i];
	sort(hst+1,hst+1+n);
	lo=hst[1].fa,dex=n;
	for(int i=1;i<=n;i++){
		if(lo==hst[i].fa) tw+=hst[i].w,tb+=hst[i].b;
		else{
			hst[++dex].w=tw,hst[dex].b=tb;
			hst[dex].fa=lo;
			lo=hst[i].fa;
			tw=tb=0;
		}
	}
	hst[++dex].w=tw,hst[dex].b=tb;
	hst[dex].fa=lo;
	sort(hst+1,hst+1+dex);
	lo=hst[1].fa;
	for(int i=1;i<=dex;i++){
		if(hst[i].fa!=lo) lo=hst[i].fa,d+=1;
		if(hst[i].w>w) continue;
		dp[d][hst[i].w]=max(hst[i].b,dp[d][hst[i].w]);
		for(int j=1;j<=w;j++){
			dp[d][j]=max(dp[d][j],dp[d-1][j]);
			if(dp[d-1][j] && j+hst[i].w<=w)
				dp[d][j+hst[i].w]=max(dp[d][j+hst[i].w],dp[d-1][j]+hst[i].b);
		}
	}
	for(int i=1;i<=d;i++)
		for(int j=1;j<=w;j++)
			res=max(res,dp[i][j]);
	printf("%d\n",res);
	return 0;
 } 
