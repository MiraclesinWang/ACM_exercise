#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 4e4 + 10;
int a[maxn], cnt[205][maxn], all[maxn], tmp[maxn], l, t, most[205][205], s, n;
map <int, int> mp;
map <int, int> pq;

void init()
{
	memset(cnt, 0, sizeof(cnt));
	sort(all, all+n);
	l = unique(all, all+n) - all;
	t = pow(n, 1.0/3.0), s = n/t;
	
	rep(0, l) mp[all[i]] = i;
	rep(0, t)
		for(int j = i*s; j < (i+1)*s; j++)
			cnt[i][mp[a[j]]]++;
	rep(t*s, n) cnt[t][mp[a[i]]]++;
	rep(1, t+1) 
		for(int j = 0; j < l; j++)
			cnt[i][j] += cnt[i-1][j];
	rep(1, t)
		for(int j = i; j < t; j++){
			int m = 0;
			for(int k = 0; k < l; k++){
				if(cnt[j+1][k] - cnt[i-1][k] > m)
					m = cnt[j+1][k] - cnt[i-1][k], most[i][j] = k;
				else if(cnt[j+1][k] - cnt[i-1][k] == m && all[k] < all[most[i][j]]) most[i][j] = k;				
			}
		}
}

int query(int p, int q)
{
	//printf("%d %d\n", p, q);
	pq.clear();
	int k1 = p/s, k2 = q/s;
	int m = 0, res;
	if(k1 >= k2-1){
		rep(p, q+1){
			if(pq.find(mp[a[i]]) == pq.end()) pq[mp[a[i]]] = 1;
			else pq[mp[a[i]]]++;
			if(pq[mp[a[i]]] > m) m = pq[mp[a[i]]], res = a[i];
			else if(pq[mp[a[i]]] == m && a[i] < res) res = a[i];
			//printf("%d %d %d %d %d\n",i, a[i],mp[a[i]],pq[mp[a[i]]], res);
		}
		return res;
	}
	pq[all[most[k1+1][k2-1]]] = cnt[k2-1][most[k1+1][k2-1]] - cnt[k1][most[k1+1][k2-1]];
	rep(p, k1*s){
		if(pq.find(a[i]) == pq.end()) pq[a[i]] = 1+cnt[k2-1][mp[a[i]]]-cnt[k1][mp[a[i]]];
		else pq[a[i]]++;
		if(pq[a[i]] > m) m = pq[a[i]], res = a[i];
		else if(pq[a[i]] == m && a[i] < res) res = a[i];
	}
	rep(k2*s, q+1){
		if(pq.find(a[i]) == pq.end()) pq[a[i]] = 1+cnt[k2-1][mp[a[i]]]-cnt[k1][mp[a[i]]];
		else pq[a[i]]++;
		if(pq[a[i]] > m) m = pq[a[i]], res = a[i];
		else if(pq[a[i]] == m && a[i] < res) res = a[i];		
	}
	return res;
}

int main()
{
	int m, x = 0;
	scanf("%d%d", &n , &m);
	rep(0, n) scanf("%d", &a[i]), all[i] = a[i];
	init();
	rep(0, m){
		int p, q;
		scanf("%d%d", &p, &q);
		p = (x+p-1)%n, q = (x+q-1)%n;
		if(p > q) swap(p, q);
		x = query(p, q);
		printf("%d\n", x);
	}
}
