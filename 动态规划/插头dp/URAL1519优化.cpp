#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

#define ll long long
#define pt(x) Thr[x]
ll dp[2][531441][3];
int mp[15][15], Thr[20];
int tb[531441], cnt = 0; 
int t[3];
int incl(int s, int i)
{return s%Thr[i+1]/Thr[i];}

void init()
{
	for(int i = 0; i < 531441; i++){
		t[0] = t[1] = t[2] = 0;
		for(int j = 0; j < 12; j++)
			t[incl(i, j)]++;
		if(t[1] == t[2]) tb[cnt++] = i;
	}
}

int main()
{
	Thr[0] =1;
	for(int i = 1; i < 13; i++) Thr[i] = Thr[i-1]*3;
	init();	
	for(int i = 0; i < 10; i++) printf("%d ", tb[i]);
	printf("\n");
	char c;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("\n");
		for(int j = 0; j < m; j++)
			scanf("%c", &c), mp[i][j] = (c=='.');
	}
	memset(dp, 0ll, sizeof(dp));
	dp[0][0][0] = 1;
	int s = pt(m);
	ll res = 0;
	for(int i = 1; i <= n; i++){
		if(mp[i][0]){
			for(int kk = 0; kk < cnt; kk++){
				int k = tb[kk];
				if(!dp[0][k][0]) continue;
				if(k%3==1) continue;
				if(k%3==2){
					dp[1][k][0] += dp[0][k][0];
					dp[1][k-2][2] += dp[0][k][0];
				}
				else dp[1][k+2][1] += dp[0][k][0];
			}
		}
		else
			for(int kk = 0; kk < cnt; kk++){
				int k = tb[kk];
				if(!(k%3)) dp[1][k][0] = dp[0][k][0];				
			}
		swap(dp[0], dp[1]), memset(dp[1], 0ll, sizeof(dp[1]));
				
		for(int j = 1; j < m-1; j++){
			if(mp[i][j]){
				for(int kk = 0; kk < cnt; kk++){
					int k = tb[kk];
					if(!dp[0][k][0] && !dp[0][k][1] && !dp[0][k][2]) continue;
					if(!incl(k, j)){
						dp[1][k][1] += dp[0][k][1];
						dp[1][k][2] += dp[0][k][2];
						dp[1][k+2*pt(j)][0] += dp[0][k][2];
						dp[1][k+pt(j)][0] += dp[0][k][1];
						dp[1][k+2*pt(j)][1] += dp[0][k][0];
					}
					else if(incl(k, j) == 2){
						dp[1][k][0] += dp[0][k][0];
						dp[1][k-2*pt(j)][2] += dp[0][k][0];
						dp[1][k-2*pt(j)][0] += dp[0][k][1];
						int b = 0, c = 1;
						for(int a = j+1; a < m; a++){
							if(incl(k, a) == 2) c++;
							else if(incl(k, a) == 1) c--;
							if(!c) {b = a; break;}							
						}
						if(b) dp[1][k-2*pt(j)+pt(b)][0] += dp[0][k][2];
					}
					else{
						dp[1][k][0] += dp[0][k][0];
						dp[1][k-pt(j)][1] += dp[0][k][0];
						int b = 0, c = 1;
						for(int a = j-1; a >= 0; a--){
							if(incl(k, a) == 1) c++;
							else if(incl(k, a) == 2) c--;
							if(!c) {b = a; break;}				
						}
						if(b) dp[1][k-pt(j)-pt(b)][0] += dp[0][k][1];
					}
				}
				res = dp[0][pt(j)][2];
			}
			else
				for(int kk = 0; kk < cnt; kk++){
					int k = tb[kk];
					if(!incl(k, j)) dp[1][k][0] = dp[0][k][0];					
				}
			swap(dp[0], dp[1]), memset(dp[1], 0ll, sizeof(dp[1]));
		}
		
		if(mp[i][m-1]){
			for(int kk = 0; kk < cnt; kk++){
				int k = tb[kk];
				if(!dp[0][k][0] && !dp[0][k][1]) continue;
				if(incl(k, m-1) == 1){
					dp[1][k][0] += dp[0][k][0];
					int b = 0, c = 1;
					for(int a = m-2; a >= 0; a--){
						if(incl(k, a) == 1) c++;
						else if(incl(k, a) == 2) c--;
						if(!c) {b = a; break;}				
					}
					if(b) dp[1][k-pt(m-1)-pt(b)][0] += dp[0][k][1];				
				}

				else if(!incl(k, m-1))
					dp[1][k+pt(m-1)][0] += dp[0][k][1];
			}
			res = dp[0][pt(m-1)][2];
		}
		else
			for(int kk = 0; kk < cnt; kk++){
				int k = tb[kk];
				if(!incl(k, m-1)) dp[1][k][0] += dp[0][k][0];				
			}
		if(i < n)
			swap(dp[0], dp[1]), memset(dp[1], 0ll, sizeof(dp[1]));
	}
	printf("%lld\n", res);
	//if(mp[n][m-1]) printf("%lld\n", dp[0][pt(m-1)][2]);
	//else printf("%lld\n", dp[1][0][0]);
} 
