#include<cstdio>
using namespace std;
int num[10],grade[5]={3,1,0,0};

void dfs(int num[10],int x,int y,int n,int * count,int grade[5])
{
	if(x==n && y==n){
		if(num[n]==0) *count+=1;
	}
	else if(y==n){
		if(num[x]==0 || num[x]==1 || num[x]==3){
			num[n]-=grade[num[x]];
			if(num[n]>=0 && num[n]<=3*(n-x-1)) dfs(num,x+1,x+1,n,count,grade);
		}
	}
	else if(x==y){
		dfs(num,x,y+1,n,count,grade);
	}
	else{
		int num1[10],num2[10];
		for(int i=1;i<=n;i++) num1[i]=num[i],num2[i]=num[i];
		num[y]-=3;    //µÃ·ÖÎª0
		if(num[y]>=0 && num[x]<=3*(n-y)) dfs(num,x,y+1,n,count,grade);
		num1[x]-=1,num1[y]-=1;
		if(num1[x]>=0 && num1[y]>=0 && num1[x]<=3*(n-y) && num1[y]<=3*(n-x)) dfs(num1,x,y+1,n,count,grade);
		num2[x]-=3;
		if(num2[x]>=0 && num2[y]<=3*(n-x)) dfs(num2,x,y+1,n,count,grade);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	int * count=new int;
	*count=0;
	dfs(num,1,1,n,count,grade);
	printf("%d\n",*count);
}
