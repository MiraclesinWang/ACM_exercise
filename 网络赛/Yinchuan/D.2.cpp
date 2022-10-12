#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t, n, m;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d", &n, &m);
		printf("Case #%d: 0.500000 %f\n", i, (double)(m+1)/(double)(2*m));
	}
}
