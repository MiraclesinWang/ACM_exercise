#include <cstdio>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	ll p, q, b, g;
	int n; scanf("%d", &n);
	while(n--) {
		scanf("%I64d %I64d %I64d", &p, &q, &b);
		q /= gcd(p, q);
		g = b;
		while(q != 1) {
			g = gcd(g, q);
			if(g == 1) break;
			while(q % g == 0) q /= g;
		}
		if(q == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
}
