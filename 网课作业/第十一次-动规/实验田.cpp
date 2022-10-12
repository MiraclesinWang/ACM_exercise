#include<iostream>
using namespace std;
int main()
{
	int res=0;
	int n,a,b;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a>>b,res+=a+b;
	cout<<res<<endl;
}
