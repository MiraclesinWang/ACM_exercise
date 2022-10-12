#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;
#define rep(i, x, y) for(int i = x; i < y; i++)
int n, m;
ll A[maxn];
struct node{
	ll sm, g;
}tree[maxn*16];

ll gcd(ll a, ll b)
{
	if(a > b) swap(a, b);
	if(!a) return b;
	while(b%a){
		ll c = b%a;
		b = a, a = c;
	}
	return a;
}

void build(int l, int r, int dex)
{
	if(l == r) tree[dex].g = tree[dex].sm = A[l];
	else{
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex].g = gcd(abs(tree[dex*2].g), abs(tree[dex*2+1].g));
		tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
	}
}

ll query_sm(int l, int r, int dex, int x, int y)
{
	if(y < x) return 0; 
	if(l >= x && r <= y) return tree[dex].sm;
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r) >> 1;
		return query_sm(l, mid, dex*2, x, y)+query_sm(mid+1, r, dex*2+1, x, y);
	}
}

ll query_gcd(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) return abs(tree[dex].g);
	else if(l > y || r < x) return -1;
	else{
		int mid = (l+r) >> 1;
		ll a = query_gcd(l, mid, dex*2, x, y), b = query_gcd(mid+1, r, dex*2+1, x, y);
		if(min(a, b) < 0) return max(a, b);
		return gcd(a, b);
	}
}

void update(int l, int r, int dex, int x, ll val)    //for one dot
{
	if(l > x || r < x) return;
	else if(l==r) tree[dex].g = tree[dex].sm = tree[dex].g + val;
	else{
		int mid = (l+r) >> 1;
		update(l, mid, dex*2, x, val), update(mid+1, r, dex*2+1, x, val);
		tree[dex].g = gcd(abs(tree[dex*2].g), abs(tree[dex*2+1].g));
		tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
	}
}


void init()
{memset(tree, 0, sizeof(tree));}

int main()
{
	init();
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%lld", &A[i]);
	for(int i = n-1; i; i--) A[i] -= A[i-1];
	build(1, n-1, 1);
	char c;
	int l, r;
	ll d;
	rep(times, 0, m){
		scanf("\n%c%d%d", &c, &l, &r);
		if(c=='C'){
			scanf("%lld", &d);
			if(l==1) A[0]+=d;
			else update(1, n-1, 1, l-1, d);
			if(r < n) update(1, n-1, 1, r, -d);
		}
		else{
			ll tmp = query_sm(1, n-1, 1, 1, l-1) + A[0];
			printf("%lld\n", gcd(tmp, query_gcd(1, n-1, 1, l, r-1)));
		}
	}
}


