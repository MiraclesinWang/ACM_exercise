#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
set <int> s;
vector <int> v;

int main()
{
	int n, m;
	cin >> n;
	rep(i, 0, n){
		cin >> m;
		int sm = 0;
		while(m) sm += m%10, m/=10;
		s.insert(sm);
	}
	cout << s.size() << "\n";
	for(auto i = s.begin(); i != s.end(); i++) v.push_back(*i);
	sort(v.begin(), v.end());
	rep(i, 0, v.size()){
		cout << v[i];
		if(i < v.size()-1) cout << " ";
	}
	return 0;
}

