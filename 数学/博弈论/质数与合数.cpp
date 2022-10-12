#include <bits/stdc++.h>
using namespace std;

const int maxn = 474747 + 10;
int prime[maxn];

int main()
{
	int n, k, win = -1;
	scanf("%d%d", &n, &k);
	prime[2] = prime[3] = -1; prime[1] = prime[0] = 0;
	for(int i = 4; i <= n; i++){
		bool flag = true;
		for(int j = 2; j <= int(sqrt(i)) + 1; j++)
			if(!(i%j)) {flag = false;break;}
		if(flag) prime[i] = -1;
		else{
			if(prime[i-1] < 0) prime[i] = 1;
			else prime[i] = prime[i-1] + 1;
			if(prime[i] > k) win = i;
		}
	}
	
	
	int res = 0;
	if(n < 3) {printf("0\n");return 0;}
	if(k == 1){
		n--;
		while(true){
			if(prime[n] < 0) res = -res+1, n--;
			else break;
			if(prime[n] > 0) res = -res-1, n--;
			else break;
		}
		printf("%d\n", res); return 0;
	}
	
	if(win > 0){
		while(n > win){
			res+=2; n -= prime[n];
			if(n - k <= win) n = win;
			else{
				n -= k;
				if(prime[n] < 0) n++;
			}
		}
		res = -res;
	}
	else{
		if(n == 3) res = 1;
		while(n > 3){
			res++;
			int tmp = n - k;
			if(tmp <= 3) break;
			while(n >= tmp){
				if(prime[n] > 0){
					if(n - prime[n] >= tmp) n -= prime[n];
					else break;
				}
				else n--;
			}
			if(n < tmp || prime[n] > 0) n++; 
			if(n < 4) break;
			res++; n--;
			if(prime[n] < 0) n--;
		}
	}
	printf("%d\n", res);
}
