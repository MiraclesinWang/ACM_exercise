#include <cstdio>
#include <cstring> 
#include <cmath> 
using namespace std;

int dp[10][10][13][2]; 
int tmp[10]; 
int t[10]; 

void init()
{
	memset(dp, 0, sizeof(dp)); 
	for(int i = 0; i < 10; i++)
		dp[0][i][i][0] = 1;
	for(int i = 1; i <= 8; i++){
		for(int j = 0; j < 10; j++){
			for(int m = 0; m < 13; m++){
				int n = (m - (j*t[i])%13 + 13) % 13; 
				for(int k = 0; k < 10; k++){
					dp[i][j][m][1] += dp[i-1][k][n][1],
					dp[i][j][m][0] += dp[i-1][k][n][0];				
				} 
				if(j == 1){
					dp[i][j][m][1] += dp[i-1][3][(m - t[i]%13 + 13)%13][0];
					dp[i][j][m][0] -= dp[i-1][3][(m - t[i]%13 + 13)%13][0]; 
				}
			} 
		} 
	} 
} 

int query(int n)
{
	if(n==1000000000) n -= 1;    //由于1e9就这一个数，没有单独多算一位的意义，就直接把它降位了
	int dex = 0;
	while(n){
		tmp[dex++] = n % 10;
		n /= 10; 
	} 
	tmp[dex--] = 0;  
	int res = 0;
	bool flag = false; 
	int mod = 0;  
	while(dex >= 0){
		if(flag)
			for(int i = 0; i < tmp[dex]; i++)
				res += dp[dex][i][(13-mod)%13][0];
		for(int i = 0; i < tmp[dex]; i++)
			res += dp[dex][i][(13-mod)%13][1];
		if(!flag && tmp[dex+1] == 1 && tmp[dex] > 3) res += dp[dex][3][(13-mod)%13][0]; 
		mod = (mod + t[dex]*tmp[dex]) %13; 
		if(tmp[dex] == 3 && tmp[dex+1] == 1) flag = true;
		dex--; 
	} 
	if(mod == 0 && flag) res++; 
	return res; 
}

int main()
{
	t[0] = 1;
	for(int i = 1; i < 10; i++)
		t[i] = t[i-1] * 10; 
	init(); 
	int n; 
	while(scanf("%d", &n)!=EOF)
		printf("%d\n", query(n));
} 
