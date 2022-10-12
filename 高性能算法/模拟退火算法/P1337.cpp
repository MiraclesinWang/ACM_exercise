#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define eql(a, b) abs(a.x-b.x) < 1e-7 && abs(a.y-b.y) < 1e-7
#define dis(a, b) sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
const int maxn = 1010;

struct node{
	double x, y, m;
}h[maxn];
int n;

int main()
{
	scanf("%d", &n);
	rep(i, 0, n) scanf("%lf%lf%lf", &h[i].x, &h[i].y, &h[i].m);
	double x1 = -1e4, x2 = 1e4, y1 = -1e4, y2 = 1e4;
	node c;
	rep(time, 0, 1000){
		c.x = (x1+x2)/2, c.y = (y1+y2)/2;
		double xx = 0, yy = 0;
		rep(i, 0, n){
			if(eql(c, h[i])) continue; 
			xx += h[i].m*(h[i].x-c.x)/dis(h[i], c);
			yy += h[i].m*(h[i].y-c.y)/dis(h[i], c);
		}
		if(xx > 0 && yy > 0) x1 = c.x, y1 = c.y;
		else if(xx <= 0 && yy <= 0) x2 = c.x, y2 = c.y;
		else if(xx <= 0 && yy > 0) x2 = c.x, y1 = c.y;
		else x1 = c.x, y2 = c.y;
		if(abs(xx) < 1e-7) x1 = x2 = c.x;
		if(abs(yy) < 1e-7) y1 = y2 = c.y;
	}
	printf("%.3f %.3f\n", x1, y1);
}
