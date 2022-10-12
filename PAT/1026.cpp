#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

struct player{
	int tm, need, wt, dex;
	player(int _t, int _n):tm(_t), need(_n){}
	player(int _t, int _n, int _w, int _d):tm(_t), need(_n), wt(_w), dex(_d){}
	player(){}
	bool operator < (const player &oth) const
	{return tm > oth.tm;}
};
priority_queue <player> vip, pq, tb;
vector <player> v;
set <int> vip_s;
int server[110];

int main()
{
	int n, m, k;
	cin >> n;
	rep(i, 0, n){
		int hh, mm, ss, nd, V;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &nd, &V);
		nd = min(nd*60, 2*3600);
		if(V) vip.push(player(3600*hh+60*mm+ss, nd));
		else pq.push(player(3600*hh+60*mm+ss, nd));
	}
	cin >> m >> k;
	rep(i, 0, k){
		int tmp;
		cin >> tmp;
		vip_s.insert(tmp);
	}
	rep(i, 1, m+1){
		if(vip_s.find(i) == vip_s.end()) tb.push(player(8*3600, 0, 0, i));
		else tb.push(player(8*3600, 1, 0, i));
	}
	
	while(true){
		if(vip.empty() && pq.empty()) break;
		if(tb.top().tm > 21*3600) break;
		player t = tb.top(), p;
		tb.pop();
		
		if(t.need){
			if(vip.empty()) p = pq.top(), pq.pop();
			else if(vip.top().tm > t.tm && pq.top().tm < vip.top().tm)p = pq.top(), pq.pop();
			else p = vip.top(), vip.pop();
		}
		else{
			if(vip.empty() || (!pq.empty() && pq.top().tm < vip.top().tm)) p = pq.top(), pq.pop();
			else p = vip.top(), vip.pop();
		}
		
		printf("%d %d %d\n", p.tm, t.tm, t.need);
		if(p.tm < t.tm) printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n", p.tm/3600, p.tm%3600/60, p.tm%60, t.tm/3600, t.tm%3600/60, t.tm%60, round((t.tm-p.tm)/60.0));
		//if(p.tm < t.tm) printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", p.tm/3600, p.tm%3600/60, p.tm%60, t.tm/3600, t.tm%3600/60, t.tm%60, round((t.tm-p.tm)/60.0));
		else printf("%02d:%02d:%02d %02d:%02d:%02d 0\n", p.tm/3600, p.tm%3600/60, p.tm%60, p.tm/3600, p.tm%3600/60, p.tm%60);
		/*if(p.tm < t.tm) v.push_back(player(p.tm, t.tm));
		else v.push_back(player(p.tm, p.tm));*/
		t.tm = max(p.tm, t.tm) + p.need, t.wt++;
		tb.push(t);
		printf("%02d:%02d:%02d\n", t.tm/3600, t.tm%3600/60, t.tm%60);
	}
	while(!tb.empty()){
		server[tb.top().dex] = tb.top().wt;
		tb.pop();
	}
	rep(i, 1, m+1){
		printf("%d", server[i]);
		if(i < m) printf(" ");
	}
	return 0;
}

