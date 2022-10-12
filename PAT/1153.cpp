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

struct testee{
	string id, site, date;
	char level;
	int score;
	bool operator < (const testee &oth){
		if(score == oth.score) return id < oth.id;
		return score > oth.score;
	}
	testee(){}
	testee(string _s, int _n):id(_s), score(_n){}
} tst[maxn];

unordered_map <string, int> mt, md, mp;
map <char, int> ml;
vector <testee> ll[maxn], tt[maxn], dd[maxn], pp;

int main()
{
	int n, m;
	cin >> n >> m;
	rep(i, 0, n){
		getchar();
		cin >> tst[i].id >> tst[i].score;
		tst[i].level = tst[i].id[0];
		tst[i].site = tst[i].id.substr(1, 3);
		tst[i].date = tst[i].id.substr(4, 6);
		if(ml.find(tst[i].level) == ml.end()) ml[tst[i].level] = ml.size();
		if(mt.find(tst[i].site) == mt.end()) mt[tst[i].site] = mt.size();
		if(md.find(tst[i].date) == md.end()) md[tst[i].date] = md.size();
		ll[ml[tst[i].level]].push_back(tst[i]);
		tt[mt[tst[i].site]].push_back(tst[i]);
		dd[md[tst[i].date]].push_back(tst[i]);
	}
	rep(i, 0, m){
		string id;
		int cmd;
		cin >> cmd >> id;
		cout << "Case " << i+1 << ": " <<cmd << " " << id << "\n";
		if(cmd==1){
			int dex = ml[id[0]];
			sort(ll[dex].begin(), ll[dex].end());
			if(ll[dex].size()){
				rep(j, 0, ll[dex].size()){
					cout << ll[dex][j].id << " " << ll[dex][j].score;
					if(j < ll[dex].size()-1) cout << "\n";
				}
			}
			else cout << "NA";
		}
		else if(cmd == 2){
			int dex = mt[id], ns =0;
			if(tt[dex].size()){
				rep(j, 0, tt[dex].size()) ns += tt[dex][j].score;
				cout << tt[dex].size() << " " << ns;
			}
			else cout << "NA";
		}
		else{
			int dex = md[id];
			mp.clear();
			if(dd[dex].size()){
				rep(j, 0, dd[dex].size()){
					if(mp.find(dd[dex][j].site) == mp.end()) mp[dd[dex][j].site] = 0;
					mp[dd[dex][j].site]++;
				}
				for(auto i = mp.begin(); i!=mp.end(); i++){
					pp.push_back(testee(i->first, i->second));
				}
				sort(pp.begin(), pp.end());
				rep(i, 0, pp.size()){
					cout << pp[i].id << " " << pp[i].score;
					if(i < pp.size()-1) cout << "\n";
				}
			}
			else cout << "NA";
		}
		if(i < m-1) cout << "\n";
	}
	return 0;
}

