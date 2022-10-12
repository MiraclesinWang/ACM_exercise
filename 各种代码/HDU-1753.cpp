#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	char * s, a1, a2, b1, b2;
	while(scanf("%s", s) != EOF){
		sscanf(s, "%s.%s %s.%s", a1, b1, a2, b2);
		printf("%s %s %s %s\n", a1, b1, a2, b2);
		scanf("\n");
	}
}
