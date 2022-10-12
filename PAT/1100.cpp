#include <bits/stdc++.h>
using namespace std;

#define MEM(A, b) memset(A, b, sizeof(A))
#define rep(i, x, y) for(int i = x; i < y; i++)

map <string, int> decimal = {{"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3},
 {"apr", 4}, {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8}, 
 {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}};
 
map <string, int> final = {{"tret", 0}, {"tam", 1}, {"hel", 2}, 
 {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6}, {"hei", 7}, 
 {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};
 
string first[20] = {"tret", "tam", "hel", "maa", "huh", "tou", 
"kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string second[20] = {"tret", "jan", "feb", "mar", "apr", 
"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

void mar2ear(string s)
{
	if(s.length() > 4){
		string a, b;
		stringstream(s) >> a >> b;
		cout << 13 * final[a] + decimal[b];
	}
	else{
		if(final.find(s) == final.end()) cout << decimal[s];
		else cout << 13* final[s];
	}
}

void ear2mar(string s)
{
	int a = 0, b=1;
	for(int i= s.length()-1; ~i;i--){
		a += (s[i]-'0') *b;
		b *=10;
	}
	if(!(a%13)) {cout << first[a/13];return;}
	if(a>=13) cout << first[a/13] << " ", a%=13;
	cout << second[a];
}

int main()
{
	int n;
	string s;
	cin >> n;
	getchar();
	rep(i, 0, n){
		getline(cin, s);
		if(s[0] >= '0' && s[0] <= '9') ear2mar(s);
		else mar2ear(s);
		if(i<n-1) cout << "\n";
	}
}
