#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 5e3 + 10;
struct line{
	int x, y1, y2;
	int val;
	bool operator < (const line &oth) const{
		if(x == oth.x) return val < oth.val;
		return x < oth.x;
	}
} lne[maxn*2];
struct rect{
	int x1, y1, x2, y2;
} rec[maxn];
struct node{
	int lzy, len;
} tree[maxn*8];
int x[maxn*2], y[maxn*2];
int res = 0;

void build(int l, int r, int dex, int *m)
{
	tree[dex].lzy = 0, tree[dex].len = m[r+1]-m[l];
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2, m), build(mid+1, r, dex*2+1, m);
	}
}
void update(int l, int r, int dex, int a, int b, int val, int * m)
{
	if(l >= a && r <= b){
		if(val > 0 && tree[dex].lzy == 0) res += tree[dex].len, tree[dex].len = 0;
		else if(val < 0 && tree[dex].lzy == 1) tree[dex].len = m[r+1]-m[l]; 
		tree[dex].lzy += val;
	}
	else if(l > b || r < a) return;
	else{
		int mid = (l+r) >> 1;
		tree[dex*2].lzy += tree[dex].lzy, tree[dex*2+1].lzy += tree[dex].lzy, tree[dex].lzy = 0;
		update(l, mid, dex*2, a, b, val, m), update(mid+1, r, dex*2+1, a, b, val, m);
		tree[dex].len = tree[dex*2].len + tree[dex*2+1].len;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2),
		x[i] = rec[i].x1, x[i+n] = rec[i].x2, y[i] = rec[i].y1, y[i+n] = rec[i].y2;
	sort(x+1, x+1+n*2), sort(y+1, y+1+2*n);
	int xx = unique(x+1, x+1+2*n) - x - 1, yy = unique(y+1, y+1+2*n) - y-1;
	for(int i = 1; i <= xx; i++) printf("%d ", x[i]);
	printf("\n");
	for(int i = 1; i <= yy; i++) printf("%d ", y[i]);
	printf("\n");
	printf("%d %d\n", xx, yy);
	printf("%d %d\n", rec[1].y1, rec[1].y2);
	for(int i = 1; i <= n; i++){
		rec[i].x1 = lower_bound(x+1, x+1+xx, rec[i].x1) - x;
		rec[i].x2 = lower_bound(x+1, x+1+xx, rec[i].x2) - x;
		rec[i].y1 = lower_bound(y+1, y+1+yy, rec[i].y1) - y;
		rec[i].y1 = lower_bound(y+1, y+1+yy, rec[i].y2) - y;	
	}
	printf("%d %d\n", rec[1].y1, rec[1].y2);
	build(1, yy-1, 1, y);
	for(int i = 1; i <= n; i++){
		lne[i].x = rec[i].x1, lne[i].y1 = rec[i].y1, lne[i].y2 = rec[i].y2;
		lne[i+n].x = rec[i].x2, lne[i+n].y1 = rec[i].y1, lne[i+n].y2 = rec[i].y2;
		lne[i].val = 1, lne[i+n].val = -1;
	}
	sort(lne+1, lne+1+2*n);
	for(int i = 1; i <= 2*n; i++) update(1, yy-1, 1, lne[i].y1, lne[i].y2-1, lne[i].val, y);
	// printf("%d %d %d %d\n", x[lne[i].x], res, lne[i].y1, lne[i].y2);
	//printf("%d ", res);
	build(1, xx-1, 1, x);
	for(int i = 1; i <= n; i++){
		lne[i].x = rec[i].y1, lne[i].y1 = rec[i].x1, lne[i].y2 = rec[i].x2;
		lne[i+n].x = rec[i].y2, lne[i+n].y1 = rec[i].x1, lne[i+n].y2 = rec[i].x2;
		lne[i].val = 1, lne[i+n].val = -1;
	}
	sort(lne+1, lne+1+2*n);
	for(int i = 1; i <= 2*n; i++) update(1, xx-1, 1, lne[i].y1, lne[i].y2-1, lne[i].val, x);
	//printf("%d\n", res);
	printf("%d\n", res*2);
}
