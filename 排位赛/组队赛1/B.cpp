#include <cstdio>
#include <cmath>
#include<algorithm>
int solve(int n,int a){
	if (a==0) return n>>1;
	else if (a>1) return std::min(n,a);
	else return floor((sqrt(1+8*n)-1)/2);
}
int main(){
	int n,a;
	while (~scanf("%d%d",&n,&a)){
		printf("%d\n",solve(n,a));
	}
	return 0;
}
