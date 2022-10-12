#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e4 + 5;

map <string, string> mp;
set <string> checked;

bool is_prime(int num)
{
	bool flag = true;
	rep(i, 2, int(sqrt(num))+2){
		if(!(num%i)) {flag = false;break;}
	}
	return flag;
}

int main()
{
	int n, k;
	string id;
	cin >> n;
	rep(i, 1, n+1){
		getchar();
		cin >> id;
		if(i==1) mp[id] = "Mystery Award";
		else if(is_prime(i)) mp[id] = "Minion";
		else mp[id] = "Chocolate";
	}
	cin >> k;
	rep(i, 0, k){
		getchar();
		cin >> id;
		cout << id << ": ";
		if(checked.find(id) != checked.end()) cout << "Checked";
		else{
			if(mp.find(id) == mp.end()) cout << "Are you kidding?";
			else cout << mp[id], checked.insert(id);
		}
		if(i!=k-1) cout << "\n";
	}
	return 0;
}

