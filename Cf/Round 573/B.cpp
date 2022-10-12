#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int res;
	int a, b, c;
	char x, y, z;
	scanf("%d%c%d%c%d%c", &a, &x, &b, &y, &c, &z);
	if(x == y && y == z){
		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
		if(a > b) swap(a, b);
		if(a == b && b == c) res = 0;
		else if(b - a == 1 &&  c - b == 1) res = 0;
		else if(a == b || b == c) res = 1;
		else if(b - a == 1 ||  c - b == 1) res = 1;
		else if(a == b -2 || b == c - 2) res = 1;
		else res = 2;
	}
	else{
		if(x != y && y != z && x != z) res = 2;
		else{
			if(y == z) a = c;
			else if(x == z) b = c;
			if(a > b) swap(a, b);
			if(a == b || a == b - 1 || a == b - 2) res = 1;
			else res = 2;
		}
	}
	printf("%d\n", res);
}
