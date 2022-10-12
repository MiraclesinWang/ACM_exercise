#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define maxn 100000 + 10
ll p[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &p[i]);
	if(n == 1){
		if(p[1] % 2 == 0) printf("cslnb\n"); 
		else printf("sjfnb\n");
	}
	else if(n == 2){
		if((p[1] + p[2]) % 2 == 0) printf("sjfnb\n");//ÏÈÊÖÊ¤Àû 
		else printf("cslnb\n");    
	}
	else{
		int cnt = 0;
		sort(p + 1, p +1 +n);
		for(int i = 1; i < n; i++)
			if(p[i] == p[i + 1]) cnt++;
		if(cnt > 1 || (p[1] ==p[2] && p[1] == 0)) printf("cslnb\n");
		else if(cnt != 1){
			if(n % 2 == 0){
				ll sm = 0;
				for(int i = 1; i <= n; i++)
					sm += p[i];
				ll base = (ll)(n - 1) *(ll)n / 2;
				if((sm - base) % 2 == 0) printf("cslnb\n");
				else printf("sjfnb\n");
			}	
			else{
				ll sm = 0;
				for(int i = 1; i <= n; i++)
					sm += p[i];
				ll base = (ll)(n - 1) *(ll)n / 2;	
				if((sm - base) % 2 == 0) printf("cslnb\n");
				else printf("sjfnb\n");		
			}
		}
		else{
			int dex;
			for(int i = 1; i < n; i++)
				if(p[i] == p[i+1]) dex = i;
			if(dex > 1 && p[dex] == p[dex-1] + 1) {printf("cslnb\n");return 0;}
			if(n % 2 == 0){
				ll sm = 0;
				for(int i = 1; i <= n; i++)
					sm += p[i];
				ll base = (ll)(n - 1) *(ll)n / 2;
				if((sm - base) % 2 == 0) printf("sjfnb\n");
				else printf("cslnb\n");
			}	
			else{
				ll sm = 0;
				for(int i = 1; i <= n; i++)
					sm += p[i];
				ll base = (ll)(n - 1) *(ll)n / 2;	
				if((sm - base) % 2 == 0) printf("sjfnb\n");
				else printf("cslnb\n");		
			}				
		}
	}

}
