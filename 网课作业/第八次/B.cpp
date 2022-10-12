#include<iostream>
#include<algorithm>
using namespace std;
int stn[12];
int main()
{
	ios::sync_with_stdio(false);
	int n,sm;
	while(cin>>n,n){
		for(int i=1;i<=n;i++) cin>>stn[i];
		sm=0;
		sort(stn+1,stn+n+1); 
		for(int i=1;i<=n;i++) sm+=stn[i];
		if(n==2){
			if(stn[2]==stn[1]) cout<<"0"<<endl;
			else cout<<"1"<<endl;
		}
		else if(n%2) cout<<"1"<<endl;
		else{
			if(sm==n) cout<<"0"<<endl;
			else cout<<"1"<<endl;
		}
	}
} 
