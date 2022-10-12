#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
int c[maxn*30], ls[maxn*30], rs[maxn*30], T[maxn];
int a[maxn], b[maxn];
int m, n, q, cnt;

void init()
{
	cnt = -1;
	for(int i = 1; i <= n; i++)
		b[i] = a[i];
	sort(b+1, b+1+n);
	m = unique(b+1, b+1+n) - b -1;
}

int build(int l, int r)
{
	c[++cnt] = 0;
	int rt = cnt;
	if(l != r){
		int mid = (l+r) >> 1;
		ls[rt] = build(l, mid);
		rs[rt] = build(mid+1, r);
	}
	return rt;
}

int update(int rt, int pos, int val)
{
	c[++cnt] = c[rt] + val;
	int res, nrt;
	res = nrt = cnt;
	int l = 1, r = m;
	while(l != r){
		int mid = (l + r) >> 1;
		if(pos <= mid){
			ls[nrt] = ++cnt, rs[nrt] = rs[rt];
			nrt = ls[nrt], rt = ls[rt];
			r = mid;
		}
		else{
			ls[nrt] = ls[rt], rs[nrt] = ++cnt;
			nrt = rs[nrt], rt = rs[rt];
			l = mid+1;
		}
		c[nrt] = c[rt] + val;
	}
	return res;
}

int query(int lrt, int rrt, int k)
{
	int l = 1, r = m;
	while(l != r){
		int mid = (l+r) >> 1;
		if(c[ls[lrt]] - c[ls[rrt]] >= k){
			r = mid;
			lrt = ls[lrt], rrt = ls[rrt];
		}
		else{
			k -= c[ls[lrt]] - c[ls[rrt]];
			l = mid+1;
			lrt = rs[lrt], rrt = rs[rrt];
		}
	} 
	return b[l];
}

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	init();
	T[n+1] = build(1, m);
	for(int i = n; i; i--){
		int pos = lower_bound(b+1, b+1+m, a[i]) - b;
		T[i] = update(T[i+1], pos, 1);
	}
	for(int i = 1; i <= q; i++){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(T[l], T[r+1], k));
	}
}
