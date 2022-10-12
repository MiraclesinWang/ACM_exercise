#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e3 + 10;
const int maxm = 1e4 + 10;

struct Edge{
	int nxt, v;
	Edge() {nxt=-1;}
} E[maxm];
int head[maxn], tot=0, deg[maxn], dg[maxn];
queue <int> q;

void addedge(int u, int v)
{
	if(~head[u]) E[tot].nxt = head[u];
	head[u] = tot;
	E[tot++].v = v;
}

int main()
{
	MEM(head, -1);
	MEM(deg, 0);
	int n, m, k;
	cin >> n >> m;
	rep(i, 0, m){
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		deg[b]++;
	}
	cin >> k;
	rep(i, 0, k){
		memcpy(dg, deg, sizeof(deg));
		bool flag = true;
		rep(j, 0, n){
			int p;
			cin >> p;
			if(dg[p] > 0) flag = false;
			for(int dex = head[p]; ~dex; dex = E[dex].nxt){
				int v = E[dex].v;
				dg[v]--;
			}
		}
		if(!flag) q.push(i);
	}
	cout << q.front();
	q.pop();
	while(!q.empty()){
		cout << " " << q.front();
		q.pop();
	}
	return 0;
}

