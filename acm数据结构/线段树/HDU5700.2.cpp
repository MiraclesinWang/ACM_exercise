#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
ll a[maxn], sm[maxn];
int tree[maxn*16], t[maxn*2], s[maxn];
struct lne{
	int l, r;
} l[maxn];

void build(int l, int r, int dex)
{
	tree[dex] = 0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
	else t[l] = dex;
}
void update(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) tree[dex]++;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		update(l, mid, dex*2, x, y), update(mid+1, r, dex*2+1, x, y);
	}
}
void pushdown(int l, int r, int dex)
{
	if(l != r){
		int mid = (l+r) >> 1;
		tree[dex*2] += tree[dex], tree[dex*2+1] += tree[dex];
		pushdown(l, mid, dex*2), pushdown(mid+1, r, dex*2+1);
	}
}

int main()
{
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m) != EOF){
		ll res = 0, tmp = 0;
		build(1, n, 1);
		sm[0] = 0;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sm[i] = sm[i-1]+a[i];
		for(int i = 1; i <= m; i++){
			scanf("%d%d", &l[i].l, &l[i].r);
			update(1, n, 1, l[i].l, l[i].r);
		}
		pushdown(1, n, 1);
		int rub = 1e8;
		for(int i = n; i; i--){
			if(tree[t[i]] < k || tree[t[i]] != tree[t[i+1]]) rub = i;
			s[i] = rub-1;
		}
		for(int i = 1; i <= m; i++){
			int lll = l[i].l, r = l[i].r;
			ll x = sm[min(s[i], r)] - sm[lll-1];
			res = max(res, x);
		}
		for(int i = 1; i <= n; i++)
			printf("%d ", tree[t[i]]);
		printf("\n");
		printf("%lld\n", res);
		/*for(int i = 1; i <= n*2; i++){
			if(i%2 == 0) printf("%d ", tree[t[i]]);
			if(tree[t[i]] >= k){
				if(i%2 == 0) tmp += a[i/2];
			}
			else res = max(res, tmp), tmp = 0;
		}*/
	}
}
