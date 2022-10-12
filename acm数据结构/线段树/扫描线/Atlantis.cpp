#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
#define rep(i, x, y) for(int i = x; i < y; i++)
int n;
double y[maxn*2];
struct dot{
	double y1, y2, x;
	int cnt;
	bool operator < (dot &oth) {return x < oth.x;}
} A[maxn*2];
struct node{
	double len;
	int lzy, mn, mx;
} tree[maxn*16];


void build(int l, int r, int dex)
{
	tree[dex].lzy = tree[dex].mx = tree[dex].mn = 0; tree[dex].len = 0.0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}

void refresh(int dex)
{
	tree[dex].len = tree[dex*2].len + tree[dex*2+1].len;
	tree[dex].mn = min(tree[dex*2].mn, tree[dex*2+1].mn);
	tree[dex].mx = max(tree[dex*2+1].mx, tree[dex*2+1].mx);
}

void pushdown(int l, int r, int dex)
{
	printf("%d ", tree[dex].lzy);
	if(l==r){
		tree[dex].mn = tree[dex].mx = tree[dex].lzy;
		tree[dex].len = tree[dex].lzy?(y[l+1] - y[l]):0;
		printf("leaf: %d %d %d %f\n", l, l, tree[dex].lzy, tree[dex].len);
		return;
	}
	if((tree[dex].lzy > 0 && !tree[dex].mn) ||   //需要增加区间 
	(tree[dex].lzy < 0 && !(tree[dex].mn + tree[dex].lzy))){ //需要减少区间 
		tree[dex*2].lzy += tree[dex].lzy, tree[dex*2+1].lzy += tree[dex].lzy;
		if(tree[dex].lzy > 0 && !tree[dex].mx) tree[dex].len = y[r+1] - y[l]; //一起增加 
		else if(tree[dex].lzy < 0 && !!(tree[dex].mx + tree[dex].lzy)) tree[dex].len = 0; //一起减小
		else{
			int mid = (l+r) >> 1;
			pushdown(l, mid, dex*2), pushdown(mid+1, r, dex*2+1);
		} 
		tree[dex].lzy = 0;
		refresh(dex);
	}
	printf("pushdown: %d %d %f\n", l, r, tree[dex].len);
}

void update(int l, int r, int dex, int x, int y, int val)
{
	if(l >= x && r <= y){
		tree[dex].lzy += val;
		pushdown(l, r, dex);
	}
	else if(l > y || r < x) pushdown(l, r, dex);
	else{
		int mid = (l+r) >> 1;
		tree[dex*2].lzy += tree[dex].lzy, tree[dex*2+1].lzy += tree[dex].lzy;
		tree[dex].lzy = 0;
		update(l, mid, dex*2, x, y, val), update(mid+1, r, dex*2+1, x, y, val);
		refresh(dex); 
	} 
	printf("update: %d %d %d %d %d %d %d %lf\n", l, r, x, y, val, tree[dex].mn, tree[dex].mx, tree[dex].len);
}


void init()
{
	memset(A, 0, sizeof(A));
}

int main()
{
	int test_case = 1;
	while(scanf("%d", &n) && n){
		map<int, int> mp;
		double res = 0;
		init();
		printf("Test case #%d\n", test_case++);
		double x1, x2, y1, y2;
		rep(i, 1, n+1){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			A[i].x = x1, A[i].y1 = y1, A[i].y2 = y2, A[i].cnt = 1;
			A[i+n].x = x2, A[i+n].y1 = y1, A[i+n].y2 = y2, A[i+n].cnt = -1;
			y[i] = y1, y[i+n] = y2;
		}
		sort(A+1, A+1+2*n);
		sort(y+1, y+1+2*n);
		int m = unique(y+1, y+1+2*n) - y - 1;
		rep(i, 1, m+1) mp[y[i]] = i;
		
		build(1, m-1, 1);
		rep(i, 1, 2*n){
			update(1, m-1, 1, mp[A[i].y1], mp[A[i].y2]-1, A[i].cnt);
			printf("%f %f\n", tree[1].len, (A[i+1].x - A[i].x));
			res += tree[1].len * (A[i+1].x - A[i].x);
		}
		printf("Total explored area: %.2f\n", res);
	}
	
}


