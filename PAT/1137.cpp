#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 4e4 + 10;

struct student{
	int mt, ft, ps, gpa;
	string id;
	student(){mt=ft=ps=-1, gpa=0.0;}
	bool operator < (const student &oth){
		if(oth.gpa == gpa) return id < oth.id;
		return gpa > oth.gpa;
	}
} st[maxn], qual[maxn];
map <string, int> mp;

int main()
{
	int p, n, m, score, tot=0;
	cin >> p >> m >> n;
	string id;
	rep(i, 0, p){
		getchar();
		cin >> id >> score;
		if(mp.find(id) == mp.end()){
			st[tot].id = id;
			st[tot].ps = score;
			mp[id] = tot++;
		}
		else st[mp[id]].ps = score;
	}
	
	rep(i, 0, m){
		getchar();
		cin >> id >> score;
		if(mp.find(id) == mp.end()){
			st[tot].id = id;
			st[tot].mt = score;
			mp[id] = tot++;
		}
		else st[mp[id]].mt = score;
	}
	
	rep(i, 0, n){
		getchar();
		cin >> id >> score;
		if(mp.find(id) == mp.end()){
			st[tot].id = id;
			st[tot].ft = score;
			mp[id] = tot++;
		}
		else st[mp[id]].ft = score;
	}
	int dex = 0;
	rep(i, 0, tot){
		if(st[i].ps >= 200){
			st[i].gpa = round(st[i].mt > st[i].ft?0.4*st[i].mt+0.6*st[i].ft:(double)st[i].ft);
			if(st[i].gpa >=60) qual[dex++] = st[i];
		} 
	}
	sort(qual, qual+dex);
	rep(i, 0, dex){
		cout << qual[i].id << ' ' << qual[i].ps << ' ' << qual[i].mt << ' ' << qual[i].ft << ' ' << qual[i].gpa;
		if(i<dex-1) cout << "\n";
	}
	
	return 0;
}

