#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define frt(x) return (x==fa[x])?x:(fa[x]=frt(fa[x]))
#define lowbit(x) x&(-x)

int n, m, cnt=0, tot = 0;
int now = 0;
struct node{
	int cnt=0, bro=-1, sn=0, fa=0;
	char c;
} trie[maxn];

//失败节点统一返回父节点编号 
int search(string s)
{
	int i = 0;
	now = 0, tot=0;
	while(i < s.length()){
		if(trie[now].sn == 0) return i;    // 没有子节点 
		now = trie[now].sn;
		while(trie[now].c != s[i]){
			if(trie[now].bro < 0) {now = trie[now].fa; return i;}    //第一个失败的位编号 
			now = trie[now].bro;
		}
		tot += trie[now].cnt;
		i++;
	}
	return i;
}

int main()
{
	rep(i, 0, maxn)
		trie[i].bro = -1, trie[i].sn = trie[i].cnt = 0;
	std::ios::sync_with_stdio(false);
	string tmp;
	scanf("%d%d", &n, &m);
	rep(times, 0, n){
		cin >> tmp;
		int dex = search(tmp), cpy = dex;
		rep(i, dex, tmp.length()){
			if(trie[now].sn == 0){   //增加子节点 
				trie[now].sn = ++cnt;
				trie[cnt].fa = now;
				trie[cnt].c = tmp[i];
				now = cnt;
			}
			else{          //增加兄节点 
				int t = trie[now].sn;
				while(trie[t].bro != -1) t = trie[t].bro;
				trie[t].bro = ++cnt;
				trie[cnt].fa = trie[t].fa;
				trie[cnt].c = tmp[i];
				now = cnt;
			}
		}
		if(cpy == tmp.length()) trie[now].cnt++;
		else trie[cnt].cnt++;
	}
	rep(times, 0, m){
		cin >> tmp;
		int dex = search(tmp);
		printf("%d\n", tot);
	}
}


