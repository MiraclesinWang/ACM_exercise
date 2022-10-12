#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

queue <pair<string, string> > q;

string modify(string s)
{
	bool changed = false;
	rep(i, 0, s.length()){
		if(s[i]=='1') s[i] = '@', changed = true;
		else if(s[i] == '0') s[i] = '%', changed = true;
		else if(s[i] == 'l') s[i] = 'L', changed = true;
		else if(s[i] == 'O') s[i] = 'o', changed = true;
	}
	if(changed) return s;
	else return " ";
}

int main()
{
	int n, cnt=0;
	cin >> n;
	string ac, pwd, s;
	getchar();
	rep(i, 0, n){
		getline(cin, s);
		stringstream(s) >> ac >> pwd;
		string tmp = modify(pwd);
		if(tmp[0] != ' ') q.push({ac, tmp}), cnt++; 
	}
	if(q.empty()){
		if(n==1) printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified", n);
	}
	else{
		printf("%d\n", cnt);
		while(!q.empty()){
			cout << q.front().first << " " << q.front().second;
			q.pop();
			if(!q.empty()) cout << "\n";
		}
	}
	return 0;
}

