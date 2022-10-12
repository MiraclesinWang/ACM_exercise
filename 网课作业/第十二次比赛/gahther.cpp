#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const ll mod=10000007;
struct arr{
	ll lu,ld,ru,rd;
	arr operator *(const arr &a){
		arr res;
		res.lu=(lu*a.lu+ru*a.ld)%mod;
		res.ld=(ld*a.lu+rd*a.ld)%mod;
		res.ru=(lu*a.ru+ru*a.rd)%mod;
		res.rd=(ld*a.ru+rd*a.rd)%mod;
		return res;
	}
	arr operator *(const ll a){
		arr res;
		res.lu=(a*lu)%mod;
		res.ld=(a*ld)%mod;
		res.rd=(a*rd)%mod;
		res.ru=(a*ru)%mod;
		return res;
	}
	arr operator +(const arr &a){
		arr res;
		res.lu=(lu+a.lu)%mod;
		res.ld=(ld+a.ld)%mod;
		res.rd=(rd+a.rd)%mod;
		res.ru=(ru+a.ru)%mod;
		return res;
	}
};
int num[maxn];
int main()
{
	int n;
	ll k,a,b,sm,ans;
	arr tmp,now;
	tmp.lu=tmp.ru=tmp.rd=1,tmp.ld=0;
	now.lu=1,now.rd=1,now.ld=now.ru=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%lld",&num[i]),sm=(sm+num[i])%mod;
	sort(num,num+n);
	a=num[n-1],b=num[n-2];
	if(a<=0 && b<=0) cout<<((a+b)*k+sm)%mod<<endl;
	else if(a>=0 && b>=0){
		while(k){
			if(k&1) now=now*tmp;
			tmp=tmp*tmp;
			k>>=1;
		}
		tmp=now;
		ans=((tmp.lu+tmp.ru)*a+2*tmp.rd*b)%mod;
		ans=(ans+sm)%mod;
		printf("%lld\n",ans);
	}
	else{
		if(a*k+b<=0){
			ll k2=(k*(k+1)/2)%mod;
			cout<<(b*k+k2*a+sm)%mod;
		}
		else{
			ll t=(-b)/a;
			t+=1;
			ll t2=(t*(t+1)/2)%mod;
			ans=(b*t+t2*a+sm)%mod;
			k-=t;
			ll c=a*t+b;
			if(c>a) swap(a,c);
			while(k){
				if(k&1) now=now*tmp;
				tmp=tmp*tmp;
				k>>=1;
			}
			tmp=now;
			ans=(ans+(tmp.lu+tmp.ru)*a+2*tmp.rd*c)%mod;
			printf("%lld\n",ans);
		}
	}
}
