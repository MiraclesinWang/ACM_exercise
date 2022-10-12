#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
struct node{
	int dex;
	ll sm;
} tree[maxn*8];
int e[maxn], n;
int rl, rr;
ll res;

void build(int l, int r, int dex)
{
	if(l == r) tree[dex].dex = l, tree[dex].sm = (ll)e[l];
	else{
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		if(e[tree[2*dex].dex] > e[tree[2*dex+1].dex]) tree[dex].dex = tree[2*dex+1].dex;
		else tree[dex].dex = tree[dex*2].dex;
		tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
	}
}
ll sm_query(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) return tree[dex].sm;
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r) >> 1;
		return sm_query(l, mid, dex*2, x, y)+sm_query(mid+1, r, dex*2+1, x, y);
	}
}
int m_query(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) return tree[dex].dex;
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r) >> 1;
		int a = m_query(l, mid, dex*2, x, y), b = m_query(mid+1, r, dex*2+1, x, y);
		if(e[a] > e[b]) return b;
		else return a;
	}
}
void query(int l, int r)
{
	int m = m_query(1, n, 1, l, r);
	//printf("%d %d %d\n", l, r, m);
	ll tmp = (ll)e[m]*sm_query(1, n, 1, l, r);
	if(tmp > res) rl = l, rr = r, res = tmp;
	if(l < m) query(l, m-1);
	if(r > m) query(m+1, r);
}

int main()
{
	int cnt = 0;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++) scanf("%d", &e[i]);
		build(1, n, 1);
		e[0] = 1e9, res = 0, rl = rr = 1;
		query(1, n);
		if(cnt++) printf("\n");
		printf("%lld\n%d %d\n", res, rl, rr);
	}
}
