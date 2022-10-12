#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e3 + 10;



vector <int> v[maxn];
int fa[maxn];
struct node{
	int num, rt;	
	bool operator < (const node &oth){return num > oth.num;}
}rt[maxn];
map <int, int> mp;

inline int frt(int x)
{return x==fa[x]?x:fa[x]=frt(fa[x]);}

int main()
{
	int n, m, tmp;
	cin >> n;
	rep(i, 1, n+1){
		cin >> m;
		scanf(":");
		rep(j, 0, m) cin >> tmp, v[tmp].push_back(i);
		fa[i] = i;
	}
	rep(i, 1, maxn){
		if(v[i].size()==0) continue;
		int f = v[i][0];
		rep(j, 1, v[i].size()) fa[frt(v[i][j])] = f;
	}
	int cnt = 0;
	rep(i, 1, n+1){
		frt(i);
		if(mp.find(fa[i]) == mp.end()) rt[cnt].num = 1, rt[cnt].rt = fa[i], mp[fa[i]] = cnt++;
		else rt[mp[fa[i]]].num++;
	}
	cout << cnt << "\n";
	sort(rt, rt+cnt);
	rep(i, 0, cnt){
		cout << rt[i].num;
		if(i < cnt-1) cout << " ";
	}
	return 0;
}

