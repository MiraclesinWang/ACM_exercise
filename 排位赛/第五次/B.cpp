#include<cstdio>
#include<iostream> 
#include<map>
#include<cstring>
using namespace std;
const double c=12.01;
const double o=16.00;
const double h=1.008;
const double n=14.01;
map<char,double> mp;
bool isd(char c){
	if(c>='0' && c<='9') return true;
	else return false;
}
char tmp[85];
int main()
{
	mp['C']=c,mp['O']=o,mp['H']=h,mp['N']=n;
	int T,l,num,i;
	double res,n;
	char el;
	scanf("%d\n",&T);
	for(int cn=1;cn<=T;cn++){
		cin.getline(tmp,85);
		l=strlen(tmp),res=0;
		if(tmp[l-1]<'0' || tmp[l-1]>'9') res+=mp[tmp[l-1]];
		i=0;
		while(i<l-1){
			el=tmp[i];
			if(isd(tmp[i+1])){
				num=tmp[i+1]-'0';
				i+=2;
				while(isd(tmp[i])) num*=10,num+=tmp[i++]-'0';
				res+=double(num)*mp[el]; 
			}
			else res+=mp[el],i++;
		}
		printf("%.3f\n",res);
	}
 } 
