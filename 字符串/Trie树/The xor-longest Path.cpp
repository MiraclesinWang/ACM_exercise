#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

int n, fa[maxn], val[maxn], res[maxn], cnt=0; 

struct node{
	int head, nxt, w;
} Edge[maxn];

struct trie_node{
	bool have;
	int fa, sn;
} trie[maxn*2];


void init()
{
	rep(i, 0, maxn) fa[i] = i, Edge[i].head = -1, Edge[i].nxt = -1;
	memset(trie, 0, sizeof(trie));
}
void addedge(int u, int v, int w)
{
	Edge[u].w = w;
	if(!~Edge[u].head) Edge[u].head = v;
	else Edge[v].nxt = Edge[u].head, Edge[u].head = v;
}
void addnode(int v)
{
	int dex = 0;
	for(int i = 30; i >=0; i--){
		if(!trie[dex].sn) trie[dex].sn = ++cnt; ++cnt;
		dex = trie[dex].sn;
		if((1<<i)&v) dex++;
		trie[dex].have = true;
	}
}
void dfs(int dex, int now, int par)
{
	printf("look at this: %d %d %d\n", dex, now, par);
	int cpy = dex;
	res[dex] = now ^ val[dex];
	now = res[dex];
	dex = Edge[dex].head;
	//addnode(res[dex]);
	while(~dex){
		if(dex != par) dfs(dex, now, cpy);
		dex = Edge[dex].nxt;
	}
}

int query(int v)
{
	int dex = 0, ans = 0;
	for(int i = 30; i >=0; i--){
		dex = trie[dex].sn;
		if((1<<i)&v) dex++;
		if(!trie[dex].have) ans = (ans<<1) + ((1<<i)&v);
		else dex = (((dex-1)>>1)<<1) + 1 + (((1<<i)&v)^1), ans = (ans<<1) + (((1<<i)&v)^1);
	}
	return ans;
}


int main()
{
	init();
	scanf("%d", &n);
	int u, v, w, rt;
	rep(i, 1, n) scanf("%d%d%d", &u, &v, &w), addedge(u, v), addedge(v, u);
	rep(i, 0, n) if(fa[i] ==i) {rt = i; break;}
	dfs(rt, 0, -1);
	int ans = 0, mod = (1<<30) -1 + (1<<30);
	rep(i, 0, n){
		int q = mod^res[i];
		ans = max(ans, query(q)^res[i]);
		ans = max(ans, res[i]);
	}
	printf("%d\n", ans);
}


