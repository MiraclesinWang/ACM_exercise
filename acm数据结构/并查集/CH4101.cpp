#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 3e4 + 10;
int fa[maxn], b[maxn], cnt[maxn];   //b表示除了根节点的元素个数 

int frt(int x)
{
	if(fa[x] == x) return x;
	int head = frt(fa[x]);
	b[x] += b[fa[x]];
	fa[x] = head;
	return head;
}
void merge(int x, int y)
{
	int xrt = frt(x), yrt = frt(y);
	b[xrt] = cnt[yrt], cnt[yrt] += cnt[xrt], cnt[xrt] = 0;
	fa[xrt] = yrt;
}

int main()
{
	memset(b, 0, sizeof(b));
	rep(0, maxn) fa[i] = i, cnt[i] = 1;
	int t;
	scanf("%d", &t);
	rep(0, t){
		int x, y;
		char c;
		scanf("\n%c%d%d", &c, &x, &y);
		if(c == 'M') merge(x, y);
		else{
			int xrt = frt(x), yrt = frt(y);
			if(xrt!=yrt) printf("-1\n");
			else{
				int res = abs(b[x]-b[y])-1;
				printf("%d\n", res);
			}
		}
		//rep(1, 5) printf("%d: %d %d %d\n", i, fa[i], b[i], cnt[i]);
	}
}
