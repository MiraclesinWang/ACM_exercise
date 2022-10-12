#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f

int main()
{
	int kase, n;
	scanf("%d", &kase);
	while(kase--){
		int res = -1;
		scanf("%d", &n);
		rep(i, 1, sqrt(n)+2){
			if(n%i) continue;
			int j = n/i;
			if(i >= j) break;
			if(!((i+j)%2)) res = abs(j-i)/2;
		}
		printf("%d\n", res);
	}
}
