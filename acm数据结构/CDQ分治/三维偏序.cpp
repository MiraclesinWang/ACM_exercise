#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i =x; i < y; i++)
const int maxn = 1e5 + 10;

int res[maxn];

struct elem{
	int a, b, c, val, cnt, dex;
	bool operator < (const elem &oth){
		if (a != oth.a) return a < oth.a;
		if (b != oth.b) return b < oth.b;
		return c < oth.c;
	}
	bool operator == (const elem &oth){
		if (a==oth.a && b==oth.b && c==oth.c) return true;
		return false;
	}
}E[maxn], EE[maxn], tmp[maxn], smp[maxn], ans[maxn];

void InCDQ(int l, int r)
{
	if(l == r) return;
	int mid = (l+r) >> 1;
	InCDQ(l, mid), InCDQ(mid+1, r);
	int d1 = l, d2 = mid+1, cnt =0;
	rep(i, l, r+1){
		if(d1 > mid || (d2 <= r && tmp[d1].c > tmp[d2].c)){
			if(tmp[d2].a == 1) ans[tmp[d2].dex].cnt += cnt;
			smp[i] = tmp[d2++];
			
		}
		else{
			if(tmp[d1].a == 0) cnt += tmp[d1].val;
			smp[i] = tmp[d1++];
		}
	}
	rep(i, l, r+1) tmp[i] = smp[i];
}

void CDQ(int l, int r)
{
	if(l==r) return;
	int mid = (l+r) >> 1;
	CDQ(l, mid), CDQ(mid+1, r);
	int d1 = l, d2 = mid+1;
	rep(i, l, r+1){
		if(d1 > mid || (d2 <= r && E[d1].b > E[d2].b))
			tmp[i] = E[d2++], tmp[i].a = 1;
		else
			
			tmp[i] = E[d1++], tmp[i].a = 0;
	}
	rep(i, l, r+1) E[i] = tmp[i];
	InCDQ(l, r); 
}

int main()
{
	int n, k, m=0;
	scanf("%d%d", &n, &k);
	rep(i, 0, n) scanf("%d%d%d", &EE[i].a, &EE[i].b, &EE[i].c);
	sort(EE, EE+n);
	E[0] = EE[0], E[0].dex=0, E[0].val=1, E[0].cnt=0;
	rep(i, 1, n){
		if(EE[i] == E[m]) E[m].val++, E[m].cnt++;
		else E[++m] = EE[i], E[m].val=1, E[m].dex=m, E[m].cnt = 0;
	}
	memcpy(ans, E, sizeof(E));
	CDQ(0, m);
	memset(res, 0, sizeof(res));
	rep(i, 0, m+1) res[ans[i].cnt] += ans[i].val;
	rep(i, 0, n){
		printf("%d\n", res[i]);
	}
}

