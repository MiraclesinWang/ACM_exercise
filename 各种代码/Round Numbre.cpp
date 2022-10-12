#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, l = 0, r = 0;
	scanf("%d", &n);
	m = n;
	while(m){
		if(!(m%10)) l++, m/=10;
		else break;
	}
	while(n){
		if(!(n%2)) r++, n >>= 1;
		else break;
	}
	printf("%d %d\n", l, r);
}
