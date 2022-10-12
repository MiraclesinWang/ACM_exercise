#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int lmt = 0x3f3f3f3f;
string rply="There are no adjacent primes.";
bool prime(int n)
{
	int lmt=sqrt(n);
	for(int i=2;i<=lmt;i++)
		if(n%i==0) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int pre,post,l,u,maxn,minn,tmp;
	int al,ar,bl,br;
	while(cin>>l>>u){
		pre=0,post=0,maxn=0,minn=lmt;
		for(int i=l;i<=u;i++){
			if(prime(i)){
				if(post){
					pre=post,post=i;
					tmp=post-pre;
					if(minn>tmp) minn=tmp,al=pre,ar=post;
					if(maxn<tmp) maxn=tmp,bl=pre,br=post;
				}
				else if(pre){
					post=i;
					minn=maxn=post-i;
					al=bl=pre,ar=br=post;
				}
				else pre=i;
			}
		}
		if(!post) cout<<rply<<endl;
		else printf("%d,%d are closest, %d,%d are most distant.\n",al,ar,bl,br);
	}
}
