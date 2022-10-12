#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)

int main()
{
	string s;
	cin >> s;
	int n = s.length(), h = (n+2)/3, w = n-2*h;
	rep(i, 0, h-1){
		printf("%c", s[i]);
		rep(j, 0, w) printf(" ");
		printf("%c\n", s[n-i-1]);
	}
	rep(i, h-1, n-h+1) printf("%c", s[i]);
}
