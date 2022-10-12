#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	int x,y;
	int color;
};
Node maze[205][205];
char tablet[7]={'W','A','K','J','S','D'};
void white_dfs(Node maze[205][205],int x,int y,int h,int w)    //传参数的时候W一定要*4！！！ 
{
	Node pre=maze[x][y];
	queue <Node> q;
	q.push(pre);
	while(!q.empty()){
		pre=q.front(),q.pop();
		int nx=pre.x,ny=pre.y;
		if(nx>=1 && maze[nx-1][ny].color==0) maze[nx-1][ny].color=2,q.push(maze[nx-1][ny]);
		if(ny>=1 && maze[nx][ny-1].color==0) maze[nx][ny-1].color=2,q.push(maze[nx][ny-1]);
		if(nx<=h && maze[nx+1][ny].color==0) maze[nx+1][ny].color=2,q.push(maze[nx+1][ny]);
		if(ny<=w && maze[nx][ny+1].color==0) maze[nx][ny+1].color=2,q.push(maze[nx][ny+1]);
	}
}
char black_dfs(Node maze[205][205],int x,int y,int h,int w,char tablet[7])    //传参数的时候W一定要*4！！！ 
{
	/*for(int i=0;i<=h+1;i++){
		for(int j=0;j<=w+1;j++)	printf("%d ",maze[i][j].color);
		printf("\n");		
	}*/
	int count=0;
	Node pre=maze[x][y];
	queue <Node> q;
	q.push(pre);
	while(!q.empty()){
		pre=q.front(),q.pop();
		int nx=pre.x,ny=pre.y;
		if(nx>=1){
			if(maze[nx-1][ny].color==1) maze[nx-1][ny].color=3,q.push(maze[nx-1][ny]);
			else if(maze[nx-1][ny].color==0) white_dfs(maze,nx-1,ny,h,w),count+=1;
		}
		if(ny>=1){
			if(maze[nx][ny-1].color==1) maze[nx][ny-1].color=3,q.push(maze[nx][ny-1]);
			else if(maze[nx][ny-1].color==0) white_dfs(maze,nx,ny-1,h,w),count+=1;
		}
		if(nx<=h){
			if(maze[nx+1][ny].color==1) maze[nx+1][ny].color=3,q.push(maze[nx+1][ny]);
			else if(maze[nx+1][ny].color==0) white_dfs(maze,nx+1,ny,h,w),count+=1;
		}
		if(ny<=w){
			if(maze[nx][ny+1].color==1) maze[nx][ny+1].color=3,q.push(maze[nx][ny+1]);
			else if(maze[nx][ny+1].color==0) white_dfs(maze,nx,ny+1,h,w),count+=1;
		}
	}
	return tablet[count];
}

int main()
{
	int h,w,t,count,cas=0;
	char temp[55];
	vector <char> res;
	for(int i=0;i<205;i++)
		for(int j=0;j<205;j++) maze[i][j].x=i,maze[i][j].y=j;
	while(scanf("%d %d",&h,&w),h && w){
		scanf("\n");
		for(int i=0;i<205;i++)
			for(int j=0;j<205;j++) maze[i][j].color=0;
		for(int i=1;i<=h;i++){
			cin.getline(temp,55);
			for(int j=0;j<w;j++){
				if(temp[j]-'0'<10) t=temp[j]-'0';
				else t=temp[j]-'a'+10;
				if(t>=8) maze[i][4*j+1].color=1,t-=8;
				if(t>=4) maze[i][4*j+2].color=1,t-=4;
				if(t>=2) maze[i][4*j+3].color=1,t-=2;
				if(t==1) maze[i][4*j+4].color=1;
			}
		}       //迷宫构建
		w*=4,count=0,cas++,res.clear();
		white_dfs(maze,0,0,h,w);
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++)
				if(maze[i][j].color==1) res.push_back(black_dfs(maze,i,j,h,w,tablet)),count++;
		}
		sort(res.begin(),res.end());
		printf("Case %d: ",cas);
		for(int i=0;i<count;i++) printf("%c",res[i]);
		printf("\n");
	}
}
