#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int n,m;
int tot,head[MAX],adj[MAX*2],next[MAX*2];    //adj¡¨Ω”±ﬂ 
int deep[MAX];
bool vis[MAX];
void addedge(int u,int v){
    tot++,adj[tot]=v;
	next[tot]=head[u],head[u]=tot;
}
void dfs(int x){
    vis[x]=true;
    for (int i=1;i<=20;i++)
        if (deep[x]<(1<<i)) break;
    for (int i=head[x];i;i=next[i]){
        if (!vis[adj[i]]){
            deep[adj[i]]=deep[x]+1;
            dfs(adj[i]);
        }
    }
}
int main()
{
    int i,j,u,v;
    scanf("%d%d",&n,&m);
    for (i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v),addedge(v,u);
    }
    for(int i=1;i<=2*n;i++) printf("%d ",next[i]);
    cout<<endl;
    for(int i=1;i<=2*n;i++) printf("%d ",head[i]);
    cout<<endl;
    dfs(1);
    //for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
    //cout<<endl;
}
