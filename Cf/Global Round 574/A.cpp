#include <cstdio>
#include <cstring>
using namespace std;
int cnt[1005];

int main()
{
	memset(cnt, 0, sizeof(cnt));
	int n, k, a;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a),
		cnt[a]++;
	int res = 0, c = 0;
	for(int i = 1; i <= k; i++){
		res += cnt[i];
		if(cnt[i]%2 == 1) c++, res--;
	}
	res += (c+1) / 2;
	printf("%d\n", res);
}
