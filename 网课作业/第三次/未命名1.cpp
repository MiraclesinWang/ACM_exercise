#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int x,y;
	bool walkable,searched;
};
Node s[22][22];
char temp[22];
int bfs(Node s[22][22],int startx,int starty,int m,int n)
{
	s[startx][starty].searched=true;
	int res=1,x,y;
	queue <Node> q;
	Node temp;
	q.push(s[startx][starty]);
	while(!q.empty()){
		temp=q.front(),q.pop();
		x=temp.x,y=temp.y;
		if(x>=2 && s[x-1][y].walkable && !s[x-1][y].searched) s[x-1][y].searched=true,res++,q.push(s[x-1][y]);
		if(y>=2 && s[x][y-1].walkable && !s[x][y-1].searched) s[x][y-1].searched=true,res++,q.push(s[x][y-1]);
		if(x<=n-1 && s[x+1][y].walkable && !s[x+1][y].searched) s[x+1][y].searched=true,res++,q.push(s[x+1][y]);
		if(y<=m-1 && s[x][y+1].walkable && !s[x][y+1].searched) s[x][y+1].searched=true,res++,q.push(s[x][y+1]);
	}
	return res;
}
int main()
{
	int m,n,startx,starty;
	while(scanf("%d %d",&m,&n),m||n){
		scanf("\n");
		for(int i=1;i<=n;i++){
			cin.getline(temp,22);
			for(int j=1;j<=m;j++){
				s[i][j].searched=false,s[i][j].x=i,s[i][j].y=j;
				if(temp[j-1]=='#') s[i][j].walkable=false;
				else if(temp[j-1]=='@') s[i][j].walkable=true,startx=i,starty=j;
				else s[i][j].walkable=true;
			}
		}
		printf("%d\n",bfs(s,startx,starty,m,n));
	}
}
