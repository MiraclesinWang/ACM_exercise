#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)

int cnct[50][50];
int dp[35][30][410][610];
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
	mp[12] = 1; // ��ɽ 
	mp[15] = 2; //��ׯ 
	int res = -1;
	
	for(int i = 0; i <= 400 - 8; i++)
		for(int j = 0; j <= 600 - 6; j++){
			dp[1][1][i][j] = 10000 - (i+8) * 5 - (j+6) * 10;
			if(dp[1][1][i][j] < 0) break;
		}
	
	for(int i = 1; i < 30; i++){
		for(int j = 1; j <= points; j++){
			for(int m = water[i+1]; m <= 400; m++){
				for(int n = food[i+1]; n <= 600; n++){
					if(!dp[i][j][m][n]) continue;
					if(j == points) {res = max(res, dp[i][j][m][n]); continue;}
					
					dp[i+1][j][m - water[i+1]][n - food[i+1]] = max(dp[i+1][j][m - water[i+1]][n - food[i+1]], dp[i][j][m][n]);
					if(m >= water[i+1]*2 && n >= food[i+1]*2 && water[i+1]<10)
						for(int k = 1; k <= cnct[j][0]; k++)
							dp[i+1][cnct[j][k]][m - water[i+1]*2][n-food[i+1]*2] = max(dp[i+1][cnct[j][k]][m - water[i+1]*2][n-food[i+1]*2], dp[i][j][m][n]);
					if(mp[j] == 1 && m >= water[i+1]*3 && n >= food[i+1]*3)
						dp[i+1][j][m-water[i+1]*3][n - food[i+1]*3] = max(dp[i+1][j][m-water[i+1]*3][n - food[i+1]*3], dp[i][j][m][n] + 1000);
					else if(mp[j] == 2){
						for(int x = m-water[i+1]; x <= 400; x++){
							for(int y = n-food[i+1]; y <= 600; y++){
								int tmp = dp[i][j][m][n] - 10*(x-m+water[i+1]) - 20*(y-n+food[i+1]);
								if(tmp < 0) break;
								dp[i+1][j][x][y] = max(dp[i+1][j][x][y], tmp);								
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i <= 400; i++)
		for(int j = 0; j <= 600; j++)
			res = max(res, dp[day][points][i][j] + i*5/2 + j*5);
	printf("%d\n", res);
}

