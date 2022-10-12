#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long
#define maxn 3000 + 5
ll h[maxn][maxn];
struct Node{
	int dex;
	ll val;
	bool operator <(const Node A) {return val<A.val;}
	bool operator >(const Node A) {return val>A.val;}
} down[maxn];
Node up[maxn];
deque <Node> dq;

int main()
{
	int n, m, a, b;
	ll g, x, y, z;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	cin >> g >> x >> y >>z;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			h[i][j] = g;
			g = (x*g + y) % z;
		}
	}
	
	Node nw;
	for(int i = 1; i <= n; i++)	{
		while(!dq.empty()) dq.pop_back();
		for(int j = 1; j <= b; j++){
			nw.dex = j, nw.val = h[i][j];
			while(!dq.empty() && dq.back().val > nw.val) dq.pop_back();
			dq.push_back(nw);
			h[i][1] = dq.front().val;		
		}
 		for(int j = 2; j <= m-b+1; j++){
 			nw.dex = j + b - 1, nw.val = h[i][nw.dex];
 			while(!dq.empty() && dq.front().dex < j) dq.pop_front();
 			while(!dq.empty() && dq.back().val > nw.val) dq.pop_back();
 			dq.push_back(nw);
 			h[i][j] = dq.front().val;
		}
	}
	
	for(int i = 1; i <= m-b+1; i++)	{
		while(!dq.empty()) dq.pop_back();
		for(int j = 1; j <= a; j++){
			nw.dex = j, nw.val = h[j][i];
			while(!dq.empty() && dq.back().val > nw.val) dq.pop_back();
			dq.push_back(nw);
			h[1][i] = dq.front().val;		
		}
 		for(int j = 2; j <= n-a+1; j++){
 			nw.dex = j + a - 1, nw.val = h[nw.dex][i];
 			while(!dq.empty() && dq.front().dex < j) dq.pop_front();
 			while(!dq.empty() && dq.back().val > nw.val) dq.pop_back();
 			dq.push_back(nw);
 			h[j][i] = dq.front().val;
		}
	}
	ll res = 0;
	for(int i = 1; i <= n-a+1; i++)
		for(int j = 1; j <= m-b+1; j++)
			res += h[i][j];
	printf("%lld\n", res);

	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%lld ", h[i][j]);
		printf("\n");
	}*/
}
