
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
 
//const int maxn = 100 + 5;
//const int INF = 0x3f3f3f3f;
const int hashSize = 2000000;//总状态有3^13个，size取得大有利于减小冲突，但是会增加清空内存的时间。 
int Hash[hashSize]; 
int n, m, index, ex, ey;
int total[2], state[2][hashSize], Bit[100];
LL dp[2][hashSize], ans;
int Map[15][15];
void init() {
	memset(Map, 0, sizeof Map);
	index = 0;
	total[0] = 1;
	state[0][1] = 0;
	dp[index][1] = 1;
	ans = 0;
}
void hashCal(int s, LL num) {
	int hashPos =  s % hashSize;
	while(Hash[hashPos] != -1) {
		if(state[index][Hash[hashPos]] == s) {
			dp[index][Hash[hashPos]] += num;
			return;
		}
		hashPos++;
		if(hashPos==hashSize) hashPos = 0;
	}
	total[index]++;
	dp[index][total[index]] = num;
	Hash[hashPos] = total[index];
	state[index][total[index]] = s;
}
void DP() {
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k <= total[index]; k++) state[index][k] <<= 2;
		for(int j = 1; j <= m; j++) {
			index ^= 1;
			total[index] = 0;
			memset(Hash, -1, sizeof Hash);
			for(int k = 1; k <= total[index^1]; k++) {
				int s = state[index^1][k];
				LL num = dp[index^1][k];
				int p = (s>>Bit[j-1]) % 4;
				int q = (s>>Bit[j]) % 4;
				//if(num==0) cout << i << " " << j << " " << s << endl;
				if(!Map[i][j]) {
					if(p+q == 0) hashCal(s, num);
				} 
				else if(p+q == 0) {
					if(!Map[i+1][j] || !Map[i][j+1]) continue;
					s += (1<<Bit[j-1]) + (1<<(Bit[j]+1));
					hashCal(s, num);
				}
				else if(!p && q) {
					if(Map[i][j+1]) hashCal(s, num);
					if(Map[i+1][j]) {
						s += (1<<Bit[j-1])*q - (1<<Bit[j])*q;
						hashCal(s, num);
					}
				}
				else if(!q && p) {
					if(Map[i+1][j]) hashCal(s, num);
					if(Map[i][j+1]) {
						s += (1<<Bit[j])*p - (1<<Bit[j-1])*p;
						hashCal(s, num);
					}
				}
				else if(p+q == 2) { //合并连通块 
					int b = 1; //寻找最近的右括号 
					for(int t = j+1; t <= m; t++) {
						int v = (s>>Bit[t]) % 4;
						if(v == 1) b++;
						if(v == 2) b--;
						if(!b) {
							s -= (1<<Bit[t]);
							break;
						} 
					}
					s = s - (1<<Bit[j-1])-(1<<Bit[j]);  
					hashCal(s, num);
				}
				else if(p+q == 4) {
					int b=1;  
                    for(int t = j - 2; t >= 0; t--){//寻找最近的匹配括号   
                        int v = (s>>Bit[t]) % 4;  
                        if(v == 2) ++b;  
                        if(v == 1) --b;  
                        if(!b){  
                            s += (1<<Bit[t]);//将左括号变为右括号   
                            break;  
                        }  
                    }  
                    s = s - 2*(1<<Bit[j-1]) - 2*(1<<Bit[j]);  
                    hashCal(s, num);
 
				}
				else if(p==2 && q==1) {
					s = s - (1<<(Bit[j-1]+1)) - (1<<(Bit[j]));
					hashCal(s, num);
				}
				else if(p==1 && q==2) {
					//cout << i << j << endl;
					if(i==ex && j==ey) ans += num;
					//cout << ans << endl;
				}
			}
		}
	}
}
int main() {
    //freopen("input.txt", "r", stdin);
	for(int i = 0; i <= 25; i++) Bit[i] = i<<1; //求第i个插头需要右移的位置 
	while(scanf("%d%d", &n, &m)==2) {
		init();
		char op;
		for(int i = 1; i <= n; i++) {
			getchar();
			for(int j = 1; j <= m; j++) {
				scanf("%c", &op);
				if(op=='.') Map[i][j] = 1, ex = i, ey = j;
			} 
		}
		//cout << ex << ey << endl;
		DP();
		printf("%I64d\n", ans);
	}
    return 0;
}
