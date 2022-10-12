#include <cstdio>
#include <cstring>
using namespace std;
double p[60][60];

int main()
{
	//memset(res, 0, sizeof(res));
	int t, n, m;
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= 50; i++){
		p[i][1] = 1;
		for(int j = 1; j < i; j++){
			double tmp = 1.0/(double)(i-j+1)*p[i][j];
			for(int k = j+1; k <= i; k++)
				p[i][k] += tmp;
		}
	}
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= i; j++)
			printf("%f ", p[i][j]);
		printf("\n");
	}
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &n, &m);
		double ans = 0.5;
		int tmp = (m-1)*m/2;
		double k = 1.0/(double)tmp*0.5;
		printf("%f\n", k);
		for(int j = 2; j <= m; j++)
			for(int kk = 2; kk <= j; kk++)
				ans += (double)k*(1.0-p[j][kk]);
		printf("Case #%d: 0.500000 %f\n",i, ans);
	}
}
