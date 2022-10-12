#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i < y; i++)
#define lowbit(x) x&(-x)

typedef long long LL;
const int maxn = 2e4 + 5;
LL dis[maxn*4], cnt[maxn*4], x_all[maxn];
int n;

LL query(int d, LL * tree)
{
	int ans = 0;
	for(int i = d; i > 0; i -= lowbit(i))
		ans += tree[i];
	return ans; 
} 

void update(int d, LL val, LL * tree)
{
	for(int i = d; i <= n; i += lowbit(i))
		tree[i] += val; 
} 

struct elem{
	LL x, v;
} E[maxn];

bool cmp_v(elem a, elem b) { return a.v < b.v; }

int main()
{
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	rep(i, 0, n) scanf("%lld%lld", &E[i].v, &E[i].x), x_all[i] = E[i].x;
	sort(x_all, x_all+n), sort(E, E+n, cmp_v);
	int m = unique(x_all, x_all +n) - x_all;
	LL total_dis = 0, res = 0;
	rep(i, 0, n){
		int d = lower_bound(x_all, x_all+m, E[i].x) - x_all + 1;
		LL ts = query(d-1, dis), tn = query(d-1, cnt);
		res += (tn*E[i].x - ts) * E[i].v + (total_dis - ts - (i-tn)*E[i].x)*E[i].v;
		total_dis += E[i].x;
		update(d, E[i].x, dis), update(d, 1, cnt); 
	}
	cout << res;
}
