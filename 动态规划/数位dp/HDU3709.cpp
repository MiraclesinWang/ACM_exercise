//HDU3709
#include <cstdio>
#include <cstring>
using namespace std;

#define ll long long
ll dp[20][10][20][3000], tp[20][4000];
ll fp[20][20][3000];
const ll lmt = 1e18-1;
int num[20];

ll query(ll x)
{
	ll res = 0;
	int tmp = 0, m = 0;
	if(x >= lmt) x = lmt;
	//if(x < 0) return -1;
	for(int i = 0; i < 18; i++)
		num[i] = (int)(x%10), x /= 10;
	for(int i = 17; i >= 0; i--){
		for(int j = 0; j < num[i]; j++)
			for(int k = 0; k <= i; k++)
				res += dp[i][j][k][1500+tmp+m*(i-k)];
		m += num[i];
		tmp += m;					
	}
	return res;
}

void init()
{
	memset(dp, 0, sizeof(dp));
	memset(tp, 0, sizeof(tp));
	memset(fp, 0, sizeof(fp));
	tp[0][0] = 1;
	for(int i = 1; i < 18; i++)
		for(int j = 0; j < 10; j++)
			for(int k = i*j; k < 1500; k++)
				tp[i][k] += tp[i-1][k-i*j];
	for(int i = 0; i < 10; i++) dp[0][i][0][1500] = 1;
	fp[0][0][1500] = 10;
	for(int i = 1; i < 18; i++)
		for(int k = 0; k < 1500; k++)
			for(int j = 0; j < 10; j++)
				dp[i][j][i][k+1500] = tp[i][k],
				fp[i][i][k+1500] += tp[i][k];
	for(int i = 1; i < 18; i++)
		for(int j = 0; j < 10; j++)
			for(int p = 0; p < i; p++)
				for(int k = 0; k < 3000; k++)
					dp[i][j][p][k] += fp[i-1][p][k+(i-p)*j],
					fp[i][p][k] += fp[i-1][p][k+(i-p)*j];
}

int main()
{
	init();
	int t;
	ll a, b;
	while(scanf("%lld", &a) != EOF)
		printf("%lld\n", query(a));
	/*scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%lld%lld", &a, &b);
		printf("%lld", query(b+1)-query(a));
	}*/
}
