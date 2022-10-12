#include <cstdio>
#include <iostream>
using namespace std;

int s;

int main()
{
	int kase;
	scanf("%d",&kase);
	for(int t = 0; t < kase; t++){
		int n,k;
		scanf("%d%d",&n,&k);
		if(k%3==0){
			s=n%(k+1);
			if(s%3==0 && s!=k)printf("Bob\n");
			else printf("Alice\n");			
		}
		else{
			if(n%3!=0)printf("Alice\n");
			else printf("Bob\n");
		}
	}
}

