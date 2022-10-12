#include<cstdio>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
struct uBigInt{
	static const int maxn=35;
	static const int base=1e8;
	int num[maxn],len;
	uBigInt(long long n=0) {*this=n;};
	uBigInt &operator=(long long n){
		memset(num,0,sizeof(num));
		len=0;
		do{
			num[len++]=n%base;
			n/=base;
		}while(n);
		return *this;
	}
	bool operator < (const uBigInt &oth) const{
		uBigInt res;
		if(oth.len>res.len) return true;
		else if(oth.len<res.len) return false;
		for(int i=1;i<=res.len;i++){
			if(oth.num[oth.len-i]>res.num[res.len-i]) return true;
			else if(oth.num[oth.len-i]<res.num[res.len-i]) return false;
		}
		return true;
	}
	bool operator == (const uBigInt &oth) const{
		uBigInt res;
		if(oth.len!=res.len) return false;
		for(int i=1;i<=res.len;i++){
			if(oth.num[oth.len-i]!=res.num[res.len-i]) return false;
		}
		return true;
	}
	uBigInt operator + (const uBigInt &oth) const{
		uBigInt res;
		res.len=0;
		long long x,g=0;
		for(int i=0;g || i<max(len,oth.len);++i){
			x=g;
			if(i<len) x+=num[i];
			if(i<oth.len) x+=oth.num[i];
			res.num[res.len++]=x%base;
			g=x/base;
		}
		while(!res.num[len-1] && res.len>1) --res.len;
		return res;
	}
	uBigInt operator * (const uBigInt &oth) const{
		long long buf[maxn];
		memset(buf,0,sizeof(buf));
		for(int i=0;i<len;++i)
			for(int j=0;j<oth.len;++j) buf[i+j]+=(long long int)num[i]*(long long int)oth.num[j];
		uBigInt res;
		for(res.len=len+oth.len;!buf[res.len] && res.len>=1;--res.len);
		int l=res.len+1;
		long long x,g=0;
		res.len=0;
		for(int i=0;i<l;++i){
			x=g+buf[i];
			res.num[res.len++]=x%base;
			g=x/base;
		}
		if(g>0) res.num[res.len++]=g;
		return res;
	}
	friend void print(const uBigInt a){
		printf("%d",a.num[a.len-1]);
		for(int i=a.len-2;i>=0;--i) printf("%08d",a.num[i]);
		printf("\n");
	}
};
clock_t start=clock(),end;
uBigInt dp[100+2][1002];
bool searched[100+2][1002];
uBigInt one=1,zero=0;
int main()
{
	int n,k,t;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) dp[i][j]=0,searched[i][j]=false;
	for(int i=1;i<=k;i++){
		t=i;
		while(t<=n) dp[i][t]=1,t+=i;
	}
	searched[k][n]=true;
	t=n;
	while(t>0) searched[k-1][t]=true,t-=k;
	for(int i=k-1;i>1;i--){
		for(int j=1;j<=n;j++){
			t=j;
			while(t>0) searched[i-1][t]=true,t-=i;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(!searched[i][j]) continue;
			t=j;
			while(t>0) dp[i][j]=dp[i][j]+dp[i-1][t],t-=i;
		}
	}
	end=clock();
	double tm=(double)(end-start)/CLOCKS_PER_SEC;
	print(dp[k][n]);
	printf("%f\n",tm);
}
