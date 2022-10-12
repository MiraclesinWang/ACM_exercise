#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e10; 
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

int n, m;
struct child{
	int dex, bis;
	ll g;
} c[35];
ll dp[35][30*30/2 + 5][35];
int fa[35][30*30/2 + 5][35];

bool cmp_g(child &c1, child &c2) {return c1.g > c2.g;}
bool cmp_dex(child &c1, child &c2) {return c1.dex < c2.dex;}

void init()
{
	rep(i, 0, 35)
	 rep(j, 0, 30*30/2 + 5)
	  rep(k, 0, 35)
	   dp[i][j][k] = INF;
}

int main()
{
	init();
	scanf("%d%d", &n, &m);
	rep(i, 1, n+1) scanf("%lld", &c[i].g), c[i].dex = i;
	sort(c+1, c+1+n, cmp_g);
	int l = max(0,m-n*(n-1)/2)%n + n*(n-1)/2;
	l = min(l, n);
	
	dp[0][l][0] = 0;
	rep(i, 0, n){    //贪婪度大的在前 
		for(int j = l; j; j--){
			if((n-i) > j) break;  //每人一块都无法分配 
			rep(k, 1, j){
				if(dp[i][j][k] >= INF) continue;
				rep(t, 1, k+1){
					
					dp[i+1][j-t][t] =  
				} 
			}
		}
	}
}


