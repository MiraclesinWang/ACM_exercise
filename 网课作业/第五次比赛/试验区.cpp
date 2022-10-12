#include<cstdio>
#include<cmath>
using namespace std;
#define maxn 100000+5
#define ll long long
struct Node{
	ll value;
	int tms;
	ll &operator =(const ll l) {value=l;return value;}
};
int main()
{
	int a=8;
	a=sqrt(a);
	printf("%d\n",a);
}
