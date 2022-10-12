#include <bits/stdc++.h>
using namespace std;

bool dp[50][360*1000 + 10];
char cmd[20];
int turn[50];
#define rep(a, b) for(int i = a; i < b; i++)
const double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172;

int main()
{
	int n, t = 0;
	double tmp, forward = 0.0, backward = 0.0;
	scanf("%d", &n);
	rep(1, n+1){
		scanf("\n%s %lf", cmd, &tmp);
		if(cmd[0] == 'f') forward += tmp;
		if(cmd[0] == 'b') backward += tmp;
		int tt = round(tmp*1000.0);
		if(cmd[0] == 'l') turn[++t] = tt;
		if(cmd[0] == 'r') turn[++t] = 360*1000 - tt;
	}
	if(!t){
		printf("%f\n", abs(backward + forward));
		return 0;
	}
	memset(dp, false, sizeof(dp));
	dp[1][0] = dp[1][turn[1]] = true;
	rep(2, t+1){
		for(int j = 0; j < 360*1000; j++)
			if(dp[i-1][j]) dp[i][(j+turn[i])%360000] = dp[i][j] = true;
	}
	double angel;
	for(int i = 0; i < 180*1000; i++)
		if(dp[t][180000-i] || dp[t][180000+i]) angel = (double)i / (double) 180000 * pi;
	double x = forward + backward*cos(angel);
	double y = backward*sin(angel);
	printf("%.10f\n", sqrt(x*x+y*y));
}
