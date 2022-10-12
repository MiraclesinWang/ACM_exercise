#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s1,s2,tmp;
	int cnt1,cnt2,dex1,dex2;
	while(scanf("\n")!=EOF){
		cin>>s1
		scanf("\n");
		cin>>s2;
		//scanf("\n");
		//cout<<s2;
		cnt1=cnt2=dex1=dex2=0;
		for(int i=0;i<s1.length();i++)
			if(s1[i]=='c') cnt1++;
		for(int i=0;i<s2.length();i++)
			if(s2[i]=='c') cnt2++;
		if(cnt1!=cnt2) {printf("No\n");return 0;}
		cnt1=cnt2=0;
		while(dex1<s1.length()){
			if(s1[dex1]=='c'){
				while(dex2<s2.length()){
					if(s2[dex2]!='c') dex2++,cnt2++;
					else{
						if((cnt1-cnt2)%2!=0) {printf("No\n");return 0;}
						cnt1=cnt2=0;
					}
				}
			}
			else cnt1++,dex1++;
		}
		printf("Yes\n");
	}
}
