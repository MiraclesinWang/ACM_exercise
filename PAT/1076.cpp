#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e3 + 10;

vector <int> v[maxn];
bitset <maxn> dp[maxn][10], bs;

int get_len(bitset <maxn> & b)
{
	int res = 0;
	rep(i, 0, b.size())
		if(b[i]) res++;
	return res-1;
}

int main()
{
	int n, l, k;
	cin >> n >> l;
	rep(i, 1, n+1){
		int num, tmp;
		cin >> num;
		rep(j, 0, num) cin >> tmp, v[tmp].push_back(i);
	}
	rep(i, 1, n+1){
		bs = 0;
		rep(j, 0, v[i].size()) bs[v[i][j]] = 1;
		bs[i] = 1;
		dp[i][1] = bs;
	}
	rep(j, 2, l+1){
		rep(i, 1, n+1){
			dp[i][j] = dp[i][j-1];
			rep(t, 0, v[i].size())
				dp[i][j] |= dp[v[i][t]][j-1];
		}
	}
	cin >> k;
	rep(i, 0, k){
		int id;
		cin >> id;
		cout << get_len(dp[id][l]);
		if(i!=k-1) cout << "\n";
	}
	
	return 0;
}


