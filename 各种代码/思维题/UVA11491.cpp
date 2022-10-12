#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100000+5
int n,d;
int s[maxn], f[maxn];
char c;

void solve()
{
	scanf("\n");
	for(int i = 1; i <= n; i++)
		scanf("%c", &c), s[i] = c - '0';
	int dex = 2, len = n - d, ndex = 1;
	f[1] = s[1];
	while(dex <= n && d > 0){
		while(ndex > 0 && s[dex] > f[ndex] && d > 0)
			ndex -= 1, d -= 1;
		f[++ndex] = s[dex++];
	}
	for(int i = 1; i <= min(len, ndex); i++)
		printf("%d",f[i]);
	len -= ndex;
	for(int i = 0; i < len; i++)
		printf("%d",s[dex++]);
	printf("\n"); 
}

int main()
{
	while(scanf("%d%d",&n, &d), n && d)
		solve();
}
