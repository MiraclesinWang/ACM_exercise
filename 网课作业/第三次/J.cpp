#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int num[70],possible[1000];
bool searched[70][70];

bool dfs(bool searched[70][70],int num[70],int dex,int n,int number,int count)
{
	//printf("%d %d %d\n",dex,number,count);
	bool res;
	if(number==0){
		memcpy(searched[0],searched[count],sizeof(bool)*n);
		return true;
	}
	if(dex>=n) return false;
	while(number<num[dex] || searched[count][dex]) dex++;
	if(dex>=n) return false;
	else{
		if(count>=1 && num[dex]==num[dex-1] && !searched[count][dex-1]){
			memcpy(searched[count+1],searched[count],sizeof(bool)*n);
			return dfs(searched,num,dex+1,n,number,count+1);
		}
		else{
			memcpy(searched[count+1],searched[count],sizeof(bool)*n);
			res=dfs(searched,num,dex+1,n,number,count+1);
			searched[count+1][dex]=true;
			res=res||dfs(searched,num,dex+1,n,number-num[dex],count+1);
			return res;
			//printf("%d\n",number-num[dex]);
			//return dfs(searched,num,dex+1,n,number-num[dex],count+1)||dfs(searched,num,dex+1,n,number,count);			
		}
	}
}

bool judge(bool searched[70][70],int num[70],int goal,int n)
{
	int dex,temp;
	while(true){
		/*for(int i=0;i<n;i++) printf("%d ",searched[0][i]);
		printf("\n");*/
		dex=0;
		while(searched[0][dex]) dex++;
		temp=goal-num[dex],searched[0][dex]=true;
		if(dex>=n) return true; 
		if(!dfs(searched,num,dex+1,n,temp,0)) return false;
	}
}

int main()
{
	int n,sum=0,dex;
	bool flag;
	while(scanf("%d",&n),n){
		dex=0,sum=0,flag=false;
		for(int i=0;i<n;i++) scanf("%d",&num[i]),sum+=num[i];
		sort(num,num+n,greater<int>());
		num[n]=0;
		for(int i=num[0];i<=sum/2;i++) if(sum%i==0) possible[dex++]=i;
		for(int i=0;i<dex;i++){
			for(int j=0;j<n;j++) searched[0][j]=false;
			if(judge(searched,num,possible[i],n)){
				printf("%d\n",possible[i]),flag=true;
				break;
			}
		}
		if(!flag) printf("%d\n",sum);
	}
}
//40 40 30 35 35 26 15 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 40 43 42 42 41 10 4 40 40 40 40 40 40 40 40 40 40 40 40 40 40 25 39 46 40 10 4 40 40 37 18 17 16 15 40 40 40 40 40 40 40 40
