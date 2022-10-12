#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e4 + 5;

int clr[maxn]; 
vector<int> v[maxn];
set <int> s;

int main()
{
	int m, n, k;
	cin >> n >> m;
	rep(i, 0, m){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> k;
	rep(i, 0, k){
		s.clear();
		bool flag = true;
		rep(j, 0, n) cin >> clr[j], s.insert(clr[j]);
		rep(j, 0, n){
			rep(t, 0, v[j].size())
				if(clr[v[j][t]] == clr[j]) flag=false;
				//printf("%d %d %d %d\n", j, v[j][t], clr[j], clr[v[j][t]]);
		}
		if(flag) printf("%d-coloring", s.size());
		else printf("No");
		if(i!=k-1) printf("\n");
	}
	return 0;
}

