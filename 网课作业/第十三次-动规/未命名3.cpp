#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll m;
ll qp(ll n,ll k){
    ll res=1;
    while (k){
        if (k&1) res=(res*n)%m;
        n=n*n;
        k>>=1;
    }
    return res;
}
int main()
{
    ll n, a;
    ll res;
    while(~scanf("%lld%lld", &n, &a)){
        m=(1<<n);
        if(a&1)
            res=1;
        else{
            res=0;
            for(int i=1;i<=n;i++)	
				if(qp(i,a)==qp(a,i))res++;
            if(a > n) res += pow(2,n-1)-n/2;
            else{
              	int num_2=ceil((double)n/a);
				int te=n/pow(2,num_2);
				res+=pow(2,n-num_2)-te;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
