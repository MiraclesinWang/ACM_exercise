#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n" 

const int maxn = 1e5 + 5;
int A[maxn], n;

int main()
{
	int n, l=0, r=0;
	cin >> n;
	rep(i, 0, n) cin >> A[i];
	sort(A,A+n);
	rep(i, 0, n/2) l+= A[i];
	rep(i, n/2, n) r+= A[i];
	if(n%2 && abs(l-r) < abs(l-r+2*A[n/2])) l+= A[n/2], r+=A[n/2];
	printf("%d %d", n%2, abs(l-r)); 
	return 0;
}
