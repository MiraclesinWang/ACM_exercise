#include<cstdio>
#include<iostream>
using namespace std;
char a[10010],b[10010];
long long int C(int a,int b)
{
	if(a<0 || b<0) return 0;
	if(a>b) return 0;
	if(a==0) return 1;
	long long int res=1;
	int temp=b-a+1;
	while(temp<=b) res*=(long long)temp,temp++;
	temp=2;
	while(temp<=a) res/=(long long)temp,temp++;
	return res;
}
int main()
{
	int n,a_count=0,b_count=0,left;
	long long int res=0;
	scanf("%d",&n);
	scanf("\n");
	cin.getline(a,10000);
	cin.getline(b,10000);
	for(int i=0;i<n;i++){
		if(a[i]=='0') a_count+=1;
		if(b[i]=='0') b_count+=1;
	}
	left=n-b_count;     //b中1的个数 
	printf("%d %d\n",a_count,b_count);
	for(int i=a_count-n+b_count;i<=a_count;i++)
		printf("C%d %d=%d\n",i,b_count,C(i,b_count)),res+=C(i,b_count);
	printf("%lld\n",res-1);
}
