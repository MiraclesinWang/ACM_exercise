#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int tree[maxn*8], s[maxn];
int n, q;

int build(int l, int r, int dex)
{
	if(l == r) tree[dex] = s[l], s[l] = dex;
	else{
		int mid = (l+r)>>1;
		tree[dex] = max(build(l, mid, dex*2), build(mid+1, r, dex*2+1));
	}
	return tree[dex];
}
void update(int dex, int val)
{
	int d = s[dex];
	tree[d] = val;
	d >>= 1;
	while(d){
		tree[d] = max(tree[d*2], tree[d*2+1]);
		d >>= 1;
	}
}
int query(int l, int r, int dex, int x, int y)
{
	if(l>=x && r<=y) return tree[dex];
	if(l > y || r < x) return 0;
	int mid = (l+r)>>1;
	return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
}

void solve()
{
	//int n, q;
	char cmd;
	//scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	build(1, n, 1);
	int l, r;
	for(int i = 0; i < q; i++){
		scanf("\n%c%d%d", &cmd, &l, &r);
		if(cmd == 'Q') printf("%d\n", query(1, n, 1, l, r));
		else update(l, r);
	}
}
int main()
{
	while(scanf("%d%d", &n, &q) != EOF) solve();
}
