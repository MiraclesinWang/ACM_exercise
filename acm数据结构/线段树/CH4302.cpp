#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long ll;
const int maxn = 5e5 + 10;
struct node{
	int gcd, sm;
} tree[maxn*16];
int n, m;
int B[maxn], A[maxn];

int _gcd(int a, int b)
{
	a = abs(a), b = abs(b);
	if(a > b) swap(a, b);
	if(!a) return b;
	while(true){
		int c = b%a;
		if(c) b=a, a=c;
		else return a;
	}
}

void build(int l, int r, int dex)
{
	if(l == r) tree[dex].sm = tree[dex].gcd = B[l];
	else{
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
		tree[dex].gcd = _gcd(tree[dex*2].gcd, tree[dex*2+1].gcd);
	}
}

void update(int l, int r, int x, int val, int dex)
{
	if(l>x || r<x) return;
	if(l==r) {
		tree[dex].sm += val, tree[dex].gcd += val;
		return;
	}
	int mid = (l+r) >> 1;
	update(l, mid, x, val, dex*2), update(mid+1, r, x, val, dex*2+1);
	tree[dex].sm = tree[dex*2].sm + tree[dex*2+1].sm;
	tree[dex].gcd = _gcd(tree[dex*2].gcd, tree[dex*2+1].gcd);
}

int query_gcd(int l, int r, int x, int y, int dex)
{
	if(l>y || r<x) return 0;
	if(l==r) return tree[dex].gcd;
	int mid = (l+r) >> 1;
	return _gcd(query_gcd(l, mid, x, y, dex*2), query_gcd(mid+1, r, x, y, dex*2+1));
}

int query_sum(int l, int r, int x, int y, int dex)
{
	if(l>y || r<x || y<x) return 0;
	if(l==r) return tree[dex].gcd;
	int mid = (l+r) >> 1;
	return query_sum(l, mid, x, y, dex*2) + query_sum(mid+1, r, x, y, dex*2+1);
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n+1) scanf("%d", &A[i]);
	B[1] = A[1];
	rep(i, 2, n+1) B[i] = A[i] - A[i-1];
	build(1, n, 1);
	char cmd;
	int l, r, d;
	rep(i, 0, m){
		scanf("\n%c%d%d", &cmd, &l, &r);
		if(cmd=='Q')
			printf("%d\n", _gcd(query_sum(1, n, 1, l, 1), query_gcd(1, n, l+1,r,1)));
		else{
			scanf("%d", &d);
			update(1, n, l, d, 1), update(1, n, r+1, -d, 1);
		}
			
	}
}
