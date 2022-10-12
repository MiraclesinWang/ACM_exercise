#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6+5;
char h[maxn];
int next[maxn];
int dp[maxn][0];
void getnext(int n)
{
	next[0]=-1;
    int i=0,j=-1;
    while(i<n)   
    {
        if(j==-1||h[i]==h[j]){
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int main()
{
	int n,dex;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>h[i];
		dex=n-1;
		getnext(n);
		while(next[dex]==next[dex-1]+1) dex--;
		cout<<dex<<endl;
	}
}
