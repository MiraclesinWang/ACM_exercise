#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

set <string> sign = {"+", "-", "*", "%", "/"};

struct node{
	int l, r;
	string s;
	bool is_sign;
} T[30];
int deg[30], fa[30];

void bfs(int rt, int dep)
{
	if(!~T[rt].l && !~T[rt].r) {cout << T[rt].s; return;}
	if(dep) cout << '(';
	if(~T[rt].l) bfs(T[rt].l, dep+1);
	cout << T[rt].s;
	bfs(T[rt].r, dep+1);
	if(dep) cout << ')';
}

int main()
{
	MEM(deg, 0);
	int n, a, b, rt;
	cin >> n;
	string s;
	rep(i, 1, n+1){
		getchar();
		cin >> s >> a >> b;
		deg[a]++, deg[b]++;
		T[i].s = s, T[i].l = a, T[i].r = b;
		if(sign.find(s) == sign.end()) T[i].is_sign = false;
		else T[i].is_sign = true;
		fa[a] = fa[b] = i;
	}
	rep(i, 1, n+1)
		if(!deg[i]) rt = i;
	bfs(rt, 0);
	return 0;
}

