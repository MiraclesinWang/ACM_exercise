#include<cstdio>
using namespace std;
#define maxn 8000+5
int brnd[maxn];
int son[maxn];
int res[maxn];
int main()
{
	int n,cnt,lo,fa;
	scanf("%d",&n);
	son[1]=1,fa=1;
	for(int i=2;i<=n;i++) scanf("%d",&brnd[i]);
	for(int i=2;i<=n;i++){
		if(brnd[i]==0){
			son[i]=fa,fa=i;
			continue;
		}
		else if(brnd[i]==i-1){
			cnt=1,lo=fa;
			while(cnt<brnd[i]) lo=son[lo],cnt++;
			son[lo]=i;
		}
		cnt=1,lo=fa;
		while(cnt<brnd[i]) lo=son[lo],cnt++;
		son[i]=son[lo],son[lo]=i;
	}
	/*cnt=1,lo=fa;
	while(cnt<=n) printf("%d ",lo),lo=son[lo],cnt++;*/
	lo=fa;
	for(int i=1;i<=n;i++){
		res[lo]=i;
		lo=son[lo];
	}
	for(int i=1;i<=n;i++) printf("%d\n",res[i]);
}
