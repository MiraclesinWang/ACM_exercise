#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int dp[10][10], tp[10][10][10], t[10], nb[10], b[10], res[10], ans[10];
void init()
{
	t[0] = 1;
	for(int i = 1; i < 10; i++) t[i] = 10*t[i-1];
	memset(dp, 0, sizeof(dp));
	memset(tp, 0, sizeof(tp));
	for(int i = 0; i < 10; i++) tp[0][i][i] = 1;
	dp[0][0] = 1;
	for(int i = 1; i < 9; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				for(int p = 0; p < 10; p++)
					tp[i][j][k] += tp[i-1][p][k];
				if(j == k) tp[i][j][k] += t[i];		
			}
		}
	}
	
	for(int i = 1; i < 9; i++){
		for(int j = 0; j < 10; j++){
			for(int p = 0; p < 10; p++){
				if(j) dp[i][j] += tp[i-1][p][0];
				else dp[i][j] += dp[i-1][p];	
			}
		}
	}
}
int query(int n)
{
	int cnt = -1, cpy = n;
	memset(res, 0, sizeof(res));
	if(!n){res[0] = 1; return 0;}
	while(n){
		nb[++cnt] = n % 10;
		n /= 10;
	}
	for(int i = cnt; ~i; i--)
		b[i] = cpy%t[i], cpy %= t[i];
	for(int i = cnt; ~i; i--){
		for(int j = 0; j < nb[i]; j++){
			for(int k = 0; k < 10; k++)
				res[k] += tp[i][j][k];
			//res[0] += dp[i][j];			
		}
		res[nb[i]] += b[i] +1;
		//printf("%d\n", res[1]);
	}
	for(int j = 0; j < nb[cnt]; j++)
		res[0] += dp[cnt][j] - tp[cnt][j][0];
}

int main()
{
	//freopen("test.txt", "r", stdin); 
	init();
	int n, m;
	while(scanf("%d%d", &n, &m), n&&m){
		if(m < n) swap(n, m);
		query(m);
		for(int i = 0; i < 10; i++) ans[i] = res[i];
		query(n-1);
		for(int i = 0; i < 10; i++)
			printf("%d", ans[i] - res[i]), printf(i==9?"\n":" ");
		
	}
}
