#include <cstdio>
#include <cmath>
using namespace std;
double p,q,r,s,t,u;
double cal(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	double f,g,mid;
	while (scanf ("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)!=EOF) {
		if(cal(0)<0||cal(1)>0)
			printf ("No solution\n");
		else{
			g=0,f=1;
			while (f-g>1e-8){
				mid=(f+g)/2;
				if(cal(mid)<0) f=mid;
				else g=mid;
			}
			printf("%.4lf\n",mid);	
		}
	}
}
