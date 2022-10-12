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

vector <int> pos, neg;
int pro[maxn];

int main()
{
	int n, m, tmp;
	cin >> n;
	rep(i, 0, n){
		cin >> tmp;
		if(tmp > 0) pos.push_back(tmp);
		else if(tmp < 0) neg.push_back(tmp);
	}
	cin >> m;
	rep(i, 0, m) cin >> pro[i];
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());
	sort(pro, pro+m, greater<int>());
	
	int res = 0, dex = 0;
	for(auto i = pos.begin(); i != pos.end(); i++, dex++){
		int j = *i;
		if(pro[dex] <= 0) break;
		res += j * pro[dex];
	}
	dex = m-1;
	for(auto i = neg.begin(); i!=neg.end(); i++, dex--){
		int j = *i;
		if(pro[dex] >=0) break;
		res += j * pro[dex];
	}
	cout << res;
	return 0;
}

