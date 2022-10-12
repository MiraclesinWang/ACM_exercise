#pragma comment(linker,"/STACK:1024000000,1024000000") 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int day = 10;
const int points = 10;
const int ini = 10000;
const int bonus = 200;
const int weight = 1200;
const int sand = 20;
const float sunny = 0.5;
const float hot = 0.5;
const float storm = 0.0;
const float INF = 1e9;
int water[4] = {3, 9, 10};
int food[4] = {4, 9, 10};
int cnct[50][50], mp[20];
float dp[35][20][305][505];
bool valid[35][20][305][505];
int weather[15] = {0, 0,1,0,0,0,1,1,1,0,1};


void A(int u, int v)
{
	cnct[u][++cnct[u][0]] = v;
	cnct[v][++cnct[v][0]] = u;
}

int main()
{
	A(1,2);
    A(1,8);
    A(2,3);
    A(2,6);
    A(2,8);
    A(3,4); 
    A(4,5);
    A(5,6);
    A(5,7);
    A(5,10);
    A(6,7);
	A(6,9);
	A(7,9);
	A(7,10);
	A(8,9);
	A(9,10);
	mp[4] = 2;
	memset(valid, 0, sizeof(valid));
	memset(dp, -INF, sizeof(dp));
	for(int i = 1; i <= day; i++)
		for(int j = 0; j <=300; j++)
			for(int k = 0; k <= 500; k++){
				if(3*j + 2*k > weight) break;
				dp[i][points][j][k] = (float)j * 5.0 / 2.0 + (float)k * 5.0;
				valid[i][points][j][k] = 1;
			}
	
	for(int i = day-1; i >= 0; i--){
		for(int j = 1; j <= points; j++)
			for(int w = sand; w <= 300; w++)
				for(int f = sand; f <= 500; f++){
					if(3*w + 2*f > weight) break;
					
					if(valid[i+1][j][w-water[0]][f-food[0]] && valid[i+1][j][w-water[1]][f-food[1]])      // ²»¶¯ 
						dp[i][j][w][f] = sunny * dp[i+1][j][w-water[0]][f-food[0]] + hot * dp[i+1][j][w-water[1]][f-food[1]], valid[i][j][w][f] = 1;
						
					for(int k = 1; k <= cnct[j][0]; k++){      //ÒÆ¶¯ 
						int p = cnct[j][k];
						if(w >= water[0]*2 && f >= food[0]*2 && valid[i+1][p][w-water[0]*2][f-food[0]*2]){
							float tmp = sunny * dp[i+1][p][w-water[0]*2][f-food[0]*2];
							if(w >= water[1]*2 && f >= food[1]*2  && valid[i+1][p][w-water[1]*2][f-food[1]*2])
								tmp += hot * dp[i+1][p][w-water[1]*2][f-food[1]*2];
							else tmp += hot * dp[i+1][p][w-water[1]][f-food[1]];
							dp[i][j][w][f] = max(dp[i][j][w][f], tmp);
							valid[i][j][w][f] = 1;
						}
					}
					
					if(mp[j] == 2 && w >= water[0]*3 && f >= food[0]*3 && valid[i+1][j][w-water[0]*3][f-food[0]*3]){   //ÍÚ¿ó 
						float tmp = sunny * dp[i+1][j][w-water[0]*3][f-food[0]*3];
						if(w >= water[1]*3 && f >= food[1]*3 && valid[i+1][j][w-water[1]*3][f-food[1]*3])
							tmp += hot * dp[i+1][j][w-water[1]*3][f-food[1]*3];
						else tmp += hot * dp[i+1][j][w-water[1]][f-food[1]];
						dp[i][j][w][f] = max(dp[i][j][w][f], tmp+bonus);
						valid[i][j][w][f] = 1;
					}
				}
	}
	
	int x, y;
	double res = -INF;
	for(int i = 0; i <= 300; i++)
		for(int j = 0; j <= 500; j++){
			//if (dp[0][1][i][j] > 0.0 && res > 0.0) printf("%f %f %f\n", res, dp[0][1][i][j], dp[0][1][i][j] - 5.0*(float)i - 10.0*(float)j + float(ini));
			if(3*i + 2*j > weight) break;
			if(valid[0][1][i][j] && dp[0][1][i][j] - 5.0*(float)i - 10.0*(float)j + float(ini) > res) res = dp[0][1][i][j] - 5.0*(float)i - 10.0*(float)j + float(ini), x = i, y = j;
		}
	printf("%d %d %f\n", x, y, res);
	int m = ini - x*5 - 10*y;
		
	int days = 0, l  =1;
	while(l != points){
		printf("day %d: %d %d %d %d\n", days, l, x, y, m);
		float tmp = dp[days+1][l][x-water[weather[days+1]]][y-food[weather[days+1]]];
		int xx = x-water[weather[days+1]], yy = y-food[weather[days+1]], ll = l;
		for(int k = 1; k <= cnct[l][0]; k++){
			int p = cnct[l][k];
			if(x>=2*water[weather[days+1]] && y>=2*food[weather[days+1]] && tmp <= dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]]){
				//printf("%f %f\n", dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]], tmp),
				tmp = dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]],
				xx = x-2*water[weather[days+1]], yy = y-2*food[weather[days+1]], ll = p;				
			}

		}
		if(mp[l] == 2 && x>=3*water[weather[days+1]] && y>=3*food[weather[days+1]] && tmp < dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]] + bonus)
			tmp = dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]] + bonus,
			xx = x-3*water[weather[days+1]], yy = y-3*food[weather[days+1]], ll = l;
			
		x = xx, y = yy, l = ll; days++;
	}
	printf("day %d: %d %d %d %d\n", days, l, x, y, m+x*5/2+y*5);
}
