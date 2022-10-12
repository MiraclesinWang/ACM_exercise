#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define maxn 1000+5
int rope[maxn];
int main()
{
	int T,n,c,res;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&rope[i]);
		sort(rope+1,rope+n+1,greater<int>());
		c=0,res=0;
		while(++c<=n)
			res=max(res,rope[c]*(c));
		printf("%d\n",res);
	}
}
