#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, q, u, v, t;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 5;
queue <ll> q1, q2, q3;
ll A[maxn];

void init()
{
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
}

int main()
{
	init();
	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	rep(i, 0, n) scanf("%lld", &A[i]);
	sort(A, A+n, greater<ll>());
	rep(i, 0, n) q1.push(A[i]);
	rep(i, 0, m){
		ll l = -INF;
		if(!q1.empty() && q1.front() > l) l = q1.front();
		if(!q2.empty() && q2.front() > l) l = q2.front();
		if(!q3.empty() && q3.front() > l) l = q3.front();
		if(!q1.empty() && q1.front() == l) q1.pop();
		else if(!q2.empty() && q2.front() == l) q2.pop();
		else q3.pop();
		
		l = l + i*q;
		ll len1 = l*u/v;
		q2.push(len1- (i+1)*q), q3.push(l - len1 - (i+1)*q);
		if(!((i+1)%t)) printf("%lld ", l);
	}
	printf("\n");
	rep(i, 0, m+n){
		ll l = -INF;
		if(!q1.empty() && q1.front() > l) l = q1.front();
		if(!q2.empty() && q2.front() > l) l = q2.front();
		if(!q3.empty() && q3.front() > l) l = q3.front();
		
		if(!q1.empty() && q1.front() == l) q1.pop();
		else if(!q2.empty() && q2.front() == l) q2.pop();
		else q3.pop();
		if(!((i+1)%t)) printf("%lld ", l+m*q);
	}
	printf("\n");
}
