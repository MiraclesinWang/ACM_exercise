#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100
struct node{
	int dex, val;
	bool operator < (const node &oth)
	{return val < oth.val;}
};
node a[100];
int d[maxn], dex;

int main() 
{
	int n, sm = 0, al;
	scanf("%d", &n);
	scanf("%d", &al);
	sm = al;
	for(int i = 1; i < n; i++)
		scanf("%d", &a[i].val),
		a[i].dex = i+1,
		sm += a[i].val;
	sort(a+1, a+n);
	//if(al != a[n].val || a[n].val < 2*a[n-1].val) {printf("0\n");return 0;}
	sm = (sm+2) / 2;
	//printf("%d\n", sm);
	if(al >= sm) {printf("1\n1\n");return 0;}
	int lo = n-1;
	dex = 0, d[0] = 1;
	while(lo > 0 && a[lo].val*2 > al) lo--;
	if(lo == 0) {printf("0\n");return 0;}
	while(lo > 0 && al < sm) d[++dex] = a[lo].dex,al += a[lo].val, lo--;
	if(al < sm) {printf("0\n");return 0;}
	printf("%d\n1 ", dex + 1);
	for(int i = 1; i <= dex; i++)
		printf("%d", d[i]),
		printf(i == dex? "\n": " ");
}
