#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)

int cnct[50][50];
int dp[35][30][8000];
int water[35] = {8, 8,5,10,5,8,10,5,8,8,5,5,8,5,10,8,5,5,8,8};
int food[35] = {6,6,7,10,7,6,10,7,6,6,7,7,6,7,10,6,7,7,6,6};
int mp[50];
const int day = 30;
const int points = 27;

void A(int u, int v)
{
	cnct[u][++cnct[u][0]] = v;
	cnct[v][++cnct[v][0]] = u;
}

int main()
{
	memset(mp, 0, sizeof(mp));
	memset(dp, -1, sizeof(dp));
	memset(cnct, 0, sizeof(cnct));
	A(1, 2); A(1, 25); A(2, 3); A(3, 4); A(3, 25); A(4, 5); A(4, 24); A(5, 24); A(5, 6); A(6, 24);
	A(6, 23); A(6, 7); A(7, 22); A(7, 8); A(8, 22); A(8, 9); A(9, 22); A(9, 17); A(9, 21); A(9, 16);
	A(9, 10); A(9, 15); A(10, 15); A(10, 11); A(10, 13); A(11, 13); A(11, 12); A(12, 13); A(12, 14);
	A(13, 15); A(13, 14); A(14, 16); A(14, 15); A(15, 16); A(16, 17); A(16, 18); A(17, 21);
	A(17, 18);A(18, 20);A(18, 19);A(19, 20);A(20, 21);A(21, 22);A(21, 23);A(21, 27);A(22, 23);
	A(23, 24);A(24, 25);A(24, 26);A(25, 26);A(26, 27);
	mp[12] = 1; // ¿óÉ½ 
	mp[15] = 2; //´å×¯ 
	int res = -1;
	
	//for(int i = 0; i <= 2000; i++) dp[0][1][i] = 10000 - 5*i;
	dp[1][1][2000-water[1]-food[1]*2] = 0;
	for(int i = 0; i < 30; i++){
		for(int j = 1; j <= points; j++){
			for(int k = 0; k <= 8000; k++){
				if(dp[i][j][k] < 0) continue;
				if(j == points) {res = max(res, dp[i][j][k] + k*10 - 10000); continue;}
				
				dp[i+1][j][k - water[i+1] - food[i+1]*2] = max(dp[i+1][j][k - water[i+1] - food[i+1]*2], dp[i][j][k]);
				if(k >= water[i+1]*2 + food[i+1]*4 && water[i+1] < 10)
					for(int t = 1; t <= cnct[j][0]; t++){
						dp[i+1][cnct[j][t]][k-water[i+1]*2-food[i+1]*4] = max(dp[i+1][cnct[j][t]][k-water[i+1]*2-food[i+1]*4], dp[i][j][k]);
						if(mp[j] == 2) dp[i+1][cnct[j][t]][k-water[i+1]*2-food[i+1]*4 + dp[i][j][k]/10] = max(0, dp[i+1][cnct[j][t]][k-water[i+1]*2-food[i+1]*4 + dp[i][j][k]/10]);
					}
						
				if(mp[j] == 1 && k >= water[i+1] * 3 + food[i+1] *6)
					dp[i+1][j][k-water[i+1]*3-food[i+1]*6] = max(dp[i+1][j][k-water[i+1]*3-food[i+1]*6], dp[i][j][k] + 1000);
				if(mp[j] == 2) dp[i+1][j][k - water[i+1] - food[i+1]*2 + dp[i][j][k]/10] = max(dp[i+1][j][k - water[i+1] - food[i+1]*2 + dp[i][j][k]/10], 0); 
			}
		}
	}
	for(int k = 0; k <= 8000; k++)
		if(dp[day][points][k] >= 0)
			printf("%d %d\n", k, dp[day][points][k]), res = max(res, dp[day][points][k] + k*10-10000);
	printf("%d\n", res);
}
