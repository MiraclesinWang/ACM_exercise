#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void cmp(char s1[10000+5],char s2[10000+5])
{
	int cnt1,cnt2,dex1,dex2;
	cnt1=cnt2=dex1=dex2=0;
	for(int i=0;i<strlen(s1);i++)
		if(s1[i]=='c') cnt1++;
	for(int i=0;i<strlen(s2);i++)
		if(s2[i]=='c') cnt2++;
	if(cnt1!=cnt2) {printf("No\n");return;}
	cnt1=cnt2=0;
	while(dex1<strlen(s1)){
		if(s1[dex1]=='c'){
			while(dex2<strlen(s2)){
				if(s2[dex2]!='c') dex2++,cnt2++;
				else{
					if((cnt1-cnt2)%2!=0) {printf("No\n");return ;}
					cnt1=cnt2=0;
					dex2++;
				}
			}
			dex1++;
		}
		else cnt1++,dex1++;
	}
	cnt2=strlen(s2)-dex2;
	if((cnt1-cnt2)%2==0) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	char s1[10005],s2[10000+5];
	while(cin.getline(s1,1e4+5)){
		cin.getline(s2,1e4+5);
		cmp(s1,s2);
	}
}
