#pragma comment(linker,"/STACK:1024000000,1024000000") 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)

int cnct[50][50];
int dp[35][20][310][505];
int fa[35][20][310][505][3];
int water[35] = {0, 8,8,5,10,5,8,10,5,8,8,10,8,5,8,8,8,10,10,8,8,5,5,8,5,10,8,5,5,8,8};
int food[35] = {0, 6,6,7,10,7,6,10,7,6,6,10,6,7,6,6,6,10,10,6,6,7,7,6,7,10,6,7,7,6,6};
int mp[20];
const int day = 30;
const int points = 15;
const int ini = 10000;
const int bonus = 1000;
const int weight = 1200;

void A(int u, int v)
{
	cnct[u][++cnct[u][0]] = v;
	cnct[v][++cnct[v][0]] = u;
}

int main()
{
	A(1, 2);
	A(2, 3);
	A(3, 4);
	A(4, 5);
	A(5, 6);
	A(6, 7);
	A(7, 8);
	A(8, 9);
	A(9, 10);
	A(10, 11);
	A(10, 14);
	A(11, 14);
	A(11, 12);
	A(11, 13);
	A(12, 13);
	A(13, 14);
	A(13, 15);
	A(14, 15);
	memset(dp, -1, sizeof(dp));
	memset(mp, 0, sizeof(mp));
	int res = -1;
	mp[9] = mp[12] = 1;//´å×¯
	mp[8] = mp[11] = 2;//¿óÉ½ 
	int days;
	
	for(int i= 0 ; i <= 300; i++)
		for(int j = 0; j <= 500; j++){
			if(3*i + 2*j > weight) break;
			dp[0][1][i][j] = ini - 5*i  - 10*j;
			if(dp[0][1][i][j] < 0) break;
		}
	
	for(int i = 0; i < day; i++){
		printf("%d\n", i);
		for(int j = 1; j <= points; j++) 
			for(int w = 0; w <= 300; w++)
				for(int f = 0; f <= 500; f++){
					if(dp[i][j][w][f] < 0) continue;
					if(3*w+2*f > weight) break;
					if(j == points){
						if(res < dp[i][j][w][f] + w*5/2 + f*5)	days = i, res = dp[i][j][w][f] + w*5/2 + f*5;
						continue;
					}
					
					if(w >= water[i+1] && f >= food[i+1] && dp[i+1][j][w-water[i+1]][f-food[i+1]] < dp[i][j][w][f])
						fa[i+1][j][w-water[i+1]][f-food[i+1]][0] = j, fa[i+1][j][w-water[i+1]][f-food[i+1]][1] = w, fa[i+1][j][w-water[i+1]][f-food[i+1]][2] = f,
						dp[i+1][j][w-water[i+1]][f-food[i+1]] = dp[i][j][w][f];
					if(mp[j] == 2 && w>=water[i+1]*3 && f>=food[i+1]*3&& dp[i+1][j][w-water[i+1]*3][f-food[i+1]*3] < dp[i][j][w][f] + bonus)
						dp[i+1][j][w - water[i+1]*3][f - food[i+1]*3] = dp[i][j][w][f] + bonus,
						fa[i+1][j][w - water[i+1]*3][f - food[i+1]*3][0] = j, fa[i+1][j][w - water[i+1]*3][f - food[i+1]*3][1] = w, fa[i+1][j][w - water[i+1]*3][f - food[i+1]*3][2] = f;
						
					if(w>=water[i+1]*2 && f>=food[i+1]*2 && water[i+1] < 10){
						for(int k = 1; k <= cnct[j][0]; k++){
							if(mp[cnct[j][k]] == 1){
								for(int m = 0; m <= 300-w+water[i+1]*2; m++)
									for(int n = 0; n <= 500-f+food[i+1]*2; n++){
										if(m * 10 + n*20 > dp[i][j][w][f] || 3*(m+w-water[i+1]*2) + 2*(n+f-food[i+1]*2) > weight) break;
										if(dp[i+1][cnct[j][k]][m+w-water[i+1]*2][n+f-food[i+1]*2] < dp[i][j][w][f] - m*10 - n*20)
											dp[i+1][cnct[j][k]][m+w-water[i+1]*2][n+f-food[i+1]*2] = dp[i][j][w][f] - m*10 - n*20,
											fa[i+1][cnct[j][k]][m+w-water[i+1]*2][n+f-food[i+1]*2][0] = j,
											fa[i+1][cnct[j][k]][m+w-water[i+1]*2][n+f-food[i+1]*2][1] = w,
											fa[i+1][cnct[j][k]][m+w-water[i+1]*2][n+f-food[i+1]*2][2] = f;										
									}

							}
							
							else 
								if (dp[i+1][cnct[j][k]][w-water[i+1]*2][f-food[i+1]*2] < dp[i][j][w][f])
									dp[i+1][cnct[j][k]][w-water[i+1]*2][f-food[i+1]*2] = dp[i][j][w][f],
									fa[i+1][cnct[j][k]][w-water[i+1]*2][f-food[i+1]*2][0] = j,
									fa[i+1][cnct[j][k]][w-water[i+1]*2][f-food[i+1]*2][1] = w,
									fa[i+1][cnct[j][k]][w-water[i+1]*2][f-food[i+1]*2][2] = f;
						}
					}
				}		
	}
	
	if(res < dp[day][points][0][0]) days = day, res = dp[day][points][0][0];
	printf("%d\n", dp[day][points][0][0]);
	int l = points, w = 0, f = 0;
	while(days){
		printf("day %d: %d %d %d %d\n", days, l, w, f, dp[days][l][w][f]);
		int ll = fa[days][l][w][f][0], ww = fa[days][l][w][f][1], ff = fa[days][l][w][f][2];
		l = ll, w = ww, f = ff, days--;
	}
	
	printf("%d\n", res);
}
