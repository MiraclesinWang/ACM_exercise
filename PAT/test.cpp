#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e4 + 10;

map <int, int> mp = {{1, 2}, {2, 4}};
int main()
{
	printf("%d\n", mp.find(1) == mp.end());
	mp.erase(mp.find(1));
	printf("%d\n", mp.find(1) == mp.end());
	return 0;
}

