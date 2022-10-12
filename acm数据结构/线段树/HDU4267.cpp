#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5e4 + 10;
int lzy[maxn], t[maxn];

void build(int l, int r, int dex)
{
	lzy[dex] = 0;
	if(l != r){
		int mid = (l+r)>>1;
		build(l, mid, 2*dex), build(mid+1, r, dex*2+1);
	}
}
void update(int l, int r, int dex, int x, int y, int val)
{
	if(l >= x && r <= y) lzy[dex] += val;
	else if(l > y || r < x) return;
	else{
		int mid = (l+r)>>1;
		update(l, mid, dex*2, x, y, val), update(mid+1, r, dex*2+1, x, y, val);
	}
}
int query(int l, int r, int dex, int trgt)
{
	if(l == r) return t[trgt] + lzy[dex];
	else{
		int mid=(l+r)>>1;
		lzy[dex*2] += lzy[dex], lzy[dex*2+1]+=lzy[dex];
		lzy[dex] = 0;
		if(mid >= trgt) return query(l, mid,dex*2, trgt);
		else return query(mid+1, r, dex*2+1, trgt);
	}
}

int main()
{
	int n, q, a, b, k, c, cmd;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++)
			scanf("%d", &t[i]);
		scanf("%d", &q);
		build(1, n, 1);
		for(int i = 0; i < q; i++){
			scanf("%d%d", &cmd, &a);
			if(cmd == 2) printf("%d\n", query(1, n, 1, a));
			else{
				scanf("%d%d%d", &b, &k, &c);
				update(1, n, )
			}
		}
	}
}
