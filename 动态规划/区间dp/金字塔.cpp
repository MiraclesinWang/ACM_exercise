#include <bits/stdc++.h>
using namespace std;

#define isReverse(x, y) (x%26==y/26 && x/26==y%26) 
#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;

const LL mod = 1e9;

int cnct[305];
LL dp[305][305], mp[305][305];

int main()
{
	memset(dp, 0ll, sizeof(dp)); 
	memset(mp, 0ll, sizeof(mp));
    string s;
    cin >> s;
    rep(i, 1, s.length()){
    	cnct[i] = 26 * (s[i-1]-'A') + (s[i]-'A');
    	if(i > 1) dp[i-1][i] = isReverse(cnct[i], cnct[i-1]), mp[i-1][i]=dp[i-1][i];
	}
	for(int t = 1; t < s.length(); t+=2){
		rep(i, 1, s.length()-t){
			int j = t + i;
			for(int k = i+1; k < j; k+=2){
				(dp[i][j] += (mp[i][k] * dp[k+1][j])) %= mod;
			}
			if(isReverse(cnct[i], cnct[j]) && j-i > 1){
				(dp[i][j] += dp[i+1][j-1]) %= mod;
				(mp[i][j] += dp[i+1][j-1]) %= mod;
			}
		}
	}
	printf("%lld", dp[1][s.length()-1]);
}
