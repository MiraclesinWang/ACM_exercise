#include <cstdio>
#include <cmath>
using namespace std;

int dp[15][30], cnt[15][30];
int tmp[30];
int query(int n, int b)
{
	int res = 0, l = 0;
	while(n){
		tmp[l++] = n%b;
		n /= b;
	}
	int t = 0;
	for(int i = l-1; i; i--){
		for(int j = 0; j < tmp[i]; j++)
			res += ((t+j)*cnt[b][i-1] + dp[b][i-1]);	
		t += tmp[i];	
	}
	res += t*(tmp[0]+1) + (tmp[0]+1)*tmp[0]/2;
	return res;
}

int main()
{
	for(int i = 2; i <= 10; i++){
		int len = log(1e6)/log(i) + 1;
		cnt[i][0] = i;
		for(int j = 1; j <= len; j++) 
			cnt[i][j] = i*cnt[i][j-1];
	}
	for(int i = 2; i <= 10; i++){
		int len = log(1e6)/log(i) + 1;
		dp[i][0] = i*(i-1)/2;
		for(int j = 1; j <= len; j++) 
			dp[i][j] = i*dp[i][j-1] + cnt[i][j-1]*i*(i-1)/2;
	}
	/*for(int i = 1; i <= 3; i++) printf("%d ", dp[2][i]);
	printf("\n");*/
	int t, b, n;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &n, &b);
		printf("Case #%d: %d\n", i, query(n, b));
	}
 } 
