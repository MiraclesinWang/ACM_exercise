#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define req(m, n) for(int i = m; i < n; i++)
struct question{
	ll maxpoint, decrease;
	int time;
	bool operator <(const question &oth){
		//if(oth.decrease == decrease) return time < oth.time;
		return decrease*1.0 / time > oth.decrease*1.0/oth.time;
	}
} q[60]; 
ll dp[60][100000+10];

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	req(1, n+1) scanf("%lld", &q[i].maxpoint);
	req(1, n+1) scanf("%lld", &q[i].decrease);
	req(1, n+1) scanf("%d", &q[i].time);
	sort(q+1, q+1+n);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	req(0, n)
		for(int j = 0; j <= t; j++){
			if (dp[i][j] < 0) continue;
			dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
			if(j+q[i+1].time <= t)
				dp[i+1][j+q[i+1].time] = max(dp[i][j] + q[i+1].maxpoint - q[i+1].decrease * ll(j+q[i+1].time), dp[i+1][j+q[i+1].time]);
			
		}
	ll res = 0;
	req(0, t+1) res = max(res, dp[n][i]);
	printf("%lld\n", res);
}
