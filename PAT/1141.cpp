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

struct school{
	int ns, ta, tb, tt, tws;
	string name;
	bool operator < (const school &oth){
		if(tws != oth.tws) return tws > oth.tws;
		if(ns != oth.ns) return ns < oth.ns;
		return name < oth.name;
	}
} sch[maxn];
map <string, int> mp;

int main()
{
	int n, tot=0;
	cin >> n;
	rep(i, 0, n){
		string id, sc;
		int score;
		getchar();
		cin >> id >> score >> sc;
		transform(sc.begin(),sc.end(),sc.begin(),::tolower);
		if(mp.find(sc) == mp.end())
			mp[sc] = ++tot, sch[tot].name = sc;
		if(id[0] == 'A') sch[mp[sc]].ta += score;
		else if(id[0] == 'B') sch[mp[sc]].tb += score;
		else sch[mp[sc]].tt += score;
		sch[mp[sc]].ns++;
	}
	rep(i, 1, 1+tot)
		sch[i].tws = int(sch[i].tb/1.5 + sch[i].ta*1.0 + sch[i].tt*1.5);
	sort(sch+1, sch+1+tot);
	cout << tot << "\n" << "1 " << sch[1].name << " " << sch[1].tws << " " << sch[1].ns;
	int rank = 1;
	rep(i, 2, tot+1){
		if(sch[i].tws != sch[i-1].tws) rank = i;
		cout << "\n" << rank << " " << sch[i].name << " " << sch[i].tws << " " << sch[i].ns;
	}
	return 0;
}

