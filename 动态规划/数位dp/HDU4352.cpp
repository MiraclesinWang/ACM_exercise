#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
typedef long long ll;
std::map<string, int> todex;
string tostr[1000];
int tot = 0;

void Recur(string s, int last)
{
	rep(last+1, 10){
		todex[s+char(i+'0')] = tot;
		tostr[tot++] = s + char(i+'0');
		cout << tostr[tot-1] << '\n';
		Recur(s+char(i+'0'), i);
	}
}

void init()
{
	Recur("", -1);
}

int main()
{
	init();
}
