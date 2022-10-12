#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
const int maxn=2e5+5;
ll num[maxn];
int main()
{
	int n;
	ll sm;
	ios::sync_with_stdio(false);
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=n;i++)
			scanf("%lld",&num[i]);
		sm=0;
		for(int i=n;i>=0;i--){
			sm+=num[i];
			if(sm>=(ll)i) {cout<<i<<endl;break;}
		}
	}
 } 
