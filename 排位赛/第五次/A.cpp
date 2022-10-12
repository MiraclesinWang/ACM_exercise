#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,d,e,f,res=0;
	cin>>a>>b>>c;
	cin>>d>>e>>f;
	if(a<d) res+=d-a;
	if(b<e) res+=e-b;
	if(c<f) res+=f-c;
	cout<<res<<endl;
}
