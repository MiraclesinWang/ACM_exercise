#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxm = 1e4 + 10;

pair <int, int> Edge[maxm];
set <int> s;

int main()
{
	int n, m, k, p;
	cin >> n >> m;
	rep(i, 0, m) cin >> Edge[i].first >> Edge[i].second;
	cin >> k;
	rep(i, 0, k){
		s.clear();
		cin >> p;
		int tmp;
		bool flag = true;
		rep(j, 0, p) cin >> tmp, s.insert(tmp);
		rep(j, 0, m){
			if(s.find(Edge[j].first) == s.end() && s.find(Edge[j].second) == s.end())
				{flag = false; break;}
		}
		printf(flag?"Yes":"No");
		if(i!=k-1) printf("\n");
	}
	return 0;
}

