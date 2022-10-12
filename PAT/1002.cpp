#include <bits/stdc++.h>
using namespace std;

map <int, double> mp;
int num[100];

int main()
{
	mp.clear();
	int k, n, l =0;
	double a;
	for(int kase = 0; kase < 2; kase++){
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			scanf("%d%lf", &n, &a);
			if(mp.find(n) == mp.end()) mp[n] = a;
			else mp[n] += a;
			num[l++] = n;
		}
	}
	sort(num, num+l, greater<int>());
	int m = unique(num, num+l) - num, cpy = m;
	for(int i = 0; i < cpy; i++){
		if(abs(mp[num[i]]) < 1e-3) m--;
	}
	printf("%d", m);
	for(int i = 0; i < cpy; i++){
		if(abs(mp[num[i]]) < 1e-3) continue;
		printf(" %d %.1f", num[i], mp[num[i]]);
	}
}
/*
2 3 -0.1 1 -0.5
2 3 0.1 1 0.5
*/
