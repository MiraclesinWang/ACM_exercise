#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1005
int fa[maxn];
int dp[maxn][maxn]; 
int frt(int n){return n==fa[n]?n:fa[n]=frt(fa[n]);}
struct hos{
	int w,b,fa;
	bool operator <(const hos& oth){return fa<oth.fa;}
} h[maxn*2];
void init(int n)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int main()
{
	memset(dp,0,sizeof(dp));
	int n,m,w,x,y,res=0;
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		cin>>h[i].w;
	for(int i=1;i<=n;i++)
		cin>>h[i].b;
	init(n);
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(fa[x]==x) fa[x]=y;
		else if(fa[y]==y) fa[y]=x;
		else fa[frt(x)]=frt(y);
	}
	for(int i=1;i<=n;i++) frt(i);
	for(int i=1;i<=n;i++) h[i].fa=fa[i];
	sort(h+1,h+1+n);
	int lo=1,tw=0,tb=0,now=h[1].fa;
	for(int i=1;i<=n;i++){
		if(now!=h[i].fa){
			if(tw<=w){
				dp[lo][tw]=max(dp[lo][tw],tb);
				res=max(dp[lo][tw],res);
				for(int j=1;j<=w;j++){
					if(dp[lo-1][j]!=0){
						if(j+tw<=w){
							dp[lo][j+tw]=max(dp[lo-1][j]+tb,dp[lo][j+tw]),
							res=max(dp[lo][j+tw],res);							
						}
						dp[lo][j]=max(dp[lo-1][j],dp[lo][j]);
					}
				}
			}
			lo++,now=h[i].fa,tw=h[i].w,tb=h[i].b;
		}
		else tw+=h[i].w,tb+=h[i].b;
		if(h[i].w<=w){
			dp[lo][h[i].w]=max(dp[lo][h[i].w],h[i].b);
			res=max(dp[lo][h[i].w],res);
			for(int j=1;j<=w;j++){
				if(dp[lo-1][j]!=0){
					if(j+h[i].w<=w){
						dp[lo][j+h[i].w]=max(dp[lo-1][j]+h[i].b,dp[lo][j+h[i].w]);
						res=max(dp[lo][j+h[i].w],res);						
					}
					dp[lo][j]=max(dp[lo-1][j],dp[lo][j]);
				}
			}
		}
	}
	if(tw<=w){
		dp[lo][tw]=max(dp[lo][tw],tb);
		res=max(dp[lo][tw],res);
		for(int j=1;j<=w;j++){
			if(dp[lo-1][j]!=0){
				if(j+tw<=w){
					dp[lo][j+tw]=max(dp[lo-1][j]+tb,dp[lo][j+tw]),
					res=max(dp[lo][j+tw],res);							
				}
				dp[lo][j]=max(dp[lo-1][j],dp[lo][j]);
			}
		}
	} 
	printf("%d\n",res);
	/*for(int i=1;i<=w;i++){
		for(int j=1;j<=dex;j++)
			printf("%8d",dp[j][i]);
		printf("\n");
	}*/
}
