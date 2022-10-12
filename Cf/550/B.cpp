#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
int odd[maxn],even[maxn];
int main()
{
	int n,codd=0,ceven=0,temp,res=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(temp%2==1) odd[codd++]=temp;
		else even[ceven++]=temp;
	}
	sort(even,even+ceven,greater<int>());
	sort(odd,odd+codd,greater<int>());
	if(ceven==codd || ceven-codd==1 || codd-ceven==1) printf("0\n");
	else if(ceven>codd){
		for(int i=codd+1;i<ceven;i++) res+=even[i];
		printf("%d\n",res);
	}
	else{
		for(int i=ceven+1;i<codd;i++) res+=odd[i];
		printf("%d\n",res);
	}
 } 
