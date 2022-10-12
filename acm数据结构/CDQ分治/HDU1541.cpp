#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i < y; i++)
const int maxn = 15000 + 10;

struct elem{
	int a, b, cnt;
} E[maxn], tmp[maxn];
int cnt[maxn], ans[maxn];

void solve(int l, int r)
{
	if(l==r) return;
	int mid = (l+r) >> 1;
	solve(l, mid), solve(mid+1, r);
	int d1 = l, d2 = mid+1;
	for(int i = l; i <= r; i++){
		if(d1 > mid || (d2 <= r && E[d1].b > E[d2].b)){
			E[d2].cnt += d1-l;
			tmp[i] = E[d2++];
		} 
		else{
			tmp[i] = E[d1++];
		}
	}
	rep(i, l, r+1) E[i] = tmp[i];

}

int main()
{
	
	int n;
	while(~scanf("%d", &n)){
		memset(cnt, 0, sizeof(cnt));
		rep(i, 0, n){
			scanf("%d%d", &E[i].b, &E[i].a);
			E[i].cnt=0;
		}
		solve(0, n-1);
		rep(i, 0, n) cnt[E[i].cnt]++;
		rep(i, 0, n){
			printf("%d\n", cnt[i]);
		}
	}

} 
