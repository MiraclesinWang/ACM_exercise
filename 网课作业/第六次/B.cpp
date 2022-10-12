#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
#define maxn 500000+5
#define ll long long
int lowbit(int x) {return x&(-x);}
struct Node{
	int d;
	ll val;
	bool operator <(const Node A) {return val<A.val;}
};
Node dot[maxn];
int tree[maxn];
void init(int n)
{
	for(int i=1;i<=n;i++)
		tree[i]=(ll)lowbit(i);
}
ll query(int d)
{
	ll sm=0;
	for(int i=d;i>0;i-=lowbit(i))
		sm+=tree[i];
	return sm;
}
void update(int d,int n)
{
	for(int i=d;i<=n;i+=lowbit(i))
		tree[i]-=1;
}
int main()
{
	int n,dex;
	ll res;
	while(scanf("%d",&n),n){
		init(n);
		res=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&dot[i].val);
			dot[i].d=i;
		}
		sort(dot+1,dot+n+1);
		for(int i=1;i<=n;i++){
			dex=dot[i].d;
			res+=query(dex-1);
			update(dex,n);
		}
		printf("%lld\n",res);
	}
 } 
