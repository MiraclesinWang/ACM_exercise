#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
double dp[60][60], kp[60][60], mat[3][3], com[3];

int main()
{
	int kase, w, f;
	double p;
	scanf("%d", &kase);
	for(int k = 1; k <= kase; k++){
		scanf("%lf %d %d", &p, &w, &f);
		
		if(w == 1 && f == 1) {printf("Case %d: 1\n", k);continue;}
		if(p < 1e-6) {printf("Case %d: %d\n", k, w);continue;}
		if(1 - p < 1e-6) {printf("Case %d: %d\n", k, f);continue;}
		if(!w || !f){printf("Case %d: 0\n", k);continue;}
		
		dp[w][0] = dp[0][f] = kp[w][0] = kp[0][f] = 0.0;
		for(int i = w-1; i; i--){
			kp[i][0] = kp[i+1][0] * (1.0 - p) + p;
			dp[i][0] = dp[i+1][0] * (1.0 - p) + 1.0;
		}
		for(int i = f-1; i; i--){
			kp[0][i] = kp[0][i+1] * p + 1.0 - p;
			dp[0][i] = dp[0][i+1] * p + 1.0;
		}
		
		mat[0][0] = kp[0][1], mat[0][1] = -1.0, com[0] = -dp[0][1];
		mat[1][0] = -1.0, mat[1][1] = kp[1][0], com[1] = -dp[1][0];
		if(abs(mat[0][0]) < 1e-6) swap(mat[0], mat[1]), swap(com[0], com[1]);
		mat[1][1] -= mat[1][0] * mat[0][1] / mat[0][0];
		com[1] -= mat[1][0] * com[0] / mat[0][0];
		dp[1][0] = com[1] / mat[1][1];
		dp[0][1] = (com[0] - dp[1][0] * mat[0][1]) / mat[0][0];
		dp[0][0] = dp[0][1] * (1-p) + dp[1][0] * p + 1.0;
		printf("Case %d: %.6f\n", k, dp[0][0]);
	}
}
