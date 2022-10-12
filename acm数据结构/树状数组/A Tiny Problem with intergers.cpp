#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)
ll tree[maxn];
int m, n;


void build(int n)
{
	for(int i = 1; i <= n; i++){
		int j = 0;
		while(!((1<<j) & i)) tree[i] += tree[i-(1<<j)], j++;
	}
}

ll query(int d)
{
	ll ans = 0;
	for(int i = d; i > 0; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

void update(int d, int val)
{
	for(int i = d; i <= n; i += lowbit(i))
		tree[i] += val;
}

int main()
{
	memset(tree, 0, sizeof(tree));
	scanf("%d%d", &n, &m);
	rep(i, 1, n+1) scanf("%lld", &tree[i]);
	for(int i = n; i > 1; i--) tree[i] -= tree[i-1];
	build(n);
	rep(cmd_times, 0, m){
		char c;
		scanf("\n%c", &c);
		if(c=='Q'){
			int d;
			scanf("%d", &d);
			printf("%lld\n", query(d));
		}
		else{
			int l, r, val;
			scanf("%d%d%d", &l, &r, &val);
			update(l, val);
			if(r<n) update(r+1, -val);
		}
	}
}


