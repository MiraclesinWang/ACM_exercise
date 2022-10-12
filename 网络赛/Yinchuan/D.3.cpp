#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXM=2e5+10;
const int MAXN = 1e5 + 10;
struct Edge{
	int to,next;
}edge[MAXM];
int head[MAXN],tot, cnt[MAXN];
double dp[MAXN], p[MAXN], tp[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v){
	edge[tot]=(Edge){v,head[u]};
	head[u]=tot++;
}
vector<int> topo;
int deg[MAXN];
void bfs(int n){
    topo.clear();
    queue<int> Q;
    for (int u=1;u<=n;++u){
        if (!deg[u]){
            Q.push(u);
        }
    }
    while (!Q.empty()){
        int u=Q.front();
        Q.pop();
        topo.push_back(u);
        for (int i=head[u];~i;i=edge[i].next){
            if (!(--deg[edge[i].to]))
                Q.push(edge[i].to);
        }
    }
}
int T,n,m,u,v;
int main()
{
	for (scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		init();
		memset(deg,0,sizeof(deg));
		for (int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			addedge(v,u);
			++deg[u];
		}
		for(int i = 1; i <= n; i++) p[i] = 1.0/(double)(deg[i]+1);
		for(int i = 1; i < n; i++) p[i] = p[i]/(1.0-p[i]);
		bfs(n);
		memset(dp, 0, sizeof(dp));
		memset(tp, 0, sizeof(tp));
		for(int i = 1; i < n; i++) dp[i] = p[i];
		for(int i = 0; i < n-1; i++){
			int k = topo[i];
			for(int j = head[k]; j != -1; j = edge[j].next){
				int v = edge[j].to;
				dp[v] += p[v]*(dp[k] + 1.0);
			}
		}
		for(int i = 1; i < n; i++) tp[i] = p[i]*(2.0*dp[i]+1.0);
		for(int i = 0; i < n-1; i++){
			int k = topo[i];
			for(int j = head[k]; j != -1; j = edge[j].next){
				int v = edge[j].to;
				tp[v] += p[v]*(tp[k]+2.0*dp[k]+1.0); 
			}
		}
		printf("%.2f\n", (dp[1]+tp[1])/2.0);
	}
}
