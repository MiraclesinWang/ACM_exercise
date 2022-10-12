#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i < y; i++)
typedef long long LL;
const int maxn = 250000 + 10;

struct magn{
	LL d, r;
	int m, p, dex;
	magn(){}
	magn(LL _d, LL _r, int _m, int _p):d(_d), r(_r), m(_m), p(_p){}
	bool operator < (const magn &oth){return d < oth.d;}
} mg[maxn], seq[505][605];
queue <magn> q;
bool vis[maxn];
int now[505];

bool cmp_d(LL a, magn &b) {return a < b.d;}
bool cmp_m(int a, magn &b) {return a < b.m;}
bool cmp_p(magn &a, magn &b) {return a.m < b.m;}

void prepro(int b, int bl, int n)
{
	memset(vis, false, sizeof(vis));
	memset(now, 0, sizeof(now));
	while(!q.empty()) q.pop();
	rep(i, 0, b-1){
		int l = i*bl, r = (i+1)*bl;
		rep(j, l, r) seq[i][j-l+1] = mg[j];
		sort(seq[i]+1, seq[i]+1+bl, cmp_p);
	}
}

void attract(magn m, int bl, int b, int n)
{
	int i, j;
	for(i=0 ; i < b-1 && mg[(i+1)*bl-1].d <= m.r; i++){
		for(j = now[i]+1; j <= bl && seq[i][j].m <= m.p; j++){
			if(!vis[seq[i][j].dex]) 
				vis[seq[i][j].dex] =true, q.push(seq[i][j]);
		}
		now[i] = j-1;
	}

	for(j = i*bl; j < n && mg[j].d <= m.r; j++){
		if(!vis[mg[j].dex] && mg[j].m <= m.p) 
			vis[mg[j].dex] = true, q.push(mg[j]);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	LL x0, y0, r0;
	int p0, n;
	cin >> x0 >> y0 >> p0 >> r0 >> n;

	int b = sqrt(n), bl = n/b;
	rep(i, 0, n){
		LL x, y;
		cin >> x >> y >> mg[i].m >> mg[i].p >> mg[i].r;
		mg[i].r = mg[i].r * mg[i].r;
		mg[i].d = (x-x0)*(x-x0) + (y-y0)*(y-y0);
		mg[i].dex = i;
	}
	sort(mg, mg+n);
	prepro(b, bl, n);

	q.push(magn(0, r0*r0, 0, p0));
	while(!q.empty()){
		attract(q.front(), bl, b, n);
		q.pop();
	}

	int ans = 0;
	rep(i, 0, n)
		if(vis[i]) ans++;
	cout << ans;
}