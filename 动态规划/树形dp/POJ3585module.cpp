#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int maxn = 200100;
struct Edge {
	int to, nxt, len;
	Edge() {}
	Edge(int _to, int _nxt, int _len) : to(_to), nxt(_nxt), len(_len) {}
}E[maxn*2];
 
int h[maxn], cnt, f[maxn], d[maxn], val[maxn], deg[maxn];
int n, T;
 
void addedge(int a, int b, int v) {
	deg[a]++; deg[b]++;
	E[++cnt] = Edge(b, h[a], v), h[a] = cnt;
	E[++cnt] = Edge(a, h[b], v), h[b] = cnt;
}
 
void dfs(int rt, int fa) {
	d[rt] = 0;
	for(int i = h[rt]; i; i = E[i].nxt) {
		int v = E[i].to;
		if(v == fa) continue;
		dfs(v, rt);
		if(deg[v] == 1) d[rt] += E[i].len;
		else d[rt] += min(d[v], E[i].len);
	}
}
 
void redfs(int rt, int fa) {
	for(int i = h[rt]; i; i = E[i].nxt) {
		int v = E[i].to;
		if(v == fa) continue;
		if(deg[rt] == 1) f[v] = d[v] + E[i].len;
		else f[v] = d[v] + min(f[rt] - min(d[v], E[i].len), E[i].len);
		redfs(v, rt);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		memset(h, 0, sizeof(h));
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		memset(deg, 0, sizeof(deg));
		cnt = 0;
		for(int i = 1; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c);
		}
		dfs(1, 0);
		f[1] = d[1];
		redfs(1, 0);
		int res = -1;
		for(int i = 1; i <= n; i++) res = max(res, f[i]);
		printf("%d\n", res);
	}
}
