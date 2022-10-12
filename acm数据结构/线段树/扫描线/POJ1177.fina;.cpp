#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

const int maxn = 5010;
int sx[maxn*2], sy[maxn*2];
struct node{
	int cnt, len;
} tree[maxn*16];
struct lne{
	int x, d, u;
	int val;
	bool operator < (const lne &oth) const{
		if(x == oth.x) return val > oth.val;
		else return x < oth.x; 
	}
} l[maxn*2];
struct vec{
	int x1, x2, y1, y2;
} v[maxn];

void build(int ll, int r, int dex, int *m)
{
	tree[dex].len = tree[dex].cnt = 0;
	if(ll != r){
		int mid = (ll+r) >> 1;
		build(ll, mid, dex*2, m), build(mid+1, r, dex*2+1, m);
	}
}
void update(int ll, int r, int dex, int x, int y, int val, int *m)
{
	if(ll > y || r < x) return;
	else if(ll >= x && r <= y) tree[dex].cnt += val;
	else{
		int mid = (ll+r) >> 1;
		update(ll, mid, dex*2, x, y, val, m), update(mid+1, r, dex*2+1, x, y, val, m);
		tree[dex].len = tree[dex*2].len + tree[dex*2+1].len;
	}
	if(tree[dex].cnt > 0) tree[dex].len = m[r+1] - m[ll];
	else tree[dex].len = (ll==r?0:tree[dex*2].len+tree[dex*2+1].len);
}

int main()
{
	int res = 0, pre = 0;
	int n, x1, x2, y1, y2;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &v[i].x1, &v[i].y1, &v[i].x2, &v[i].y2),
		sx[i] = v[i].x1, sx[i+n] = v[i].x2, sy[i] = v[i].y1, sy[i+n] = v[i].y2;
	sort(sx+1, sx+1+2*n), sort(sy+1, sy+1+n*2);
	int xx = unique(sx+1, sx+1+2*n) - sx-1, yy = unique(sy+1, sy+1+2*n) - sy-1;
	for(int i = 1; i <= n; i++)
		v[i].x1 = lower_bound(sx+1, sx+1+xx, v[i].x1) - sx,
		v[i].x2 = lower_bound(sx+1, sx+1+xx, v[i].x2) - sx,
		v[i].y1 = lower_bound(sy+1, sy+1+yy, v[i].y1) - sy,
		v[i].y2 = lower_bound(sy+1, sy+1+yy, v[i].y2) - sy;
	for(int i = 1; i <= n; i++){
		l[i].x = v[i].x1, l[i].d = v[i].y1, l[i].u = v[i].y2;
		l[i+n] = l[i], l[i+n].x = v[i].x2;
		l[i].val = 1, l[i+n].val = -1;
	}
	sort(l+1, l+1+2*n);
	build(1, yy-1, 1, sy);
	for(int i = 1; i <= 2*n; i++){
		update(1, yy-1, 1, l[i].d, l[i].u-1, l[i].val, sy);
		res += max(0, tree[1].len-pre);
		pre = tree[1].len;
	}
	
	pre = 0;
	for(int i = 1; i <= n; i++){
		l[i].x = v[i].y1, l[i].d = v[i].x1, l[i].u = v[i].x2;
		l[i+n] = l[i], l[i+n].x = v[i].y2;
		l[i].val = 1, l[i+n].val = -1;
	}
	sort(l+1, l+1+n*2);
	build(1, xx-1, 1, sx);
	for(int i = 1; i <= 2*n; i++){
		update(1, xx-1, 1, l[i].d, l[i].u-1, l[i].val, sx);
		res += max(0, tree[1].len - pre);
		pre = tree[1].len;
	}
	printf("%d\n", res*2);
}
