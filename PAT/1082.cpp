#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

map <int, string> mp = {{0, "ling"}, {1, "yi"}, {2, "er"}, {3, "san"}, 
{4, "si"}, {5, "wu"}, {6, "liu"}, {7, "qi"}, {8, "ba"}, {9, "jiu"}};

int main()
{
	int s, p;
	bool flag = false;
	scanf("%d", &s);
	if(s ==0) {cout << "ling"; return 0;}
	if(s < 0) {cout << "Fu ", s = abs(s);}
	if(p= s/int(1e8)){
		if(p/10) cout << "shi ";
		if(p%10) cout << mp[p%10] << " ";
		cout << "Yi";
		s %= int(1e8);
		if(s) cout << " ";
		flag = true;
	}
	if(p = s/int(1e4)){
		bool zero = false;
		if(p/1000) cout << mp[p/1000] << " Qian ", p%=1000, flag = true;
		else if(p && flag && !zero) cout << "ling ", zero = true;
		if(p/100) cout << mp[p/100] << " Bai ", p%=100, flag = true;
		else if(p && flag && !zero) cout << "ling ", zero = true;
		if(p/10) cout << mp[p/10] << " Shi ", p%=10, flag = true;
		else if(p && flag && !zero) cout << "ling ", zero=true;
		if(p) cout << mp[p] << " ", zero = true;
		cout << "Wan";
		s %= int(1e4);
		if(s) cout << " ";
		flag = true;
	}
	if(p=s){
		bool zero = false;
		if(p/1000){
			cout << mp[p/1000] << " Qian", p%=1000, flag = true;
			if(p) cout << " ";
		}
		else if(p && flag && !zero) cout << "ling ", zero = true;
		if(p/100){
			cout << mp[p/100] << " Bai", p%=100, flag = true;
			if(p) cout << " ";
		}
		else if(p && flag && !zero) cout << "ling ", zero = true;
		if(p/10){
			cout << mp[p/10] << " Shi", p%=10, flag = true;
			if(p) cout << " ";
		}
		else if(p && flag && !zero) cout << "ling ", zero=true;
		if(p) cout << mp[p], zero = true;
		s %= int(1e4);
	}
	return 0;
}

