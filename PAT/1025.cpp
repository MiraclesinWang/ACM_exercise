#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++) 
const int maxn = 3e4 + 5;

struct ranker{
	int score, part, lk, gk;
	string id;
	bool operator < (const ranker & oth){
		if(score == oth.score) return id < oth.id;
		return score > oth.score;
	}
} r[maxn];

void get_rank(int stat, int end, bool local)
{
	int rk = 1;
	if(local){
		r[stat].lk = rk;
		rep(i, 1, end-stat){
			if(r[i+stat].score == r[i+stat-1].score) r[i+stat].lk = rk;
			else r[i+stat].lk = rk = i+1;
		}		
	}
	else{
		r[stat].gk = rk;
		rep(i, 1, end-stat){
			if(r[i+stat].score == r[i+stat-1].score) r[i+stat].gk = rk;
			else r[i+stat].gk = rk = i+1;
		}
	}
}

int main()
{
	int n, k, dex=0, p=1;
	cin >> n;
	rep(i, 0, n){
		cin >> k;
		int stat = dex;
		for(int j = 0; j < k; j++, dex++)
			cin >> r[dex].id >> r[dex].score, r[dex].part = p;
		sort(r+stat, r+dex);
		get_rank(stat, dex, true);
		p++;
	}
	sort(r, r+dex);
	get_rank(0, dex, false);
	cout << dex << "\n";
	cout << r[0].id << " " << r[0].gk << " " << r[0].part << " " << r[0].lk;
	rep(i, 1, dex)
	cout << "\n" << r[i].id << " " << r[i].gk << " " << r[i].part << " " << r[i].lk;
}
