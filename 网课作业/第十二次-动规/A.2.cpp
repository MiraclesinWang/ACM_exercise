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
	int a, dex = 0,len,t;
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
	dex -= 1;t=dex;
	while(s[t]==e[t]) t-=1;
	for(int i=dex;i>t;i--)
		if(abs(s[t]-s[t-1])<2) {printf("0\n");return 0;}
	if(t==dex)
		for(int i=s[dex]+1;i<e[dex];i++) dp[dex][i]=1;
	else
		for(int i=s[t]+1;i<e[t];i++)
			if(abs(i-s[t+1])>=2) dp[t][i]=1;
	for(int i=t-1;i>=0;i--){
		for(int j=0;j<=9;j++){
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
		}
		for(int j=s[i]+1;j<=9;j++) if(abs(j-s[i+1])>=2) dp[i][j]+=1;
		for(int j=e[i]-1;j>=0;j--) if(abs(j-e[i+1])>=2||i>=len) dp[i][j]+=1;
	}
	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res += dp[0][i];
	}
	bool can=true;
	for(int i=dex;i>=1;i--) if(abs(e[i]-e[i-1])<2) can=false;
	if(can) res++;
	can=true;
	for(int i=len;i>=1;i--) if(abs(s[i]-s[i-1])<2) can=false;
	if(can) res++;
	cout<<res<<endl;
}
