#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
char in[50];
double p,q,r,s,t,u;
double cal(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	double res,s,e,mid,f,g,tmp;
	while(cin.getline(in,50)){
		s=0,e=1,f,g;
		sscanf(in,"%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u);
		printf("%lf %lf %lf %lf %lf %lf\n",p,q,r,s,t,u);
		f=cal(0),g=cal(1);
		printf("%lf %lf\n",cal(0),cal(1));
		if(f*g>0) {printf("No solution\n");continue;}
		while(e-s>0.000001){
			mid=(s+e)/2.0;
			tmp=cal(mid);
			if(tmp>0) s=mid,f=tmp;
			else e=mid,g=tmp;
		}
		printf("%.4f\n",e);
	}
}
