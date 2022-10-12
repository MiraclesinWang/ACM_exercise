#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e4 + 10;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

queue<int> q;
int n, m, deg[maxn], s[maxn];
struct Edge{
	int u, v;
	bool operator < (Edge &oth) {return u < oth.u;}
} E[maxn];
bitset<maxn> cnct[maxn];
map <int, int> mp;

void init()
{
	memset(cnct, 0, sizeof(cnct));
	memset(deg, 0, sizeof(deg));
	while(!q.empty()) q.pop();
}


int main()
{
	init();
	scanf("%d%d", &n, &m);
	rep(i, 0, m){
		int u, v;
		scanf("%d%d", &u, &v);
		E[i].u = u, E[i].v = v;
		deg[v]++;
	}
	sort(E, E+m);   //把边按照u的大小排序 
	for(int i = m-1; i >-1; i--) mp[E[i].u] = i;
	//记录每个u0对应的在E中的起始位置,即E[i]-E[j]这一段的u全是u0，则 mp[u]=i 
	rep(i, 1, n+1) if(!deg[i]) q.push(i);   //拓扑排序 
	int dex = n-1;
	while(!q.empty()){
		s[dex--] = q.front();
		int d = mp[q.front()];
		while(d < m & E[d].u == q.front()){
			if(!(--deg[E[d].v])) q.push(E[d].v);
			d++;
		}
		q.pop();
	}    //到这都是 
	rep(i, 0, n){
		int u = s[i];     //按照排序的顺序遍历 
		cnct[u][u] = true;   //自己可以到自己 
		if(mp.find(u) != mp.end()){   //有些边没有出度，排除 
			int d = mp[u];
			while(d < m & E[d].u == u)
				cnct[u] |= cnct[E[d].v], d++;   //每一个自己指向边能到的节点，自己一定也都能到 
		}
	}
	rep(i, 1, n+1){
		int res = 0;
		rep(j, 0, n+1) res += cnct[i][j];
		printf("%d\n", res);
	}
}


