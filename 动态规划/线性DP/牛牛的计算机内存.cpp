#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
typedef long long ll;
int dp[1<<20], me[30];
int n, m;   // n��ָ��������m���ڴ����� 

int get_code(int dex)
{
	int res = 0;
	rep(i, 0, n)
		if(dex & (1<<i))
			res |= me[i];
	return res;
}

int get_cost(int cmd, int code)   //cmd���·��ʵ���� code�����б��� 
{
	int after = (cmd | code);
	int k = (after ^ code), res = 0;
	while(k){
		if(k&1) res++;
		k >>= 1;
	}
	return res*res;
}

int main()
{
	int tmp;
	scanf("%d%d", &n, &m);
	rep(i, 0, n){
		me[i] = 0;
		rep(j, 0, m) scanf("%1d", &tmp), me[i] <<=1, me[i] += tmp;
	}
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	rep(s, 0, (1<<n)-1){
		int code = get_code(s);
		rep(i, 0, n){    //����i���ڴ� 
			if((1<<i)&s) continue;
			dp[s|(1<<i)] = min(dp[s|(1<<i)], dp[s] + get_cost(me[i], code)); 
//			printf("%d %d %d %d %d\n", s,i, s|(1<<i), code, get_cost(me[i], code));
		}
	}
	printf("%d\n", dp[(1<<n)-1]);
}
