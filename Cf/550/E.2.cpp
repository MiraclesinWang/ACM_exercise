#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int ans[maxn];
char s1[maxn],s2[maxn],res[maxn];
int main()
{
	int n,flag=0,temp;
	scanf("%d",&n);
	scanf("\n%s\n%s",&s1,&s2);
	for(int i=n-1;i>=0;i--){
		ans[i]=(s1[i]-'a')+(s2[i]-'a')+flag;
		if(ans[i]>25) flag=1,ans[i]-=26;
		else flag=0;
	}
	for(int i=0;i<n;i++){
		ans[i]+=26*flag;
		if(ans[i]%2==1) flag=1;
		else flag=0;
		ans[i]/=2;
	}
	for(int i=0;i<n;i++) res[i]=ans[i]+'a';
	cout<<res<<endl;
}
