#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
#define mod 100003
int main()
{
	ll m,n,cpy;
	scanf("%lld%lld",&m,&n);
	ll temp=m,maxn=1,minn=m;
	cpy=n-1;
	while(n){
		if(n&1) maxn=(temp*maxn)%mod;
		temp=(temp*temp)%mod,n>>=1;
	}
	temp=m-1;
	while(cpy){
		if(cpy&1) minn=(temp*minn)%mod;
		temp=(temp*temp)%mod,cpy>>=1;
	}
	maxn-=minn;
	if(maxn<0) maxn+=mod;
	printf("%d\n",maxn);
}
