#pragma comment(linker,"/STACK:1024000000,1024000000") 
#include <bits/stdc++.h>
using namespace std;


#define rep(x, y) for(int i = x; i < y; i++)
const int day = 30;
const int points = 11;
const int ini = 10000;
const int bonus = 1000;
const int weight = 1200;
const int sand = 20;
const float sunny = 0.6;
const float hot = 0.3;
const float storm = 0.1;
const float INF = 1e9;
int water[4] = {3, 9, 10};
int food[4] = {4, 9, 10};
int weather[35] = {0, 0,1,1,0,0,2,1,0,0,1,1,1,0,1,0,0,1,0,2,0,0,0,2,0,1,0,0,0,0,0};

int cnct[50][50], mp[20];
float dp[35][20][305][505];

void A(int u, int v)
{
	cnct[u][++cnct[u][0]] = v;
	cnct[v][++cnct[v][0]] = u;
}

int main()
{
	A(1, 2);
	A(2,3);
	A(3,4);
	A(4,5);
	A(5,6);
	A(5,7);
	A(6,8);
	A(7,8);
	A(8,9);
	A(8,10);
	A(9,11);
	A(10,11);
	mp[7] = 2; mp[6] = 1;
	for(int i = 0; i <= day; i++)
		for(int j = 0; j <= points; j++)
			for(int m = 0; m <= 300; m++)
				for(int n = 0; n <= 500; n++)
					dp[i][j][m][n] = -INF;
	
	for(int i = 1; i <= day; i++)
		for(int j = 0; j <=300; j++)
			for(int k = 0; k <= 500; k++){
				if(3*j + 2*k > weight) break;
				dp[i][points][j][k] = (float)j * 5.0 / 2.0 + (float)k * 5.0;
			}
			
	for(int i = day-1; i >= 0; i--){
		printf("%d\n", i);
		for(int j = 1; j <= points; j++)
			for(int w = sand; w <= 300; w++)
				for(int f = sand; f <= 500; f++){   //最低连续撑两次沙暴 
					if(3*w + 2*f > weight) break;
					
					float sy, ht, st;   //三种天气最优策略 
					sy = dp[i+1][j][w-water[0]][f-food[0]];   //不动 
					ht = dp[i+1][j][w-water[1]][f-food[1]];
					st = dp[i+1][j][w-water[2]][f-food[2]];
					
					if(mp[j] == 2){        //挖矿 
						if(w >= water[2]*3 && f >= food[2]*3 && dp[i+1][j][w-water[2]*3][f-food[2]*3] > -1e8)
							st = max(st, dp[i+1][j][w-water[2]*3][f-food[2]*3] + bonus); 
						if(w >= water[0]*3 && f >= food[0]*3 && dp[i+1][j][w-water[0]*3][f-food[0]*3] > -1e8)
							sy = max(sy, dp[i+1][j][w-water[0]*3][f-food[0]*3] + bonus);
						if(w >= water[1]*3 && f >= food[1]*3 && dp[i+1][j][w-water[1]*3][f-food[1]*3] > -1e8)
							ht = max(ht, dp[i+1][j][w-water[1]*3][f-food[1]*3] + bonus);						
					}
					
					for(int k = 1; k <= cnct[j][0]; k++){   //移动 
						int p = cnct[j][k];
						if(w >= water[0]*2 && f >= food[0]*2 && dp[i+1][p][w-water[0]*2][f-food[0]*2] > -1e8)
							sy = max(sy, dp[i+1][p][w-water[0]*2][f-food[0]*2]);
						if(w >= water[1]*2 && f >= food[1]*2 && dp[i+1][p][w-water[1]*2][f-food[1]*2] > -1e8)
							ht = max(ht, dp[i+1][p][w-water[1]*2][f-food[1]*2]);
							
						if(mp[p] == 1){           //村庄购物 
							for(int x =0; x <= 300; x++){
								if(x + w-water[1]*2 > 300) break;
								for(int y = 0; y <= 500; y++){
									if(y + f - food[1]*2 > 500 || 3*(x + w-water[1]*2)+2*(y+f-food[1]*2) > weight) break;
									ht = max(ht, dp[i+1][p][x+w-water[1]*2][y+f-food[1]*2] - 10*x - 20*y);
									if(3*(x + w-water[0]*2)+2*(y+f-food[0]*2) <= weight)
										sy = max(sy, dp[i+1][p][x+w-water[0]*2][y+f-food[0]*2] - 10*x - 20*y); 
								}
							}
						}
					}
					
					dp[i][j][w][f] = sunny * sy + hot * ht + storm * st;

				}
	}
	
	//30*11*300*500
	
	/*ofstream ofile("text.txt");
	for (int i = 0; i <= 30; ++i) {
		for (int j = 1; j <= 11; ++j) {
			for (int k = 0; k <= 300; ++k) {
				for (int t = 0; t <= 500; ++t) {
					ofile << dp[i][j][k][t];
					if (i == 30 && j == 11 && k ==300 && t == 500) {
						
					} else {
						ofile << ' ';
					}
				}
			}
		}
	}
	ofile.close();*/
	
	/*ifstream ifile("text.txt");
	for (int i = 0; i <= 30; ++i) {
		cout << i << endl;
		for (int j = 1; j <= 11; ++j) {
			for (int k = 0; k <= 300; ++k) {
				for (int t = 0; t <= 500; ++t) {
					ifile >> dp[i][j][k][t];
				}
			}
		}
	}
	ifile.close();
	printf("%f\n", dp[0][1][200][300]);*/
	
	int x, y, l = 1, days = 0;
	float res = -INF;
	for(int i = sand; i <= 300; i++)
		for(int j = sand; j <= 500; j++){
			if(i*3+2*j > weight) break;
			//printf("%f\n", dp[0][1][i][j]);
			if(dp[0][1][i][j] > -1e8 && dp[0][1][i][j] - 5*i - 10*j +ini> res)
				res = dp[0][1][i][j] - 5*i - 10*j+ini, x =i, y = j;
		}
	int m = ini - x*5 - y*10;
	while(l != points){
		printf("day %d: %d %d %d %d\n", days, l, x, y, m);
		float tmp = dp[days+1][l][x-water[weather[days+1]]][y-food[weather[days+1]]];
		int xx = x-water[weather[days+1]], yy = y-food[weather[days+1]], ll = l, mm = m;
		
		if(mp[l] == 2 && x>=3*water[weather[days+1]] && y>=3*food[weather[days+1]] && tmp < dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]] + bonus)
			//printf("%f %f %f\n", dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]], dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]]+ bonus, tmp),
			tmp = dp[days+1][l][x-3*water[weather[days+1]]][y-3*food[weather[days+1]]] + bonus, mm = m + 1000,
			xx = x-3*water[weather[days+1]], yy = y-3*food[weather[days+1]], ll = l;
		
		for(int k = 1; k <= cnct[l][0]; k++){
			int p = cnct[l][k];
			if(x>=2*water[weather[days+1]] && y>=2*food[weather[days+1]]){
				if(dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]] > -1e8 &&tmp < dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]])
					tmp = dp[days+1][p][x-2*water[weather[days+1]]][y-2*food[weather[days+1]]],
					xx = x-2*water[weather[days+1]], yy = y-2*food[weather[days+1]], ll = p;
				
				if(mp[p] == 1){
					for(int w = 0; w <= 300; w++){ 
					 	if(w+x-2*water[weather[days+1]] > 300) break;
					 	for(int f = 0; f <= 500; f++){
					 		if(f+y-2*food[weather[days+1]] > 500) break;
					 		if(dp[days+1][p][w+x-2*water[weather[days+1]]][f+y-2*food[weather[days+1]]] - 10*w - 20*f > tmp)
					 			tmp = dp[days+1][p][w+x-2*water[weather[days+1]]][f+y-2*food[weather[days+1]]] - 10*w - 20*f,
					 			xx = w+x-2*water[weather[days+1]], yy = f+y-2*food[weather[days+1]], ll = p, mm = m - 10*w - 20*f;
						 }
					 } 
				}
			}
		}
		x = xx, y = yy, l = ll, m = mm, days++;
	}
	printf("day %d: %d %d %d %d\n", days, l, x, y, m+x*5/2+y*5);
}
