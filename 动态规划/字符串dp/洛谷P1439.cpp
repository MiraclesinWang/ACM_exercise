#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) x&(-x)
const int maxn = 1e5 + 10;
int t[maxn], dp[maxn*8];
int query(int l, int r, int dex, int x, int y)
{
	if(l >= x && r <= y) return dp[dex];
	else if(l > y || r < x) return 0;
	else{
		int mid = (l+r) >> 1;
		return max(query(l, mid, dex*2, x, y), query(mid+1, r, dex*2+1, x, y));
	}
}
void update(int l, int r, int dex, int val, int x)
{
	if(l <= x && r >= x){
		dp[dex] = max(dp[dex], val);
		if(l != r){
			int mid = (l+r) >> 1;
			update(l, mid, dex*2, val, x), update(mid+1, r, dex*2+1, val, x);			
		}
	}
	else return;
}

int main()
{
	int n, res = 0, tmp;
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++) scanf("%d", &tmp), t[tmp] = i;
	for(int i = 1; i <= n; i++){
		scanf("%d", &tmp);
		int tt = query(1, n, 1, 1, t[tmp]) + 1;
		update(1, n, 1, tt, t[tmp]);
		res = max(res, tt);
	}
	printf("%d\n", res);
 } 
