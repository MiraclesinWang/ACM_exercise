#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++) 
set <int> s, rp;
const int maxn = 1e5 + 10;
int A[maxn];

int main()
{	
	int n, a;
	cin >> n;
	rep(i, 0, n){
		cin >> a;
		A[i] = a;
		if(s.find(a) == s.end()){
			s.insert(a);
		}
		else{
			if(rp.find(a) == rp.end()) rp.insert(a);
		}
	}
	rep(i, 0, n){
		if(rp.find(A[i]) == rp.end()) {cout << A[i];return 0;}
	}
	cout << "None";
 } 
