#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define rep(i, x, y) for(int i = x; i < y; i++)

const int maxn = 1e5 + 5;
int D[maxn], pre[maxn];

int main()
{
	int n, m;
	cin >> n >>m;
	D[0] = 0;
	rep(i, 1, n+1){
		cin >> D[i];
		D[i] += D[i-1];
	}
	int tmp = 1e9;
	rep(i, 1, n+1){
		int x = upper_bound(D, D+i, D[i]-m) - D -1;
		pre[i] = x;
		if(!~x) continue;
		if(D[i] - D[pre[i]] < tmp) tmp = D[i] - D[pre[i]];
	}
	bool first = true;
	rep(i, 1, n+1){
		if(!~pre[i]) continue;
		if(D[i] - D[pre[i]] == tmp){
			if(!first) cout << "\n";
			else first = false;
			
			cout << pre[i]+1 << "-" << i;
		}
	}
 } 
