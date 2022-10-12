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

pair<string, string> pr[maxn];
set <string> s;

int main()
{
	int n, m, k;
	cin >> n >> m;
	rep(i, 0, n){
		getchar();
		string s1, s2;
		cin >> s1 >> s2;
		pr[i].first = s1, pr[i].second = s2;
	}
	rep(i, 0, m){
		cin >> k;
		s.clear();
		string tmp;
		rep(j, 0, k) cin >> tmp, s.insert(tmp);
		bool res = true;
		rep(j, 0, n){
			if(s.find(pr[j].first) != s.end() && s.find(pr[j].second) != s.end()){
				res = false;
				break;
			}
		}
		printf(res?"Yes":"No");
		if(i!=m-1) cout << "\n";
	}
	return 0;
}

