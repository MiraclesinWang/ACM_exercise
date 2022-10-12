#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int state[12][22][22];
int dfs(int state[12][22][22],int rx,int ry,int w,int h,int count)
{
	int minn=INF,temp,x=rx,y=ry;
	if(count>=10) return INF;
	if(rx>=2 && state[count][rx-1][ry]!=0){
		x=rx,y=ry;
		memcpy(state[count+1],state[count],484*sizeof(int));
		/*for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++) state[count+1][i][j]=state[count][i][j];*/
		while(x>=1){
			if(state[count+1][x][y]==2){
				minn=(minn<count?minn:count);
				break;
			}
			if(state[count+1][x][y]==1) x-=1;
			else{
				state[count+1][x][y]=1;
				temp=dfs(state,x+1,y,w,h,count+1);
				minn=(temp>minn?minn:temp);
				break;
			}
		}	
	}
	if(ry>=2 && state[count][rx][ry-1]!=0){
		x=rx,y=ry;
		//printf("left\n");
		/*for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++) state[count+1][i][j]=state[count][i][j];*/
		memcpy(state[count+1],state[count],484*sizeof(int));
		while(y>=1){
			if(state[count+1][x][y]==2){
				minn=(minn<count?minn:count);
				break;
			}
			if(state[count+1][x][y]==1) y-=1;
			else{
				state[count+1][x][y]=1;
				temp=dfs(state,x,y+1,w,h,count+1);
				minn=(temp>minn?minn:temp);
				break;
			}
		}
	}
	if(rx<=h-1 && state[count][rx+1][ry]!=0){
		x=rx,y=ry;
		//printf("down\n");
		/*for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++) state[count+1][i][j]=state[count][i][j];*/
		memcpy(state[count+1],state[count],484*sizeof(int));
		while(x<=h){
			if(state[count+1][x][y]==2){
				minn=(minn<count?minn:count);
				break;
			}
			if(state[count+1][x][y]==1) x+=1;
			else{
				state[count+1][x][y]=1;
				temp=dfs(state,x-1,y,w,h,count+1);
				minn=(temp>minn?minn:temp);
				break;
			}
		}	
	}
	if(ry<=w-1 && state[count][rx][ry+1]!=0){
		x=rx,y=ry;
		//printf("right\n");
		memcpy(state[count+1],state[count],484*sizeof(int));
		/*for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++) state[count+1][i][j]=state[count][i][j];*/
		while(y<=w){
			if(state[count+1][x][y]==2){
				minn=(minn<count?minn:count);
				break;
			}
			if(state[count+1][x][y]==1) y+=1;
			else{
				state[count+1][x][y]=1;
				temp=dfs(state,x,y-1,w,h,count+1);
				minn=(temp>minn?minn:temp);
				break;
			}
		}	
	}
	return minn;
}

int main()
{
	int w,h,temp,startx,starty,res;
	while(scanf("%d %d",&w,&h),w||h){
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%d",&temp);
				if(temp==1) state[0][i][j]=0;
				else state[0][i][j]=1;
				if(temp==2) startx=i,starty=j;
				if(temp==3) state[0][i][j]=2;
			}
		}
		res=dfs(state,startx,starty,w,h,0)+1;
		if(res<=10) printf("%d\n",res);
		else printf("-1\n");
	}
}
