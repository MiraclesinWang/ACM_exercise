#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;
ll dp[2][2500 + 10];
char s1[2500 + 10], s2[2500 + 10];
int cnt1[2500 + 10], cnt2[2500+10];

int main()
{
	scanf("%s\n%s", s1, s2);
	memset(dp, 0, sizeof(dp));
	int l1 = strlen(s1), l2 = strlen(s2);
	for(int i = l1; i; i--) s1[i] = s1[i-1];
	for(int i = l2; i; i--) s2[i] = s2[i-1];
	cnt1[0] = cnt2[0] = 0;
	for(int i =1; i <= l1; i++) cnt1[i] = cnt1[i-1] + (s1[i] == ')');
	for(int i =1; i <= l2; i++) cnt2[i] = cnt2[i-1] + (s2[i] == ')');
	if((l1+l2)%2 || cnt1[l1] + cnt2[l2] != (l1+l2) / 2) {printf("0\n"); return 0;}
	int now = 0;
	for(int i =0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			if(!i && !j) dp[now][j] = 1;
			else dp[now][j] = 0;
			if(cnt1[i] + cnt2[j] > (i+j)/2) continue;
			if(i) (dp[now][j] += dp[now^1][j]) %= mod;
			if(j) (dp[now][j] += dp[now][j-1]) %= mod;
		}
		now ^= 1;
	}
	printf("%lld\n", dp[now^1][l2]);
}
