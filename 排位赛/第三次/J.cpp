#include<cstdio>
#include<queue>
using namespace std;
struct Node{
	int x,y;
	int walk;
	int l,r;
	int count;
};
Node s[2010][2010];
int bfs(Node s[2010][2010],int n,int m,int r,int c,int dx,int dy)
{
	queue <Node> q;
	Node temp;
	int x,y;
	int res=1;
	s[r][c].walk=2;
	q.push(s[r][c]);
	while(!q.empty()){
		temp=q.front(),q.pop();
		x=temp.x,y=temp.y;
		if(x>=2 && s[x-1][y].walk==1) s[x-1][y].walk=2,res++,s[x-1][y].l=temp.l,s[x-1][y].r=temp.r,q.push(s[x-1][y]);
		if(x<=n-1 && s[x+1][y].walk==1) s[x+1][y].walk=2,res++,s[x+1][y].r=temp.r,s[x+1][y].l=temp.l,q.push(s[x+1][y]);
		if(y>=2 && s[x][y-1].walk==1 && temp.l<dx) s[x][y-1].walk=2,res++,s[x][y-1].l=temp.l+1,s[x][y-1].r=temp.r,q.push(s[x][y-1]);
		if(y<=m-1 && s[x][y+1].walk==1 && temp.r<dy) s[x][y+1].walk=2,res++,s[x][y+1].l=temp.l,s[x][y+1].r=temp.r+1,q.push(s[x][y+1]);
	}
	return res;
}

int main()
{
	int n,m,r,c,x,y;
	char temp;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&r,&c);
	scanf("%d %d\n",&x,&y);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&temp);
			if(temp=='.') s[i][j].walk=1;
			else s[i][j].walk=0;
			s[i][j].x=i,s[i][j].y=j,s[i][j].l=0,s[i][j].r=0;
		}
		if(i<n) scanf("\n");
	}
	printf("%d\n",bfs(s,n,m,r,c,x,y));
}
