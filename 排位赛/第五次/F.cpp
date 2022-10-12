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
	ll a,b,n,x,tmp,res,cpy;
	cin>>a>>b>>n>>x;
	if(a==1){
		res=x%mod;
		n%=mod;
		res=(res+b*n)%mod;
		cout<<res<<endl;
	}
	else{
		tmp=cal(a,n);cpy=cal(a,n-1);
		res=(tmp*x)%mod;
		tmp=(cpy*a-1)/(a-1);
		tmp%=mod;
		res=(res+tmp*b)%mod;
		cout<<res<<endl;		
	}
	return 0;
}
