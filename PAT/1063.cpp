#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

const int maxn = 55;
set <int> t, c, s[maxn];
double query[maxn][maxn];

double get_res(int a, int b)
{
	t.clear(), c.clear();
	for(auto i = s[a].begin(); i != s[a].end(); i++){
		if(t.find(*i) == t.end()) t.insert(*i);
		else c.insert(*i);
	}
	for(auto i = s[b].begin(); i != s[b].end(); i++){
		if(t.find(*i) == t.end()) t.insert(*i);
		else c.insert(*i);
	}
	return (double)(c.size()) / (double)(t.size()) * 100.0;
}

int main()
{
	int n;
	cin >> n;
	rep(i, 1, n+1){
		int m, tmp;
		cin >> m;
		rep(j, 0, m) cin >> tmp, s[i].insert(tmp);
	}
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			if(i==j) query[i][j] = 100.0;
			else if(i>j) continue;
			query[i][j] = get_res(i, j);
		}
	}
	cin >> n;
	rep(j, 0, n){
		int a, b;
		cin >> a>> b;
		if(a>b) swap(a, b);
		printf("%.1f", query[a][b]);
		cout << '%';
		if(j!=n-1) cout << "\n";
	}
	return 0;
}
