#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 45000 + 5
#define ABS(x) x>0?x:-x
bool dp[103][maxn];
int w[103]={0};
int m,sm=0;
int n;
void recur(int x,int y,int dpt)
{
	if(x>m || dpt>n) return;
	//printf("%d %d %d\n",x,y,dpt);
	dp[x+1][y+w[dpt]]=true;
	recur(x,y,dpt+1);
	if(y+w[dpt]<=sm) recur(x+1,y+w[dpt],dpt+1);
}
int main()
{
	ios::sync_with_stdio( false);
	memset( dp, false, sizeof(dp)); 
	int res=0,cpy;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i],sm+=w[i];
	if(n==1) {printf("0 %d\n",w[1]);return 0;}
	cpy=sm,sm/=2,m=n/2;
	if(n%2) m+=1;
	dp[0][0]=true;
	recur(0,0,1);
	if(n%2){
		for(int i=1;i<=sm;i++){
			if(dp[m-1][i] || dp[m][i])
				res=max(res,i);
		}		
	}
	else{
		for(int i=1;i<=sm;i++){
			if(dp[m][i])
				res=max(res,i);
		}		
	}
	printf("%d %d\n",res,cpy-res);
}
