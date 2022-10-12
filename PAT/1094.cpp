#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define MEM(A, b) memset(A, b, sizeof(A))

const int maxn = 1e2 + 6;
vector <int> v[maxn];
int deg[maxn];
queue <pair<int, int> > q;

int main()
{
	int n, m;
	cin >> n >> m;
	rep(i, 0, m){
		int id, k, tmp;
		cin >>id >> k;
		rep(j, 0, k) cin >> tmp, v[id].push_back(tmp);
	}
	MEM(deg, 0);
	q.push({1, 1});
	while(!q.empty()){
		int id = q.front().first, dep = q.front().second;
		q.pop();
		rep(i, 0, v[id].size()) q.push({v[id][i], dep+1});
		deg[dep]++;
	}
	int d, mx = 0;
	rep(i, 1, 101){
		if(mx < deg[i]) mx = deg[i], d = i;
	}
	cout << mx << " " << d;
}
