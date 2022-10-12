#include <cstdio>
#include <cstring>
using namespace std;

int pre[100005], now[100005];
int cnt[1005];
const int mod = 1e6;
int t, s, a, b;

void push(int dex, int *n, int *p)
{
	if(dex > t){
		int res = 0;
		for(int i = s; i <= b; i++) res = (res+p[i])%mod;
		printf("%d\n", res);
		return;		
	}
	int tmp = 0;
	for(int j = 0; j <= cnt[dex]; j++)
		tmp += p[j], tmp %= mod, n[j] = tmp;
	for(int j = cnt[dex]+1; j <= b; j++)
		tmp -= p[j-cnt[dex]-1], tmp += p[j]+mod, tmp %= mod, n[j] = tmp;
	push(dex+1, p, n);	
}

int main()
{
	memset(cnt, 0, sizeof(cnt));
	int tmp;
	scanf("%d%d%d%d", &t, &a, &s, &b);
	for(int i = 1; i <= a; i++)
		scanf("%d", &tmp), cnt[tmp]++;
	memset(pre, 0, sizeof(pre));
	pre[0] = 1;
	push(1, now, pre);		
}  
