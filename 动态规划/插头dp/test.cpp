//#pragma comment (linker, "/STACK:1024000000, 1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define pt(x) (int)pow(3, x)
ll dp[13][12][5314][3];
int mp[15][15], Thr[20];
int incl(int s, int i)
{return s%Thr[i+1]/Thr[i];}

int main()
{
	Thr[0] =1;
	for(int i = 1; i < 13; i++) Thr[i] = Thr[i-1]*3;
	char c;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for(int j = 0; j < m; j++)
			scanf("%c", &c), mp[i][j] = (c=='.');
	}
	memset(dp, 0ll, sizeof(dp));
	dp[0][m-1][0][0] = 1;
	int s = pt(m);
	for(int i = 1; i <= n; i++){
		if(mp[i][0]){
			for(int k = 0; k < s; k++){
				if(k%3==1) continue;
				if(k%3==2){
					dp[i][0][k][0] += dp[i-1][m-1][k][0];
					dp[i][0][k-2][2] += dp[i-1][m-1][k][0];
				}
				else dp[i][0][k+2][2] += dp[i-1][m-1][k][0];
			}
		}
		else
			for(int k = 0; k < s; k++)
				if(!(k%3)) dp[i][0][k][0] = dp[i-1][m-1][k][0];
				
		for(int j = 1; j < m; j++){
			if(mp[i][j]){
				for(int k = 0; k < s; k++){
					if(!incl(k, j)){
						dp[i][j][k][1] += dp[i][j-1][k][1];
						dp[i][j][k][2] += dp[i][j-1][k][2];
						dp[i][j][k+2*pt(j)][2] += dp[i][j-1][k][2];
						dp[i][j][k+pt(j)][1] += dp[i][j-1][k][1];
						dp[i][j][k+2*pt(j)][1] += dp[i][j-1][k][0];
					}
					else if(incl(k, j) == 2){
						dp[i][j][k][0] += dp[i][j-1][k][0];
						dp[i][j][k-2*pt(j)][2] += dp[i][j-1][k][0];
						dp[i][j][k-2*pt(j)][0] += dp[i][j-1][k][1];
					}
					else{
						dp[i][j][k][0] += dp[i][j-1][k][0];
						dp[i][j][k-pt(j)][1] += dp[i][j-1][k][0];
					}
				}
			}
			else
				for(int k = 0; k < s; k++)
					if(!incl(k, j)) dp[i][j][k][0] = dp[i-1][m-1][k][0];
		}
		
		if(mp[i][m-1]){
			for(int k = 0; k < s; k++){
				if(incl(k, m-1) == 1)
					dp[i][m-1][k][0] += dp[i][m-2][k][0];
				else if(!incl(k, m-1))
					dp[i][m-1][k+pt(m-1)][0] += dp[i][m-2][k][1];
			}
		}
	}
	for(int i = n; i; i--){
		for(int j = m-1; j > -1; j--){
			if(mp[i][j]){
				if(!j) printf("0\n");
				else{
					ll res = 0;
					for(int k = 0; k < s; k++)
						if(incl(k, j) == 1) res += dp[i][j-1][k][2];
					printf("%lld\n", res);
				}
				return 0;
			}
		}
	}
} 
