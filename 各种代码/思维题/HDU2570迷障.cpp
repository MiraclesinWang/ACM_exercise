#include <bits/stdc++.h>
using namespace std;

int n, v, w;
int p[105];
#define rep(i, x, y) for(int i =x; i < y; i++)

void solve()
{
	scanf("%d%d%d", &n, &v, &w);
	rep(i, 1, n+1) scanf("%d", &p[i]);
	sort(p+1, p+1+n);
	if(p[1] > w) {printf("0 0.00\n");return;}
	int l = 1, r = n;
	rep(i, 2, n+1) p[i] += p[i-1];
	while(l!=r){
		int mid = (l+r+1) >>1;
		double ww = (double)w / 100.0;
		double now = (double)p[mid] / 100.0 / (double)mid;
		if(now <= ww) l = mid;
		else r = mid-1;
	}
	printf("%d %.2f\n", l*v, (double)p[l]/(double)l/100.0);
}

int main()
{
	int kase;
	scanf("%d", &kase); 
	while(kase--){
		solve();
	}
 } 
