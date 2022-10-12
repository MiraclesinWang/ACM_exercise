#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+4;
#define ull unsigned long long
struct num{
	int dex,p;
	double val;
	bool operator <(const num &n){
		if(val>n.val) return true;
		else if(val<n.val) return false;
		else return dex<n.dex;
	}
} arr[maxn];
bool resort(num a,num b) {return a.dex<b.dex;}
int main()
{
	int n;
	double a,b,c;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf",&a,&b,&c);
			arr[i].val=c/(a+b+c);
			arr[i].dex=i;
			printf("%f ",arr[i].val);
		}
		printf("\n");
		sort(arr+1,arr+n+1);
		for(int i=1;i<=n;i++) arr[i].p=i;
		sort(arr+1,arr+n+1,resort);
		for(int i=1;i<=n;i++){
			printf("%d",arr[i].p);
			printf(i==n?"\n":" ");
		}
	}
}
