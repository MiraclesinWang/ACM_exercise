#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

const int maxn = 510;
struct node{
	int cnt;
	double len;
} tree[maxn*8];
struct lne{
	int val;
	double x, d, u;
	int s, e;
	bool operator < (const lne &oth) const
	{return x < oth.x;}
}l[maxn];
double ally[maxn*2];
int n, m;

void build(int l, int r, int dex)
{
	tree[dex].cnt = 0; tree[dex].len = 0;
	if(l != r){
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
void update(int l, int r, int dex, int x, int y, int val)
{
	if(l>= x && r<= y)
		tree[dex].cnt += val;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r)>>1;
		update(l, mid, dex*2, x, y, val), update(mid+1, r, dex*2+1, x, y, val);
	}
	if(tree[dex].cnt > 0) tree[dex].len = ally[r+1] - ally[l];
	else tree[dex].len = (l==r?0:tree[dex*2].len+tree[dex*2+1].len);	
}

void solve(int cnt)
{
	double res = 0;
	double x1, x2, y1, y2;
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		l[i*2-1].x = x1, l[i*2-1].val = 1;
		l[i*2].x = x2, l[i*2].val = -1;
		l[i*2-1].u = l[2*i].u = y2, l[2*i-1].d = l[2*i].d = y1;
		ally[2*i-1] = y1, ally[2*i] = y2;
	}
	sort(ally+1, ally+1+2*n);
	m = unique(ally+1, ally+1+2*n) - ally -1;
	for(int i = 1; i <= n; i++){
		l[i*2-1].s = lower_bound(ally+1, ally+1+m, l[i*2-1].d)-ally;
		l[i*2-1].e = lower_bound(ally+1, ally+1+m, l[2*i-1].u)-ally;
		l[i*2].s = l[i*2-1].s, l[2*i].e = l[i*2-1].e;
	}
	build(1, m-1, 1);
	sort(l+1, l+1+2*n);
	update(1, m-1, 1, l[1].s, l[1].e-1, l[1].val);
	for(int i = 2; i <= 2*n; i++){
		res += tree[1].len*(l[i].x - l[i-1].x); 
		update(1, m-1, 1, l[i].s, l[i].e-1, l[i].val);
	}
	printf("Test case #%d\nTotal explored area: %.2f\n\n", cnt, res);
}

int main()
{
	int cnt = 1;
	while(scanf("%d", &n), n) solve(cnt++);
}
