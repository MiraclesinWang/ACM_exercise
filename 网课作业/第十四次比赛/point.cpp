#include<iostream>
#include<cmath>
using namespace std;
int n, m, root, a, b, total;
#define maxn 100005
int dfn[maxn], low[maxn], flag[maxn], head[maxn*2];
struct node{
    int to;
    int next;
}edge[200010];
 
int cnt = 1;
void add(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void tarjan(int u, int father) {
    int child = 0;//child用来记录在生成树中当前顶点的儿子的个数
    dfn[u] = low[u] = ++total;//时间戳
    for (int i = head[u]; i != 0; i = edge[i].next) {//前向星遍历该顶点的所有边
        int v = edge[i].to;//该顶点连接的顶点
        if (!dfn[v]) {//如果时间戳为0说明没有访问过
            child++;
            tarjan(v, u);//继续往下搜索
            low[u] = min(low[u], low[v]);//更新当前时间戳
            //  如果当前节点是根节点并且儿子个数大于等于2，则满足第一类节点，为割点
            if (u == root && child >= 2) {
                flag[u] = 1;
            //不为根结点但是满足第二类条件的节点
            } else if (u != root && low[v] >= dfn[u]) {
                flag[u] = 1;
            }
            //如果顶点被访问过并且不是该节点的父亲，说明此时的v为u的祖先，因此需要更新最早顶点的时间戳
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
 
 
int main() {
	int res=0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    root = 1;
    tarjan(1, root);
    for (int i = 1; i <= n; i++)
        if(flag[i]) res++;
    printf("%d\n",res);
    return 0;
}
