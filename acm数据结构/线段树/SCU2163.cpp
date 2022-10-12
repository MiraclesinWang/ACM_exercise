#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 8e3 + 10;
int tree[maxn*8], p[maxn], res[maxn];

void build(int l, int r, int dex)
{
	if(l == r) tree[dex] = 1;
	else{
		int mid = (l+r)>>1;
		build(l, mid, dex*2), build(mid+1, r, dex*2+1);
		tree[dex] = tree[dex*2] + tree[dex*2+1];
	}
}
int query(int l, int r, int dex, int k)
{
	if(l == r) return l;
	int mid = (l+r)>>1;
	if(k <= tree[dex*2]) return query(l, mid, dex*2, k);
	else return query(mid+1, r, dex*2+1, k - tree[dex*2]);
 } 
void update(int l, int r, int dex, int x)
{
	if(l <= x && r >= x){
		tree[dex]--;
		if(l != r){
			int mid = (l+r)>>1;
			update(l, mid, dex*2, x), update(mid+1, r, dex*2+1, x);
		}
	}
 } 

int main()
{
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 2; i <= n; i++) scanf("%d", &p[i]);
		p[0] = 0;
		build(1, n, 1);
		for(int i = n; i; i--){
			res[i] = query(1, n, 1, p[i]+1);
			update(1, n, 1, res[i]);
		}
		for(int i = 1; i <= n; i++) printf("%d\n", res[i]);		
	}
}
