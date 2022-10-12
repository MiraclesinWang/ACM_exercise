#include<cstdio>
using namespace std;
int s[105],g[105];
int main()
{
	int n,t,res,m=3e5,temp,d;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i],&g[i]);
	for(int i=1;i<=n;i++){
		if(s[i]>=t){
			if(s[i]<m) m=s[i],d=i;
		}
		else{
			temp=(t-s[i])/g[i];
			temp=temp*g[i]+s[i];
			if(temp<t) temp+=g[i];
			if(temp<m) m=temp,d=i;
		}
	}
	printf("%d\n",d);
 } 
