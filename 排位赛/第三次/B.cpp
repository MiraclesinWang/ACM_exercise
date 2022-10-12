#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int two[10010],zero[10010],one[10010];
char num[10010];
int main()
{
	int len_0=0,len_1=0,len_2=0;
	cin.getline(num,10000);
	int len=strlen(num);
	for(int i=0;i<len;i++){
		if(num[i]=='0') zero[len_0++]=i;
		else if(num[i]=='1') one[len_1++]=i;
		else two[len_2++]=i;
	}
	int dex=len-1;
	for(int i=len-1;i>=two[0];i--) if(num[i]!='1') num[dex--]=num[i];
	for(int i=0;i<len_1;i++) num[dex]='1',dex--;
	for(;dex>=0;dex--) num[dex]='0';
	cout<<num<<endl;
}
