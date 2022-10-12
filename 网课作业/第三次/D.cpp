#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
#include<ctype.h>
using namespace std;
struct Node{
	int x,y;
	int walk;             //0表示不可走，1表示可走，-1表示终点,4表示探索过 
	Node * father;
	/*Node * father[5];
	bool searched[5];     //0,1,2,3分别表示从左，从右，从上，从下 
	int dex;     //经过次数 */
};

Node maze[23][23],cpy[23][23];
char direction(Node pre,Node target)
{
	if(pre.y==target.y-1) return 'E';
	else if(pre.y==target.y+1) return 'W';
	else if(pre.x==target.x-1) return 'S';
	else return 'N';
}
bool hpush(Node maze[23][23],Node lo,Node target,Node father,bool print,int l,int r)
{
	if(maze[2*lo.x-target.x][2*lo.y-target.y].walk==0) return false;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=r;j++){
			if(maze[i][j].walk==4) maze[i][j].walk=1;
			maze[i][j].father=NULL;
		}
	}
	queue <Node> q;
	Node temp;
	int x,y;
	maze[lo.x][lo.y].walk=0,maze[father.x][father.y].father=NULL;
	maze[2*lo.x-target.x][2*lo.y-target.y].walk=2;
	q.push(maze[father.x][father.y]);
	while(!q.empty()){
		temp=q.front(),q.pop();
		Node * fa=new Node;
		Node node;
		x=temp.x,y=temp.y,*fa=maze[x][y];
		if(temp.walk==2){
			if(print){
				stack <Node> st;
				Node pre;
				Node ans=maze[temp.x][temp.y];
				if(!ans.father) break;
				while(ans.father!=NULL)	st.push(ans),ans=*ans.father;
				st.push(maze[father.x][father.y]);
				pre=st.top(),st.pop();
				while(!st.empty()){
					printf("%c",tolower(direction(pre,st.top())));
					pre=st.top(),st.pop();
				}
			}
			maze[temp.x][temp.y].walk=1,maze[lo.x][lo.y].walk=1;
			return true;
		}
		if(x>=2 && (maze[x-1][y].walk==1||maze[x-1][y].walk==2))
			maze[x-1][y].walk=(maze[x-1][y].walk==1?4:2),maze[x-1][y].father=fa,q.push(maze[x-1][y]);
		if(x<=l-1 && (maze[x+1][y].walk==1||maze[x+1][y].walk==2))
			maze[x+1][y].walk=(maze[x+1][y].walk==1?4:2),maze[x+1][y].father=fa,q.push(maze[x+1][y]);
		if(y>=2 && (maze[x][y-1].walk==1||maze[x][y-1].walk==2))
			maze[x][y-1].walk=(maze[x][y-1].walk==1?4:2),maze[x][y-1].father=fa,q.push(maze[x][y-1]);
		if(y<=r-1 && (maze[x][y+1].walk==1||maze[x][y+1].walk==2))
			maze[x][y+1].walk=(maze[x][y+1].walk==1?4:2),maze[x][y+1].father=fa,q.push(maze[x][y+1]);
	}
	maze[2*lo.x-target.x][2*lo.y-target.y].walk=1,maze[lo.x][lo.y].walk=1;
	return false;
}

bool bfs(Node maze[23][23],Node start,int l,int r,Node cpy[23][23])
{
	queue <Node> q;
	q.push(maze[start.x][start.y]);
	Node temp,t;
	int x,y;
	while(!q.empty()){
		temp=q.front(),q.pop();
		Node * fa=new Node;
		x=temp.x,y=temp.y,*fa=maze[x][y];
		if(temp.walk==-1) return true;
		if(x>=2 && x<=l-1 && (maze[x-1][y].walk==1|| maze[x-1][y].walk==-1)){
			if(hpush(cpy,temp,maze[temp.x-1][temp.y],*temp.father,false,l,r))
				maze[x-1][y].walk=(maze[x-1][y].walk==1?4:-1),maze[x-1][y].father=fa,q.push(maze[x-1][y]);
		}
		if(y>=2 && y<=r-1 && (maze[x][y-1].walk==1||maze[x][y-1].walk==-1)){
			if(hpush(cpy,temp,maze[temp.x][temp.y-1],*temp.father,false,l,r))
				maze[x][y-1].walk=(maze[x][y-1].walk==1?4:-1),maze[x][y-1].father=fa,q.push(maze[x][y-1]);
		}
		if(x<=l-1 && x>=2 && (maze[x+1][y].walk==1 ||maze[x+1][y].walk==-1)){
			if(hpush(cpy,temp,maze[temp.x+1][temp.y],*temp.father,false,l,r))
				maze[x+1][y].walk=(maze[x+1][y].walk==1?4:-1),maze[x+1][y].father=fa,q.push(maze[x+1][y]);
		}
		if(y<=r-1 && y>=2 && (maze[x][y+1].walk==1||maze[x][y+1].walk==-1)){
			if(hpush(cpy,temp,maze[temp.x][temp.y+1],*temp.father,false,l,r))
				maze[x][y+1].walk=(maze[x][y+1].walk==1?4:-1),maze[x][y+1].father=fa,q.push(maze[x][y+1]);
		}
	}
	return false;
}

int main()
{
	stack<Node> st;
	int l,r,startx,starty,boxx,boxy,endx,endy,count=0;
	char str[22],temp;
	Node start,pre;
	while(scanf("%d %d",&l,&r),r||l){
		scanf("\n"),count++;
		for(int i=1;i<=l;i++){
			cin.getline(str,22);
			for(int j=1;j<=r;j++){
				temp=str[j-1];
				if(temp=='#') maze[i][j].walk=0,cpy[i][j].walk=0;
				else if(temp=='S') startx=i,starty=j,maze[i][j].walk=1,cpy[i][j].walk=1;
				else if(temp=='B') boxx=i,boxy=j,maze[i][j].walk=1,cpy[i][j].walk=1;
				else if(temp=='T') maze[i][j].walk=-1,cpy[i][j].walk=-1,endx=i,endy=j;
				else maze[i][j].walk=1,cpy[i][j].walk=1;
				cpy[i][j].x=maze[i][j].x=i,cpy[i][j].y=maze[i][j].y=j,cpy[i][j].father=maze[i][j].father=NULL;

			}
		}
		Node *f=new Node;
		*f=maze[startx][starty];
		maze[boxx][boxy].father=f;
		start=maze[boxx][boxy];
		printf("Maze #%d\n",count);
		if(!bfs(maze,start,l,r,cpy)) printf("Impossible.\n\n");
		else{
			Node ans=maze[endx][endy];
			while(ans.father!=NULL) st.push(ans),ans=*ans.father;
			pre=st.top(),st.pop();
			while(!st.empty()){
				hpush(cpy,pre,st.top(),*pre.father,true,l,r);
				printf("%c",direction(pre,st.top()));
				pre=st.top(),st.pop();
			}
			printf("\n\n");  
		}
	}
}
