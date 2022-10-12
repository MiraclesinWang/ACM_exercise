#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 2005
bool s[maxn][maxn];          //记录棋盘状态用 
int len[maxn][maxn];      //记录每个元素在右侧最多有多少个格子符合 
int main()
{
	int m,n,start,end,count,dex,length,c=1,sq=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	for(int i=1;i<=n;i++){
		start=1,end=2,count=1;
		while(end<=m){
			if(s[i][end]!=s[i][end-1]) count++,end++;
			else{
				for(int j=start;j<end;j++) len[i][j]=count--;
				start=end,end=start+1,count=1;
			}
		}
		for(int j=start;j<end;j++) len[i][j]=count--;
	}     //打表 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			dex=j+1,length=1;
			while(dex<=n){
				if(len[dex][i]>=len[j][i] && s[dex][i]!=s[dex-1][i]) length++,dex++;
				else break;				
			}
			if(length*len[j][i]>sq) sq=length*len[j][i];
			if(min(length,len[j][i])>c) c=min(length,len[j][i]);
		}
	}
	printf("%d\n%d\n",c*c,sq);
}
