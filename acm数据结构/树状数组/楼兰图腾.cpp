#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
int n;
ll tree[maxn];
struct coor{
	int dex, val;
	bool operator < (coor &oth) {return val < oth.val;}
}A[maxn];

void update(int d, ll val)
{
	for(int i = d; i<= n; i += lowbit(i))
		tree[i] += val;
}

ll query(int d)
{
	ll res = 0;
	for(int i = d; i; i -= lowbit(i)) res += tree[i];
	return res;
}

int main()
{
	memset(tree, 0, sizeof(tree));
	scanf("%d", &n);
	rep(i, 1, n+1) scanf("%d", &A[i].val), A[i].dex = i;
	sort(A+1, A+1+n);
	ll v = 0, a = 0;
	rep(i, 1, n+1){
		ll left_low = query(A[i].dex), right_low = (ll)i - left_low - 1,
		left_high = (ll)A[i].dex -1 - left_low, right_high = (ll)(n -A[i].dex) -right_low;
		update(A[i].dex, 1ll);
		v += left_high * right_high;
		a += left_low * right_low;
	}
	printf("%lld %lld\n", v, a);
}


