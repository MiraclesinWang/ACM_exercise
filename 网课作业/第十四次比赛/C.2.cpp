#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::sort;
const int MAXN=1e3+10;
int fa[MAXN];
int dp[MAXN][MAXN]; 
int frt(int n){return n==fa[n]?n:fa[n]=frt(fa[n]);}
struct hos{
	int w,b,fa;
	bool operator <(const hos& oth){return fa<oth.fa;}
} h[MAXN<<1];
void init(int n)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	memset(dp,0,sizeof(dp));	
}
int main()
{
	int n,m,w,x,y,res=0;
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i].w);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i].b);
	init(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(fa[x]==x) fa[x]=y;
		else if(fa[y]==y) fa[y]=x;
		else fa[frt(x)]=frt(y);
	}
	for(int i=1;i<=n;i++) frt(i);
	for(int i=1;i<=n;i++) h[i].fa=fa[i];
	sort(h+1,h+1+n);
	int now=h[1].fa,tw=0,tb=0,dex=n+1;
	for(int i=1;i<=n;i++){
		if(now==h[i].fa) tw+=h[i].w,tb+=h[i].b;
		else h[dex].fa=now,h[dex].w=tw,h[dex].b=tb,dex++,tw=h[i].w,tb=h[i].b,now=h[i].fa;
	}
	h[dex].fa=now,h[dex].w=tw,h[dex].b=tb;
	sort(h+1,h+1+dex);
	int lo=1;
	now=h[1].fa;
	for(int i=1;i<=dex;i++){
		if(now!=h[i].fa) lo++,now=h[i].fa;
		if(h[i].w<=w){
			dp[lo][h[i].w]=max(dp[lo][h[i].w],h[i].b);
			res=max(dp[lo][h[i].w],res);
			for(int j=1;j<=w;j++){
				if(dp[lo-1][j]!=0){
					if(j+h[i].w<=w){
						dp[lo][j+h[i].w]=max(dp[lo-1][j]+h[i].b,dp[lo][j+h[i].w]),
						res=max(dp[lo][j+h[i].w],res);						
					}
					dp[lo][j]=max(dp[lo-1][j],dp[lo][j]);			
				}
			}
		}
	} 
	printf("%d\n",res);
	return 0;
}
