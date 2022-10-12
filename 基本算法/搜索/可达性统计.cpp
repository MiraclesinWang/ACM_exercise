#include <bits/stdc++.h>
using namespace std;

const int maxm = 3e4 + 10;
typedef long long ll;
const int maxn = 1e6;
#define rep(i, x, y) for(int i = x; i < y; i++)
#define lowbit(x) x&(-x)
int m, n, fa[maxm], cnt[maxm];
int frt(int x)
{
	if(x==fa[x]) return x;
	else{
		if(fa[x] != fa[fa[x]]) cnt[fa[x]] += cnt[x];
		fa[x]=frt(fa[x]);
		return fa[x];
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    rep(i, 1, n+1) fa[i] = i, cnt[i] = 1;
    int u, v;
    rep(i, 0, m){
    	scanf("%d%d", &u, &v);
    	fa[frt(v)] = frt(u);
	}
	rep(i, 1, n+1) frt(i);
    rep(i, 1, n+1) printf("%d\n", cnt[i]);
}

