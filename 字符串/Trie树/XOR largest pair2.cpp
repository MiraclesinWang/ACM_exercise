#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
const int maxn = 1e6 + 10;
int mod = (1<<30) -1 + (1<<30);
int A[maxn], cnt = 0;
struct node{
	bool have;
	int sn;
} trie[maxn*32];


void init()
{memset(trie, 0, sizeof(trie));}

void addnode(int v)
{
	int dex = 0;
	for(int i = 30; ~i; i--){
		int b = ((1<<i)&v);
		b = b?1:0;
		if(!trie[dex].sn && i) trie[dex].sn = ++cnt, ++cnt;
		dex = trie[dex].sn + b;
		trie[dex].have = true;
	}
}
int query(int v)
{
	//printf("%d\n", v);
	int dex = 0, ans = 0;
	for(int i = 30; ~i; i--){
		dex = trie[dex].sn;
		int cpy = dex, b = ((1<<i)&v);
		b = b?1:0;
		dex += b;
		if(!trie[dex].have) dex = cpy + (b^1), ans = (ans<<1) + (b^1);
		else ans = (ans<<1) + b;
	}
	return ans;
}

int main()
{
	init();
	int n, res = 0;
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", &A[i]), addnode(A[i]);
	rep(i, 0, n){
		int tmp = (mod^A[i]), ans = query(tmp);
		res = max(res, ans^A[i]);
	}
	printf("%d\n", res);
}


