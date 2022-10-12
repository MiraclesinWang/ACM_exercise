#include <bits/stdc++.h>
using namespace std;

#define rep(x, y) for(int i = x; i < y; i++)
const int maxn = 3e4 + 10;
int fa[maxn], b[maxn];   //b��ʾ���˸��ڵ��Ԫ�ظ��� 

int frt(int x)
{
	if(fa[x] == x) return x;
	int head = frt(fa[x]);
	if(fa[x] != fa[fa[x]]) b[x] += b[fa[x]];
	fa[x] = head;
	return head;
}
void merge(int x, int y)
{
	int xrt = frt(x), yrt = frt(y);
	b[xrt] = b[yrt]+1, b[yrt] += b[xrt]+1;
	fa[xrt] = yrt;
	
}

int main()
{
	memset(b, 0, sizeof(b));
	rep(0, maxn) fa[i] = i;
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
				if(fa[x] == x) res = b[y]-1;
				else if(fa[y] == y) res = b[x]-1;
				printf("%d\n", res);
			}
		}
		//rep(1, 5) printf("%d: %d %d\n", i, fa[i], b[i]);
	}
}
