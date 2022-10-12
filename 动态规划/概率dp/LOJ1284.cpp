#include <bits/stdc++.h>
using namespace std;

double dp[10][2];
#define rep(x, y) for(int l = x; l < y; l++)

struct matrix{
	double lu, ru, ld, rd;
	matrix(double _lu, double _ru, double _ld, double _rd)
	{this->lu = _lu, this->ld = _ld, this->rd =_rd, this->ru =_ru;}
	matrix operator * (const matrix &oth){
		matrix res(0.0, 0.0, 0.0, 0.0);
		res.lu = lu * oth.lu + ru * oth.ld;
		res.ld = ld * oth.lu + rd * oth.ld;
		res.ru = lu * oth.ru + ru * oth.rd;
		res.rd = ld * oth.ru + rd * oth.rd;
		return res;
	}
};

double qp(double p, int k)
{
	struct matrix res(1.0, 0.0, 0.0, 1.0);
	struct matrix tmp(1.0 - p, p, p, 1.0 - p);
	while(k){
		if(k&1) res = tmp*res;
		k >>= 1; tmp = tmp * tmp;
	}
	return res.ld;
}

double p_calc(int i, int x)
{return 1.0 - double(i-1) * double(i-1) / double(x)/double(x) - double(x-i)*double(x-i) / double(x)/double(x);}

int main()
{
	int t, x, y, z, k;
	scanf("%d", &t);
	rep(1, t+1){
		scanf("%d%d%d%d", &x, &y, &z, &k);
		double res = 0.0;
		for(int i = 1; i <= x; i++){
			double px = p_calc(i, x);
			for(int j = 1; j <= y; j++){
				double py = p_calc(j, y);
				for(int m = 1; m <= z; m++){
					double pz = p_calc(m, z);
					res += qp(px*py*pz, k);
					//printf("%d %d %d %f\n", i, j, m, res);
				}
			}		
		}	
		printf("Case %d: %.8f\n", l, res);
	}
}
