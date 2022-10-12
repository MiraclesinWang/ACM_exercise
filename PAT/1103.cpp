#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 4e2 + 10;

int dp[maxn][maxn], val[maxn];
pair<int, int> fa[maxn][maxn];

int main()
{
	int n, k, p;
	MEM(dp, -1);
	cin >> n >> k >> p;
	rep(i, 1, n+1){
		val[i] = 1;
		rep(j, 0, p){
			val[i]*=i;
			if(val[i] > n) {val[i]=n+1;break;}
		}
	}
	
	dp[0][0] = 0;    //选了i个数，平方和为j 
	for(int i = int(pow(n, 1.0/(double)p)) +1; i; i--){
		//cout << i << " " << val[i] << ":\n";
		rep(j, 0, k){
			rep(t, 0, n){
				if(dp[j][t] == -1) continue;
				if(t+val[i] > n) break;
				
				if(dp[j+1][t+val[i]] < dp[j][t]+i){
					dp[j+1][t+val[i]] = dp[j][t] + i;
					fa[j+1][t+val[i]] = {j, t};
					//cout << j << " " << t << " " << t+val[i] << " " << dp[j+1][t+val[i]] << "\n";
				}
			}
		}
	}
	if(!~dp[k][n]) cout << "Impossible";
	else{
		stack <int> st;
		int a = k, b = n;
		while(a&&b){
			st.push(dp[a][b] - dp[fa[a][b].first][fa[a][b].second]);
			int c = a;
			a = fa[a][b].first, b = fa[c][b].second;
		}
		cout << n << " = ";
		while(!st.empty()){
			cout << st.top() << '^' << p;
			st.pop();
			if(!st.empty()) cout << " + ";
		}
	}
}

