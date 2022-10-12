#include <bits/stdc++.h>
using namespace std;

set <char> st;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.length(); i++) st.insert(s2[i]);
	for(int i = 0; i < s1.length(); i++){
		if(st.find(s1[i]) == st.end()) cout << s1[i];
	}
}
