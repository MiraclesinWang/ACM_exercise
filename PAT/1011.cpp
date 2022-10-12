#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i <y; i++)
char con[4] = {'W', 'T', 'L'};

int main()
{
	double res = 1, a, m;
	int dex;
	rep(k, 0, 3){
		cin >> a;
		dex = 0, m =a;
		rep(i, 1, 3){
			cin >> a;
			if(a > m) m=a, dex=i;
		}
		res *= m;
		cout << con[dex] << " ";
	}
	printf("%.2f", (res*0.65-1)*2);
	return 0;
}
