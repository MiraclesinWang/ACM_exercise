#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
stack <string> q;

string reverse(string s){
	string res;
	for(int i = s.length()-1; ~i; i--) res += s[i];
	return res;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a+b;
	if(!c) {printf("0");return 0;}
	if(c<0) printf("-"), c=abs(c);
	string s;
	while(c) s+=(c%10)+'0', c/=10;
	int dex = 0;
	while(dex < s.length()){
		int r = dex+3;
		if(r < s.length()) q.push(s.substr(dex, 3));
		else q.push(s.substr(dex, s.length()-dex));
		dex += 3;
	}
	cout << reverse(q.top());
	q.pop();
	while(!q.empty()){
		cout << "," << reverse(q.top());
		q.pop();
	}
}
