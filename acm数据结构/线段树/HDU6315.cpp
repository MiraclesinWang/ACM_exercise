#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
#define ll long long

int sm[maxn*4], mn[maxn*4], lzy[maxn*4];
int b[maxn*4];
int n, m, cnt;
int d[maxn];
char cmd[10];

void build(int dex, int l, int r)
{
	sm[dex] = 0, lzy[dex] = 0;
	if(l == r) mn[dex] = b[++cnt], d[dex] = cnt;
	else{
		int mid = (l + r) >> 1;
		build(dex * 2, l ,mid);
		build(dex * 2 + 1, mid + 1, r);
		mn[dex] = min(mn[dex * 2], mn[dex *2 +1]);
	}
}

void change(int dex,int l, int r, int x, int y)
{
	if(l >= x && r <= y) mn[dex] -= 1, lzy[dex] += 1;
	else if(l > y || r < x) return;
	else{
		int mid = (l + r) >> 1;
		change(dex*2, l, mid, x, y),
		change(dex*2 + 1, mid + 1, r, x, y);
	}
}

void update(int dex, int val)
{
	while(dex){
		sm[dex] += val;
		mn[dex] = min(mn[dex*2], mn[dex*2 + 1]);
	}
}

void pushdown(int dex, int l, int r)
{
	if(mn[dex] > 0) return;
	if(l == r){
		int val = (-mn[dex]) / b[d[dex]] + 1;
		mn[dex] = (-mn[dex]) % b[d[dex]];
		sm[dex] += val;
		update(dex >> 1, val);
	}
	else{
		int mid = (l + r) >> 1;
		lzy[dex*2] += lzy[dex], lzy[dex*2 + 1] += lzy[dex];
		mn[dex*2] -= lzy[dex], mn[dex*2 + 1] -= lzy[dex];
		lzy[dex] = 0;
		pushdown(dex * 2, l, mid), pushdown(dex *2 +1, mid + 1, r);
	}
}

int query(int dex,int l, int r, int x, int y)
{
	if(l >= x && r <= y){
		pushdown(dex, l, r);
		return sm[dex];
	}
	else if(x > r || y < l) return 0;
	else{
		int mid = (l + r) >> 1;
		return query(dex * 2, l, mid, x, y) + query(dex *2 + 1, mid +1, r, x, y);
	}
}

void solve()
{
	int x, y;
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	cnt = 0;
	build(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("\n%s%d%d", cmd, &x, &y);
		if(cmd[0] == 'a')
			change(1, 1, n, x, y);
		else
			printf("%d\n", query(1, 1, n, x, y));
		for(int i = 1; i <= 10; i++) printf("%d ", sm[i]);
		printf("\n"); 
		for(int i = 1; i <= 10; i++) printf("%d ", mn[i]);
		printf("\n"); 
		for(int i = 1; i <= 10; i++) printf("%d ", lzy[i]);
		printf("\n"); 
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
		solve();
}
