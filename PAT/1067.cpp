#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 1e5 + 10;
bool vis[maxn];
int A[maxn];

int main()
{
	memset(vis, false, sizeof(vis));
	int n, cnt=0;
	cin >> n;
	rep(i, 0, n){
		cin >> A[i];
		if(A[i] == i) vis[i] = true, cnt--;
	}
	if(A[0] == 0) cnt+=2;
	rep(i, 0, n){
		if(vis[i]) continue;
		cnt++;
		vis[i] = true;
		for(int j = A[i]; j!=i; j = A[j]) vis[j] = true;
	}
	cout << n -2 + cnt;
}

/*
0 2 1 4 3      gt: 6
0 2 3 4 1      gt: 5
0 1 3 4 2      gt: 4

2 1 3 4 0
2 1 3 0 4
2 1 0 3 4
0 1 2 3 4

1 2 3 4 0
1 2 3 0 4
1 2 0 3 4
1 0 2 3 4
0 1 2 3 4
*/
