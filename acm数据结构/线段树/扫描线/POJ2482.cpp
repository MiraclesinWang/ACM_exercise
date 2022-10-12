#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define ll long long
const int maxn = 2e4 + 10;
int n;
ll w, h;
struct node{
	int val, lzy;
} tree[maxn*8];
struct dot{
	ll x, y;
	int y1, y2; 
	int val;
	bool operator < (const dot &oth) const{
		if(x==oth.x) return val < oth.val;
		else return x < oth.x;
	}
}s[maxn];
ll y[maxn];

void build(int l, int r, int dex)
{
	tree[dex].lzy = tree[dex].val = 0;
	if(l != r){
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
void update(int l, int r, int dex, int a, int b, int val)
{
	if(l >= a && r <= b) tree[dex].lzy += val, tree[dex].val += val;
	else if(l > b || r < a) return;
	else{
		int mid = (l+r)>>1;
		tree[dex*2].lzy += tree[dex].lzy, tree[dex*2+1].lzy += tree[dex].lzy;
		tree[dex*2].val += tree[dex].lzy, tree[dex*2+1].val += tree[dex].lzy;
		tree[dex].lzy = 0;
		update(l, mid, dex*2, a, b, val), update(mid+1, r, dex*2+1, a, b, val);
		tree[dex].val = max(tree[dex*2].val, tree[dex*2+1].val);
	}
}

void solve()
{
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld%d", &s[i].x, &s[i].y, &s[i].val);
		s[i+n].x = s[i].x+w, s[i+n].y = s[i].y, s[i+n].val = -s[i].val;
		y[i] = s[i].y, y[i+n] = s[i].y+h;
	}
	sort(y+1, y+1+2*n);
	int m = unique(y+1, y+1+2*n) - y -1;
	for(int i = 1; i <= n; i++){
		s[i].y1 = lower_bound(y+1, y+m+1, s[i].y) - y;
		s[i].y2 = lower_bound(y+1, y+m+1, s[i].y+h) - y;
		s[i+n].y1 = s[i].y1, s[i+n].y2 = s[i].y2;
	}
	sort(s+1, s+1+2*n);
	build(1, m, 1);
	int dex = 1, res = 0;
	for(int i = 1; i <= 2*n; i++){
		update(1, m, 1, s[i].y1, s[i].y2-1, s[i].val);
		res = max(res, tree[1].val);
	}
	printf("%d\n", res);
}

int main()
{
	while(scanf("%d%lld%lld", &n, &w, &h) != EOF)
		solve();
}
