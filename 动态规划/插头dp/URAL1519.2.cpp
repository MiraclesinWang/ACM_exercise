#include <bits/stdc++.h>
using namespace std;

int n, m;
int Thr[20];
#define incl(x, i) x%Thr[i+1]/Thr[i]
int st[1594323], cnt = 0;
#define ll long long
ll dp[2][221370];
int mp[20][20];

int main()
{
	Thr[0] = 1;
	for(int i = 1; i <= 18; i++) Thr[i] = Thr[i-1]*3;
	for(int i = 1; i < Thr[13]; i++){
		int a[3] = {0,0,0};
		for(int j = 0; j < 12; j++) a[incl(i, j)]++;
		if(a[1] == a[2]) st[cnt++] = i;
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%d", &mp[i][j]);
	memset(dp, 0, sizeof(dp));
	int l = 1, s;
	dp[0][0] = 1;
	for(int i = 0; i < cnt; i++)
		if(st[i]/Thr[m+1]) {s = i; break;}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j]){
				
			}
			else{
				for(int k = 0; k < s; k++){
					int t = st[k];
					if(!(t%3) && !incl(t, j)) dp[l][k] = dp[l^1][k];
					else dp[l][k] = 0;
				}
			}
		}
	}
 } 
