#include<cstdio>
using namespace std;
const int maxn= 3e5+3;
char s[maxn];
int main()
{
	int l,le=0,r=0,u=0;
	scanf("%d\n",&l);
	scanf("%s",s);
	for(int i=0;i<l;i++){
		if(s[i]=='(') le++;
		else if(s[i]==')') r++;
		else u++;
	}
	if(r-le>u || le-r>u || l%2==1){
		printf(":(\n");
		return 0;
	}
	le=l/2-le,r=l/2-r,u=0;
	for(int i=0;i<l-1;i++){
		if(s[i]=='(') u++; 
		else if(s[i]==')'){
			if(u==0 || u==1){
				printf(":(\n");
				return 0;
			}
			u--;
		}
		else{
			if(u==1){
				if(le<=0){
					printf(":(\n");
					return 0;
				}
				s[i]='(',u++,le--;
			}
			else{
				if(u>1 && r>0) u--,r--,s[i]=')';
				else if(le>0) u++,le--,s[i]='(';
				else{
					printf(":(\n");
					return 0;
				}
			}
		}
	}
	s[l-1]=')';
	printf("%s",s);
}
