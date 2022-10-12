#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

priority_queue <double, vector<double>, greater<double> > pq;

int main()
{
	int n, m;
	cin >> n;
	rep(i,0, n) cin >> m, pq.push(double(m));
	rep(kase_time, 0, n-1){
		double a = pq.top();
		pq.pop();
		double b = pq.top();
		pq.pop();
		//res = max(res, (a+b)/2.0);
		pq.push((a+b)/2.0);
	}
	cout << int(pq.top());
	return 0;
}

