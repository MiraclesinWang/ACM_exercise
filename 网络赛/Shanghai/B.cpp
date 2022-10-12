#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 2e3 + 10;
int a[maxn], l[maxn], r[maxn], b[maxn], tree[maxn*8];

void build(int l, int r, int dex)
{
	tree[dex] = 0;
	if(l != r){
		int mid = (l+r) >> 1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
	}
}
void change(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) tree[dex]++;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r) >> 1;
		change(l, mid, dex*2, x, y), change(mid+1, r, dex*2+1, x, y);
	}
}
int pushdown(int l, int r, int dex)
{
	if(l == r) return (tree[dex]%2==1?b[l]:0);
	tree[dex*2]+= tree[dex], tree[dex*2+1] += tree[dex];
	int mid = (l+r) >> 1;
	return pushdown(l, mid, dex*2) + pushdown(mid+1, r, dex*2+1);
}

int main()
{
	int t, n, q;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++){
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= q; i++) scanf("%d%d", &l[i], &r[i]), a[i] = l[i]-1, a[i+q] = r[i], l[i]--;
		sort(a+1, a+1+q*2);
		int m = unique(a+1, a+1+2*q) - a - 1;
		build(1, m, 1);
		b[1] = a[1]+1;
		for(int i = 2; i <= m; i++) b[i] = a[i] - a[i-1];
		for(int i = 1; i <= q; i++){
			int x = lower_bound(a+1, a+1+m, l[i]) - a, y = lower_bound(a+1, a+1+m, r[i]) - a;
			change(1, m, 1, x+1, y);			
		}
		printf("Case #%d: %d\n", kase, pushdown(1, m, 1));
	}
}
