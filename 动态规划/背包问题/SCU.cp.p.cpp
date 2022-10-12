#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5 + 20;
int pre[maxn], now[maxn], s[maxn], f[maxn];
const int base = 1e5 + 10;
int n;

void push(int dex, int * p, int * nw)
{
	if(dex > n){
		int res = 0;
		for(int i = base; i < maxn; i++)
			if(p[i] >= 0)
				res = max(res, p[i] + i - base);
		printf("%d\n", res);
		return;		
	}
	for(int i = 0; i < maxn; i++) nw[i] = p[i];
	for(int j = maxn - 1; j; j--)
		if(p[j] > -(int)1e8)
			nw[j+s[dex]] = max(nw[j+s[dex]], p[j] + f[dex]);	
	push(dex+1, nw, p);
}

int main()
{
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < maxn; i++) pre[i] = -1e9;
		for(int i = 1; i <= n; i++) scanf("%d%d", &s[i], &f[i]);
		pre[base] = 0;
		push(1, pre, now);
	}
}
