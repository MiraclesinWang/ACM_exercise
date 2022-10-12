#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
#define rep(i, x, y) for(int i = x; i < y; i++)
int mod = (1<<30) -1 + (1<<30);
int A[maxn], cnt = 0, num[35];
struct node{
	bool have;
	int fa, sn;
} trie[maxn*4];


int main()
{
	memset(trie, 0, sizeof(trie));
	int n;
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d", &A[i]);
		int tmp = A[i], dex = 0;
		memset(num, 0, sizeof(num));
		while(tmp){
			if(tmp&1) num[dex]=1;
			tmp >>=1; dex++;
		}
		dex = 0;    //此时dex是trie树的节点编号 
		for(int j = 30; j >= 0; j--){
			if(!trie[dex].sn){
				trie[dex].sn = ++cnt;
				++cnt;
			}
			dex = trie[dex].sn;
			if(num[j]) dex++;
			trie[dex].have = true;
		}
	}
	int res = 0;
	rep(i, 0, n){
		memset(num, 0, sizeof(num));
		int tmp = (A[i] ^ mod), dex = 0;
		while(tmp){
			if(tmp&1) num[dex]=1;
			tmp >>=1; dex++;
		}
		
		dex = 0;    //此时是trie树的节点编号 
		int ans = 0;
		for(int j = 30; j >= 0; j--){
			dex = trie[dex].sn + num[j];
			if(trie[dex].have) ans = (ans << 1) + num[j];
			else{
				dex = (((dex-1) >> 1)<<1) + 1 + (num[j] ^1);
				ans = (ans << 1) + (num[j] ^ 1);
			}
		}
		res = max(res, ans ^ A[i]);
	}
	printf("%d\n", res);
}


