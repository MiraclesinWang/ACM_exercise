#include<iostream>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll cal(ll a,ll n)
{
	ll tmp=1;
	while(n){
		if(n&1) tmp=(tmp*a)%mod;
		a=(a*a)%mod,n>>=1;
	}
	return tmp;	
}
int main()
{
	ll a,b,n,x,tmp=1,res,cpy;
	cin>>a>>b>>n>>x;
	if(a==1){
		res=x%mod;
		n%=mod;
		res=(res+b*n)%mod;
		cout<<res<<endl;
	}
	else{
		cpy=cal(a-1,mod-2);
		tmp=cal(a,n)*x;
		res=(cal(a,n)*x)%mod;
		res=tmp*x%mod;
		res+=((tmp-1)*cpy%mod)*(b%mod);
		res%=mod;
		cout<<res<<endl;		
	}
	return 0;
}
