#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

const int maxn = 1e3 + 10;
struct mooncake{
	double t, p, avg;
	bool operator < (const mooncake & oth){
		return avg > oth.avg;
	}
} M[maxn];

int main()
{
	int n, m;
	double res = 0;
	cin >> n >> m;
	rep(i, 0, n) cin >> M[i].t;
	rep(i, 0, n) cin >> M[i].p, M[i].avg = M[i].p / (double)M[i].t;
	sort(M, M+n);
	rep(i, 0, n){
		//printf("%d %f\n", M[i].t, M[i].p);
		if(m < M[i].t){
			res += m* M[i].avg;
			m = 0;
		}
		else res += M[i].p, m-=M[i].t;
	}
	printf("%.2f", res);
	return 0;
}

