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

struct customer{
	int tm, need;
	bool operator < (const customer& c2) const
	{return tm > c2.tm;}
	customer(){tm=need=0;}
	customer(int _t, int _n):tm(_t), need(_n){}
};
customer c[maxn];

bool cmp_cus(customer &c1, customer &c2)
{
	return c1.tm > c2.tm;
}

priority_queue <customer> pq;
priority_queue <int, vector<int>, greater<int> > bk;

int main()
{
	int n, k, tot=0, cpy;
	cin >> n >> k;
	cpy = n;
	rep(i, 1, n+1){
		int hh, mm, ss;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &c[i].need);
		c[i].tm = 3600*hh + 60*mm +ss;
		if(c[i].tm > 3600*17) {cpy--;continue;}
		pq.push(c[i]);
	}
	n = cpy;
	rep(i, 1, k+1) bk.push(8*3600);
	while(!pq.empty()){
		int b = bk.top();
		customer cr = pq.top();
		pq.pop(); bk.pop();
		tot += max(b - cr.tm, 0);
		if(cr.need > 60) pq.push(customer(cr.tm+3600, cr.need-3600));
		bk.push(max(b, cr.tm) + 60*min(cr.need, 60));
	}
	printf("%.1f", (double)tot / (double)n / 60.0);
	return 0;
}
