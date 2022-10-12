#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 10000+5
bool vis[maxn];
struct edge{
	int a,b;
	int val;
	bool operator <(const edge &oth) {return val<oth.val;}
} v[maxn*2];
int main()
{
	int n,k,m,a,b,c,cnt=0,dex=1,d;
	scanf("%d%d%d",&n,&k,&m);
	printf("%d\n",m);
	for(int i=1;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		v[i].a=a,v[i].b=b,v[i].val=c;
	}
	sort(v+1,v+m);
	v[0].val=0;
	memset(vis,false,sizeof(vis));
	while(cnt<k){
		if(vis[v[dex].a] && vis[v[dex].b]) dex++;
		else vis[v[dex].a]=true,vis[v[dex].b]=true,dex++,cnt++;
	}
	printf("%d\n",v[dex-1].val);
}
