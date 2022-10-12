#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 2000+5
#define INF 0x3f3f3f3f
struct Node{
	int add,val;
} item[2000+5];
bool cmp(Node a,Node b) {return a.add>b.add;}
bool lock[maxn];
int dp[maxn],dex[maxn];
int change_d[maxn],change_v[maxn],c;
int cnt=0;
int main()
{
	int n,tmp,a,res=-INF;
	memset(dp,-INF,sizeof(dp));
	memset(lock,true,sizeof(lock));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&item[i].add,&item[i].val);
	sort(item+1,item+n+1,cmp);
	dp[1]=0,lock[1]=false;
	dex[++cnt]=1;
	for(int i=1;i<=n;i++){
		c=0,tmp=cnt;
		for(int j=1;j<=tmp;j++){
			//printf("%d %d\n",dex[j],dp[dex[j]]);
			a=dex[j]+item[i].add-1;
			if(a>n) a=n;
			if(a<0) continue;
			//printf("%d\n",a);
			if(!lock[a]){
				if(dp[a]<dp[dex[j]]+item[i].val)
					change_d[++c]=a,change_v[c]=dp[dex[j]]+item[i].val;
			}
			else{
				dex[++cnt]=a;
				dp[a]=dp[dex[j]]+item[i].val;
				lock[a]=false;
			}
		}
		//printf("----------------\n");
		for(int j=1;j<=c;j++)
			dp[change_d[j]]=change_v[j];
	}
	for(int i=0;i<=n;i++)
		if(!lock[i]) res=max(res,dp[i]);
	printf("%d\n",res);
}
