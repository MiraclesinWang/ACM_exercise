#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int s[20], e[20];
int dp[20][20];
int main()
{
	memset(s, 0, sizeof(s));
	memset(e, 0, sizeof(e));
	memset(dp, 0, sizeof(dp));
	int a, dex = 0,len;
	cin >> a;
	while (a) {
		s[dex++] = a % 10;
		a /= 10;
	}
	len=dex-1;
	cin >> a;
	dex = 0;
	while (a) {
		e[dex++] = a % 10;
		a /= 10;
	}
	dex -= 1;
	for (int i = s[dex]; i <= e[dex]; i++)
		dp[dex][i] = 1;
	for (int i = dex - 1; i >= 0; i--) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (abs(k - j) >= 2) {
					if (k == e[i + 1]) {
						if (j <= e[i]) dp[i][j] += dp[i + 1][k];
					}
					else if (k == s[i + 1]) {
						if (j >= s[i]) dp[i][j] += dp[i + 1][k];
					}
					else dp[i][j] += dp[i + 1][k];
				}
			}
			if(j==0 && i>len) dp[i][0]+=1;
			if(j==1) {
				if(i>len) dp[i][1]++;
				else if(i==len && s[i]==1) dp[i][1]++; 
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res += dp[0][i];
	}
	/*for(int i=0;i<=9;i++){
		for(int j=0;j<=dex;j++){
			cout<<dp[j][i]<<' ';
		}
		cout<<endl;
	}*/
	cout << res << endl;
}
