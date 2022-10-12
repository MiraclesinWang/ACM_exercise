#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e5 + 10;

LL A[maxn];

int main()
{
	int n, res = 0;
	LL p;
	cin >> n >> p;
	rep(i, 0, n) cin >> A[i];
	sort(A, A+n);
	rep(i, 0, n){
		int x = upper_bound(A, A+n, p*A[i]) - A;
		res = max(res, x-i);
	}
	cout << res;
	return 0;
}

