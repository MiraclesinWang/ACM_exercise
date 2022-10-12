#include <bits/stdc++.h>
using namespace std;

int main()
{
	int kase;
	double u, v, w, l;
	scanf("%d", &kase);
	while(kase--){
		scanf("%lf%lf%lf%lf", &u, &v, &w, &l);
		printf("%.3f\n", l/(u+v)*w);
	}
}
