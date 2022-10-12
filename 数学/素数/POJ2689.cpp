#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 1e6 + 10;
bool vis[maxn];
int prime[maxn], tot = 0;
stack<int>q;

void init()
{
	memset(vis, false, sizeof(vis));
	rep(2, int(1e6)){
		if(!vis[i]){
			prime[tot++] = i;
			for(int j = 0; j < tot; j++){
				if(prime[j]*i > (1<<16)) break;
				vis[prime[j]*i] = true;
			}
		}
	}
}

int main()
{
	init();
	int l, r;
	while(scanf("%d%d", &l, &r) != EOF){
		int d1 = 1e7, m1, n1, d2 = -1, m2, n2;
		memset(vis, false, sizeof(vis));
		rep(0, tot){
			int a = max(l / prime[i], 2), b = r/prime[i];
			if(a*prime[i] < l) a++; 
			for(unsigned j = a*(prime[i]); j <= b*prime[i]; j += prime[i])
				vis[j-l] = true;
		}
		if(l==1) vis[0] = true;
		while(!q.empty()) q.pop();
		rep(0, r-l+1){
			if(vis[i]) continue;
			if(!q.empty()){
				if(i+l-q.top() < d1)
					d1 = i+l-q.top(), m1 = q.top(), n1 = i+l;
				if(i+l-q.top() > d2)
					d2 = i+l-q.top(), m2 = q.top(), n2 = i+l;
			}
			q.push(i+l);
		}
		if(d2 < 0) printf("There are no adjacent primes.\n");
		else printf("%d,%d are closest, %d,%d are most distant.\n", m1, n1, m2, n2);
	}
 } 
