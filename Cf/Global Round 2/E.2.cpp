#include<cstdio>
using namespace std;
#define maxn 300000+5
int s[maxn],two[maxn],one[maxn];
int main()
{
	int n;
	long long res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	int l=1,r=n;
	while(r>l){
		if(s[r]==1) {r--;continue;}
		if(s[r]%2==1) res++,s[r]-=(long long)3;
		while(s[r]>=2){
			if(s[l]>0){
				res++,s[r]-=(long long)2,s[l]-=(long long)1;				
			}
			else{
				l++;
				if(l==r) res+=(s[r]/(long long)3);break;
			}
		}
		r--;
	}
	printf("%lld\n",res);
}
