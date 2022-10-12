#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

#define rep(x, y) for(int i = x; i < y; i++)
typedef long long ll;
struct node{
	ll left, right, mid;
} tree[maxn*16];
ll a[maxn], res;

void build(int l, int r, int dex)
{
	if(l == r) tree[dex].left = tree[dex].right = tree[dex].mid = a[l];
	else{
		int mid = (l+r) >> 1;
		build(l, mid, dex*2);
		build(mid+1, r, dex*2+1);
		if(tree[dex*2].left == tree[dex*2].mid) tree[dex].left = tree[dex*2].left + tree[dex*2+1].left;
		else tree[dex].left = tree[dex*2].left;
		
		if(tree[dex*2+1].right == tree[dex*2+1].right) tree[dex].right = tree[dex*2+1].right + tree[dex*2].right;
		else tree[dex].right = tree[dex*2+1].right;
		
		tree[dex].mid = max(tree[dex*2].mid, tree[dex*2+1].mid);
		tree[dex].mid = max(tree[dex*2].right + tree[dex*2+1].left, tree[dex].mid); 
	}
}

node query(int l, int r, int dex, int x, int y)
{
	node res;
	res.left = res.mid = res.right = 0;
	if(l > y || x > r) return res;
	if(l >= x && r <= y) return tree[dex];
	int mid = (l+r) >> 1;
	if(mid >= y) return query(l, mid, dex*2, x, y);
	if(mid < x) return query(mid+1, r, dex*2+1, x, y);
	node left = query(l, mid, dex*2, x, y), right = query(mid+1, r, dex*2+1, x, y);
	if(left.mid == left.left) res.left = left.left + right.left;
	else res.left = left.left;
	
	if(right.right == right.mid) res.right = res.right + left.right;
	else res.right = right.right;
	
	res.mid = max(left.mid, right.mid);
	res.mid = max(left.right + right.left, res.mid);
	return res;
}

void update(int l, int r, int dex, int x, int val)
{
	if(l > x || r < x) return ;
	if(l == r) tree[dex].left = tree[dex].mid = tree[dex].right = val;
	else{
		int mid = (l+r) >> 1;
		update(l, mid, dex*2, x, val), update(mid+1, r, dex*2+1, x, val);
		if(tree[dex*2].left == tree[dex*2].mid) tree[dex].left = tree[dex*2].left + tree[dex*2+1].left;
		else tree[dex].left = tree[dex*2].left;
		
		if(tree[dex*2+1].right == tree[dex*2+1].right) tree[dex].right = tree[dex*2+1].right + tree[dex*2].right;
		else tree[dex].right = tree[dex*2+1].right;
		
		tree[dex].mid = max(tree[dex*2].mid, tree[dex*2+1].mid);
		tree[dex].mid = max(tree[dex*2].right + tree[dex*2+1].left, tree[dex].mid); 
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rep(1, n+1) scanf("%lld", &a[i]);
	build(1, n, 1);
	rep(0, m){
		int k, x, y;
		scanf("%d%d%d", &k, &x, &y);
		if(k == 1){
			if(x > y) swap(x, y);
			node res = query(1, n, 1, x, y);
			ll tmp = max(res.left, res.right);
			tmp = max(res.mid, tmp);
			printf("%lld\n", tmp);
		}
		else update(1, n, 1, x, y);
	}
}
