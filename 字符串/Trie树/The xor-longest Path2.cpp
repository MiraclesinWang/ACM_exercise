#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
#define rep(i, x, y) for(int i = x; i < y; i++)

int n, code[maxn], tot=0, head[maxn], cnt =0; 

struct Edge{
	int to,nxt, w;
}edge[maxn*2];
void addedge(int u,int v, int w){
	edge[tot]=(Edge){v, head[u], w};
	head[u]=tot++;
}
struct node{
	bool have;
	int sn;
} trie[maxn*32];

void addnode(int v)
{
	int dex = 0;
	for(int i = 30; ~i; i--){
		int b = ((1<<i)&v)?1:0;
		if(!trie[dex].sn && i) trie[dex].sn = ++cnt, ++cnt;
		dex = trie[dex].sn + b;
		trie[dex].have = true;
	}
}
int query(int v)
{
	int dex = 0, ans = 0;
	for(int i = 30; ~i; i--){
		dex = trie[dex].sn;
		int cpy = dex, b = ((1<<i)&v)?1:0;
		dex += b;
		if(!trie[dex].have) dex = cpy + (b^1), ans = (ans<<1) + (b^1);
		else ans = (ans<<1) + b;
	}
	return ans;
}
struct tuple{int dex, w, par;};
queue <tuple> q;
void dfs(int dex, int w, int par)
{
	if(par >= 0) code[dex] = code[par] ^ w, addnode(code[dex]);
	else code[dex] = 0;
	for(int e = head[dex];~e;e = edge[e].nxt)
		if(edge[e].to != par) q.push((tuple){edge[e].to, edge[e].w, dex});
}
/*
int frt()
{
	rep(i, 0, n){
		int dex = head[i], cnt = 0;
		while(~dex) dex = edge[i].nxt, cnt++;
		if(cnt == 1) return i;
	}
}
*/

void init()
{
	rep(i, 0, maxn) head[i] = -1, edge[i].nxt = -1;
	memset(trie, 0, sizeof(trie));
}

int main()
{
	init();
	scanf("%d", &n);
	int u, v, w, rt = 0;
	rep(i, 1, n) scanf("%d%d%d", &u, &v, &w), addedge(u, v, w), addedge(v, u, w);
	while(!q.empty()) q.pop();
	q.push((tuple){rt, 0, -1});
	while(!q.empty()) {dfs(q.front().dex, q.front().w, q.front().par); q.pop();}
	int ans = 0, mod = (1<<30) -1 +(1<<30);
	rep(i, 0, n){
		int tmp = code[i] ^ mod;
		ans = max(ans, query(tmp)^code[i]);
		ans = max(ans, code[i]);
	}
	printf("%d\n", ans);
}


