#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+4;
#define ll long long
struct num{
	int dex,p;
	ll a,b,c;
	bool operator <(const num &n){
		ll l,r;
		l=a*n.c+b*n.c;
		r=c*n.a+c*n.b;
		printf("%lld %lld\n",l,r);
		if(l>r) return false;
		else if(l<r) return true;
		else return dex<n.dex;
	}
} arr[maxn];
bool resort(num a,num b) {return a.dex<b.dex;}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
			arr[i].dex=i;
		}
		sort(arr+1,arr+n+1);
		for(int i=1;i<=n;i++) arr[i].p=i;
		sort(arr+1,arr+n+1,resort);
		for(int i=1;i<=n;i++){
			printf("%d",arr[i].p);
			printf(i==n?"\n":" ");
		}
	}
}
