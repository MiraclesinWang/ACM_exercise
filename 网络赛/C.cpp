#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int num[maxn], dp[maxn][5], e[maxn], tree[maxn*8], tr[maxn*8];
int s[maxn], t[maxn];
int n, q, m = 0;

void build(int l, int r, int dex)
{
	if(l == r) tree[dex] = e[l];
	else{
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex] = tree[dex*2]+ tree[dex*2+1];
	}
}
int query(int l, int r, int dex, int x, int y)
{
	if(l>=x && r<= y) return tree[dex];
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r)>>1;
		return query(l, mid, dex*2, x, y)+query(mid+1, r, dex*2+1, x, y);
	}
}

void Build(int l, int r, int dex)
{
	if(l == r) tr[dex] = t[l]-s[l]-3-query(1, n, 1, s[l], t[l]);
	else{
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex] = min(tree[dex*2], tree[dex*2+1]);
	}
}
int Query(int l, int r, int dex, int x, int y)
{
	if(l>=x && r<= y) return tree[dex];
	else if(l > y || r < x) return 1e9;
	else{
		int mid = (l+r)>>1;
		return min(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
	}
}

int main()
{
	memset(e, 0, sizeof(e));
	char c;
	scanf("%d%d\n", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%c", &c), num[i] = c-'0';
	dp[n+1][0] = dp[n+1][1] = dp[n+1][2]= 1e9;
	for(int i = n; i; i--){
		dp[i][0] = dp[i+1][0];
		dp[i][1] = dp[i+1][1];
		dp[i][2] = dp[i+1][2];
		if(num[i] == 2) dp[i][0] = i;
		else if(num[i] == 0) dp[i][1] = dp[i+1][0];
		else if(num[i] == 1) dp[i][2] = dp[i+1][1];
		else if(num[i] == 9) s[++m] = i, t[m] = dp[i+1][2];
		else if(num[i] == 8)
			if(num[i+1] == 1 && num[i+2] == 0 && num[i+3] == 2) e[i] = 1;
	}
	for(int i = 1; i < m/2; i++){
		int tmp = s[i];
		s[i] = s[n+1-i], s[n+1-i] = tmp;
		tmp = t[i];
		t[i] = t[n+1-i], t[n+1-i] = tmp;
	}
	//printf("%d %d\n", s[1], t[1]);
	build(1, n, 1); Build(1, m, 1);
	int l, r,a, b;
	while(q--){
		scanf("%d%d", &l, &r);
		if(l > s[m]) {printf("-1\n");continue;}
		a = lower_bound(s+1, s+1+m, l) - s;
		if(a >= r) {printf("-1\n");continue;}
		if(r > s[m]) b = m;
		else b = lower_bound(s+1, s+1+m, r)-s -1;
		if(t[a] > r) {printf("-1\n");continue;}
		int aa = a, bb = b;
		while(aa != bb){
			int mid = (aa+bb+1)>>1;
			if(t[mid] > r) bb = mid-1;
			else aa = mid;
		}
		int res = Query(1, m, 1, a, aa) + query(1, n, 1, l, r-3);
		printf("%d\n", res);
	}
}
