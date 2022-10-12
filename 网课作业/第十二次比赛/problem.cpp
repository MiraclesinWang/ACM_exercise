#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e6+3;
int N[105];
int main()
{
	int T,n,l,r,m,sm;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d",&n,&l,&r);
		m=r-l+1;
		memset(N,1,sizeof(N));
		for(int j=2;j<=n;j++){
			sm=0;
			for(int k=1;k<=m;k++){
				sm+=N[k];
				sm%=mod;
				N[k]=sm;
			}
		}
		sm=0;
		for(int j=1;j<=m;j++){
			sm=(sm+N[j])%mod;
		}
		printf("%d\n",sm);
	}
}
