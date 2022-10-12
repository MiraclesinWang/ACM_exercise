#include <bits/stdc++.h>
using namespace std; 
#define rep(x, y) for(int i = x; i < y; i++)

const int maxn = 110*2;
int v[maxn], to[maxn], head[maxn], b[maxn], cd[maxn], dis[maxn], val[maxn];
int n, m, k, c, cnt = 0;
void init(){
	memset(head, 0, sizeof(head));
	cnt = 0;
}
void addedge(int u, int a, int vl){
	v[++cnt] = a;
	if(head[a]) to[cnt] = head[a];
	head[a] = cnt, cd[cnt] = vl;
}
priority_queue <int, vector<int>,greater<int> > q;

int main()
{
	int a, u, vl;
	scanf("%d%d%d%d", &n, &m, &k, &c);
	rep(0, m){
		scanf("%d%d%d", &a, &u, &vl);
		addedge(a, u, vl), addedge(u, a, vl);
	}
	rep(0, k){
		scanf("%d%d", &a, &vl);
		val[a] = vl;
	}
	while(!q.empty()) q.pop();
	q.push(1), q.push(2);
	printf("%d\n", q.top());
}
