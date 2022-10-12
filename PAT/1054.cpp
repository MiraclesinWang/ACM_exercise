#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

map <int, int> mp;
const int maxn = 600*800 + 10;
vector <int> keys;

int main()
{
	int m, n, c, res, mx = 0;
	cin >> m >> n;
	rep(i, 0, n){
		rep(i, 0, m){
			cin >> c;
			if(mp.find(c) == mp.end()) mp[c] = 1, keys.push_back(c);
			else mp[c]++;
		}
	}
	
	rep(i, 0, keys.size()){
		if(mp[keys[i]] > mx) res = keys[i], mx = mp[keys[i]];
	}
	cout << res;
	return 0;
}

