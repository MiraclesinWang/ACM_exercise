#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+4;
#define ull unsigned long long
struct num{
	int dex;
	ull a,b,c;
	/*bool operator <(const num &n){
		printf("%llu %llu %llu %llu %llu %llu\n",a,b,c,n.a,n.b,n.c);
		ull l,r;
		l=a*n.c+b*n.c;
		r=c*n.a+c*n.b;
		printf("%llu %llu\n",l,r);
		if(l>r) return false;
		else if(l<r) return true;
		else return dex<n.dex;
	}*/
} arr[maxn];
bool cmp(num x,num y){
	ull l=x.a*y.c+x.b*y.c;
	ull r=y.a*x.c+y.b*x.c;
	if(l<r) return true;
	else if(l>r) return false;
	else return x.dex<y.dex;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%llu%llu%llu",&arr[i].a,&arr[i].b,&arr[i].c);
			arr[i].dex=i;
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++){
			printf("%d",arr[i].dex);
			printf(i==n?"\n":" ");
		}
	}
}
/*3
100000005 100000006 2
100000005 100000004 2
100 60 3
*/
