#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 3e3 + 10;
int a[maxn], b[maxn], all[maxn*2];
struct node{
	node (int _x, int _y){this->x = _x, this->y = _y;}
	int x, y;
	bool operator < (const node &oth){
		if(x == oth.x) return y < oth.y;
		if(y == oth.y) return y < oth.y;
		return x <oth.x & y < oth.y;
	}
}dp[2][maxn*2];

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, 1, n+1) scanf("%d", &a[i]), all[i] = a[i];
	rep(i, 1, n+1) scanf("%d", &b[i]), all[i+n] = b[i];
	sort(all+1, all+1+2*n);
	int m = unique(all+1, all+1+2*n) - all -1;
	rep(i, 1, n+1) a[i] = lower_bound(all+1, all+1+m, a[i]) - all, b[i] = lower_bound(all+1, all+1+m, b[i]) -all;
	
	int l1 = 0, l2 = 0;
	memset(dp, 0, sizeof(dp));
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			if(a[i] != b[j]) continue;
			int dex1 = lower_bound(dp[0]+1, dp[0]+l1+1) - dp[0], dex2 = lower_bound(dp[1]+1, dp[1]+1+l2);
			//dex1 = max(dex1, l1), dex2 = max(dex2, l2);
			int dex = max(dex1, dex2);
		}
	}
}
