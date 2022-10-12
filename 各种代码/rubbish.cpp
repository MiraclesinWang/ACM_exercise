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
bool valid[35][20][305][505];

void A(int u, int v)
{
	cnct[u][++cnct[u][0]] = v;
	cnct[v][++cnct[v][0]] = u;
}

int main()
{
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
	
	float f;
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	for(int i = 0; i < 5; i++) cin >> f, printf("%f\n", f); 
}
