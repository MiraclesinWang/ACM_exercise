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
	ll a,b,n,x,tmp,res,cpy1,cpy2;
	cin>>a>>b>>n>>x;
	if(a==1){
		res=x%mod;
		n%=mod;
		res=(res+b*n)%mod;
		cout<<res<<endl;
	}
	else{
		if(n%2==0){
			tmp=cal(a,n);cpy1=cal(a,n/2);
			res=(tmp*x)%mod;
			tmp=(cpy1*cpy1-1)/(a-1);
			tmp%=mod;
			res=(res+tmp*b)%mod;		
		}
		else{
			tmp=cal(a,n);cpy1=cal(a,n/2);cpy2=cal(a,n/2+1);
			res=(tmp*x)%mod;
			tmp=(cpy1*cpy2-1)/(a-1);
			tmp%=mod;
			res=(res+tmp*b)%mod;			
		}
		cout<<res<<endl;		
	}
	return 0;
}
