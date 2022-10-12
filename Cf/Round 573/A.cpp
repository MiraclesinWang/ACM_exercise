#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if(n % 4 == 0) printf("1 A\n");
	else if(n % 4 == 1) printf("0 A\n");
	else if(n % 4 == 2) printf("1 B\n");
	else printf("2 A\n");
}
