#include<cstdio>
using namespace std;
#define maxn 1000+5
#define limit 0x3f3f3f3f
int s[maxn][maxn];
int floor[maxn][maxn];
int groud[maxn][maxn];
int nfloor[maxn][maxn];
int ngroud[maxn][maxn];
void init(int a,int b,int n)
{
	for(int i=1;i<=a;i++){       //行 
		for(int j=2;j<=n;j++){        //格子的长度 
			for(int k=1;k<=b-j+1;k++){      //列 
				if(floor[i][k]<s[i][j+k-1]) floor[i][k]=s[i][j+k-1];
				if(groud[i][k]>s[i][j+k-1]) groud[i][k]=s[i][j+k-1];
			}
		}
	}
}
void advance(int a,int b,int n)
{
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b-n+1;j++) nfloor[i][j]=floor[i][j],ngroud[i][j]=groud[i][j];
	for(int i=1;i<=b-n+1;i++){
		for(int j=2;j<=n;j++){
			for(int k=1;k<=a-j+1;k++){
				if(nfloor[k][i]<floor[j+k-1][i]) nfloor[k][i]=floor[j+k-1][i];
				if(ngroud[k][i]>groud[j+k-1][i]) ngroud[k][i]=groud[k+j-1][i];
			}
		}
	}
}
int main()
{
	int a,b,n,res=limit;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++) scanf("%d",&s[i][j]),floor[i][j]=s[i][j],groud[i][j]=s[i][j];
	init(a,b,n),advance(a,b,n);
	for(int i=1;i<=a-n+1;i++)
		for(int j=1;j<=b-n+1;j++)
			if(res>nfloor[i][j]-ngroud[i][j]) res=nfloor[i][j]-ngroud[i][j];
	printf("%d\n",res);
}
