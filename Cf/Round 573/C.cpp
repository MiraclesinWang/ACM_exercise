#include <cstdio>
#include <iostream>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
ll num[maxn];

int main()
{
	ll n, k;
	int m, cnt = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> num[i - 1];
	int tmp = 0;
	while(tmp < m){
		int dex = tmp;
		int mod = (num[dex] - (ll)tmp - 1) / k;
		dex += 1;
		while(dex < m){
			if((num[dex] - (ll)tmp - 1) / k == mod) dex++;
			else break;
		}
		tmp = dex;
		cnt++;
		
	}
	printf("%d\n", cnt);
}
