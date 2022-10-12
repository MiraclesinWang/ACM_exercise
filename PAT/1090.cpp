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

struct retailer{
	int dex, fa;
	double p;
} rt[maxn];

bool cmp_dex(retailer & r1, retailer & r2){
return r1.dex < r2.dex;}

queue <int> q;
vector <int> v[maxn];

int main()
{
	int n;
	double p, r, mx = 0.0;
	cin >> n >> p >> r;
	r = r/100.0 + 1.0;
	rep(i, 0, n) cin >> rt[i].fa, rt[i].dex = i;
	rep(i, 0, n){
		if(rt[i].fa == -1) q.push(rt[i].dex);
		else v[rt[i].fa].push_back(i);
	}
	while(!q.empty()){
		int dex = q.front();
		if(rt[dex].fa == -1) rt[dex].p = p;
		else rt[dex].p = rt[rt[dex].fa].p *r;
		q.pop();
		rep(i, 0, v[dex].size()) q.push(v[dex][i]);
		if(mx < rt[dex].p) mx = rt[dex].p;
	}
	int cnt = 0;
	rep(i, 0, n){
		if(abs(mx-rt[i].p) < 1e-4) cnt++;
	}
	printf("%.2f %d", mx, cnt);
	return 0;
}

