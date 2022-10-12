#include <bits/stdc++.h>
using namespace std;

#define MEM(A, b) memset(A, b, sizeof(A))
#define rep(i, x, y) for(int i  =x; i < y; i++)
const int maxn = 1e5 + 10;

bool vis[maxn];

int main()
{
	int n, m;
	cin >> n;
	MEM(vis, false);
	rep(i, 0, n){
		cin >> m;
		if(m > 0 && m <= n+3) vis[m] = true;
	}
	rep(i, 1, n+3){
		if(!vis[i]) {cout << i; return 0;}
	}
}
