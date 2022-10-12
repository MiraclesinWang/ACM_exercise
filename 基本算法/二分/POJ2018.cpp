#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 1e5 + 10;
int n, f;
double a[maxn], b[maxn];

int main()
{
	scanf("%d%d", &n, &f);
	rep(i, 1, n+1) scanf("%lf", &a[i]);
	double l = 0, r = 2000;
	while(l + 1e-8 < r){
		b[0] = 0;
		double mid = (l+r) /2, s = 0, minval = 1e6;
		rep(i, 1, n+1) b[i] = a[i] - mid + b[i-1];
		rep(i, f, n+1) minval = min(minval, b[i-f]), s = max(s, b[i]-minval);
		if(s > 0) l = mid;
		else r = mid;
	}
	printf("%f\n", int(r*1000));
}

