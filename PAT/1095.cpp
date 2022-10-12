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

struct record{
	int tm, tot;
	string id;
	bool in, eff;
	bool operator < (const record &oth) {return tm < oth.tm;}
} r[maxn], tr[maxn];

struct time_length{
	int tm;
	string id;
	bool operator < (const time_length &oth){
		if(tm == oth.tm) return id < oth.id;
		else return tm > oth.tm;
	}
} fnl[maxn];

map <string, int> pre, interval;
int T[maxn];

int main()
{
	int n, m, k = 0;
	cin >>n >> m;
	rep(i, 1, n+1){
		int hh, mm, ss;
		string stat;
		getchar();
		cin >> r[i].id;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		r[i].tm = hh*3600 + mm*60 + ss;
		cin >> stat;
		if(stat == "in") r[i].in = true;
		else r[i].in = false;
	}
	
	sort(r+1, r+1+n);
	rep(i, 1, n+1){
		r[i].eff = true;
		if(r[i].in){
			if(pre.find(r[i].id) != pre.end()) r[pre[r[i].id]].eff = false;
			pre[r[i].id] = i;
		}
		else{
			if(pre.find(r[i].id) == pre.end()) {r[i].eff=false;continue;}
			if(interval.find(r[i].id) == interval.end()){
				interval[r[i].id] = r[i].tm-r[pre[r[i].id]].tm;
			}
			else interval[r[i].id] += r[i].tm-r[pre[r[i].id]].tm;
			pre.erase(pre.find(r[i].id));
		}
	}
	for(int i = n; i; i--)
		if(pre.find(r[i].id) != pre.end()){
			r[i].eff = false;
			pre.erase(pre.find(r[i].id));
		}
	rep(i, 1, n+1){
		if(r[i].eff) tr[++k] = r[i];
	}
		
	tr[0].tot = 0, tr[0].tm = -1;
	rep(i, 1, k+1){
		if(tr[i].in) tr[i].tot = tr[i-1].tot+1;
		else tr[i].tot = tr[i-1].tot-1;
	}
	rep(i, 0, k+1) T[i] = tr[i].tm;
	rep(i, 0, m){
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int query = hh*3600 + mm*60 + ss;
		int dex = upper_bound(T, T+k+2, query) - T;
		cout << tr[dex-1].tot << "\n";
	}
	
	int dex = 0;
	for(auto i = interval.begin(); i != interval.end(); i++, dex++)
		fnl[dex].id= i->first, fnl[dex].tm = i->second;
	sort(fnl, fnl+dex);
	int mx_tmp = fnl[0].tm, d = 0;
	while(d < dex){
		if(mx_tmp == fnl[d].tm) cout << fnl[d].id << " ";
		d++;
	}
	printf("%02d:%02d:%02d", mx_tmp/3600, mx_tmp%3600/60, mx_tmp%60);
	return 0;
}
/*JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in

JH007BD 05:09:59 in
JH007BD 05:10:33 in
JH007BD 12:23:42 out
JH007BD 12:24:23 out
JH007BD 18:00:01 in
JH007BD 18:07:01 out*/

