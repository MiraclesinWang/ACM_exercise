#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 1e5;
int tablet[maxn][100];
int prime[10000];
bool pre[maxn+5];
int main()
{
	memset(pre,true,sizeof(pre));
	int cnt=1,tmp;
	for(int i=2;i<=maxn;i++){
		if(pre[i]){
			tmp=2*i;
			while(tmp<=maxn) pre[tmp]=false,tmp+=i; 
		}
	}
	for(int i=2;i<=maxn;i++)
		if(pre[i]) prime[cnt++]=i;
	for(int i=1;i<cnt;i++) printf("%d ",prime[i]);
}
