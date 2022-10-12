#include <bits/stdc++.h>
using namespace std;

#define rep(i,x, y) for(int i = x; i < y; i++)
const int maxn = 5e5 + 5;
int trie[maxn][30], n, tot, fail[maxn];
bool vis[maxn];
queue <int> q;

void insert(string s)
{
	int rt = 0;
	rep(i, 0, s.length()){
		int dex = s[i] - 'a';
		if(!trie[rt][dex]) trie[rt][dex] = tot++;
		rt = trie[rt][dex];
	}
	trie[rt][26]++;
}
void fail_calc()
{
	fail[0] = 0;
	rep(i, 0, 26){
		if(!trie[0][i]) continue;
		fail[trie[0][i]] = 0;
		q.push(trie[0][i]);
	}
	while(!q.empty()){
		int dex = q.front();
		q.pop();
		rep(i, 0, 26){
			if(!trie[dex][i]) trie[dex][i] = trie[fail[dex]][i];
			else fail[trie[dex][i]] = trie[fail[dex]][i], q.push(trie[dex][i]);
		}
	}
}
void query(string s)
{
	memset(vis, 0, sizeof(vis));
	int rt = 0, res = 0;
	rep(i, 0, s.length()){
		int dex = s[i] - 'a';
		rt = trie[rt][dex];
		for(int j=rt; j&&!vis[j]; j=fail[j]) vis[j]=1, res+=trie[j][26];
	}
	printf("%d\n", res);
}
void init()
{
	memset(trie, 0, sizeof(trie));
	tot = 1;
	while(!q.empty()) q.pop();
}
int main()
{
	ios::sync_with_stdio(false);
	int kase;
	cin >> kase;
	while(kase--){
		init(); string s;
		cin >> n;
		getline(cin, s);
		rep(i, 0, n){
			getline(cin, s);
			insert(s);
		}
		fail_calc(); getline(cin, s); query(s);
	}
}
