#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int mod=998244353;

char a[maxn][13];
int len[maxn];
int lsum[maxn];

ll pow(ll a,ll b)
{
	ll res=1;
	while(b>0){
		if(b&1)res=(res*a)%mod;
		a=(a*a)%mod;
		b >>= 1;
	}
	return res;
}

ll cacu(int x,int y)
{
	ll res=pow(10,y);
	res=(res*x)%mod;
	return res;
}

int main(){
	int n;
	ll res=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		scanf("%s",a[i]+1);
	for(int i=0;i<n;i++)
		len[strlen(a[i]+1)]++;
	lsum[0]=0;
	for(int i=1;i<=n;i++)
		lsum[i]=lsum[i-1]+len[i];
		
	for(int i=0;i<n;i++){
		for(int j=1;j<=strlen(a[i]+1);j++){
			int t=strlen(a[i]+1) - j + 1;
			res += (n-lsum[t-1])*cacu(a[i][j]-'0',2*t-1);
			res %= mod;
			for(int tmp=1;tmp<t;tmp++){
				res += len[tmp]*cacu(a[i][j]-'0',t+tmp-1);
				res %= mod;
			}
			res += (n-lsum[t-2])*cacu(a[i][j]-'0',2*t-2);
			res %= mod;
			for(int k=1;k<t-1;k++){
				res += len[k]*cacu(a[i][j]-'0',t+k-1);
				res %= mod;
			}
		}
	}
	printf("%lld\n",res);
}

