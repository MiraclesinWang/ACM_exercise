#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn=1e5 + 5;
const int mod=998244353;

char a[maxn][13];
ll pow(ll a,ll b)
{
	ll res=1;
	while(b>0){
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;
		b=b>>1;
	}
	return res;
}
ll cacu(int x,int y)
{
	ll res=pow(10,y);
	res=(res*x)%mod;
	return res;
}
int main()
{
	int n;
	ll res=0;
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		scanf("%s",a[i]+1);
	int l=strlen(a[0]+1);
	for(int i=0;i<n;i++){
		for(int j=1;j<=l;j++){
			res += cacu(a[i][j]-'0',2*l-2*j+1);
			res %= mod;
			res += cacu(a[i][j]-'0',2*l-2*j);
			res %= mod;
		}
	}
	res=(res*n)%mod;
	printf("%lld\n",res);
}

