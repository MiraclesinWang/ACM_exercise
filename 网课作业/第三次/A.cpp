#include<cstdio>
using namespace std;
struct Node{
	int x,y;
	bool water;
};
Node s[105][105];
void connect(int x,int y,int N,int M)
{
	if(x>N || x<1 || y<1 || y>M) return;
	if(!s[x][y].water) return;
	else{
		s[x][y].water=false;
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
				if(i!=0 || j!=0) connect(x+i,y+j,N,M);
	}
}
int main()
{
	int N,M,res=0;
	char temp;
	while(scanf("%d %d\n",&N,&M),N!=0||M!=0){
		res=0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++) scanf("%c",&temp),s[i][j].x=i,s[i][j].y=j,s[i][j].water=(temp=='@'?true:false);
			if(i<N) scanf("\n");		
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				if(s[i][j].water) res+=1;
				connect(i,j,N,M);
			}
		}
		printf("%d\n",res);		
	}

}
