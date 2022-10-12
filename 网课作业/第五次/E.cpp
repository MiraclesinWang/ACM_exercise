#include<cstdio>
using namespace std;
#define maxn 1000000+5
struct Node{
	int dex,value;
	bool operator <(const Node A) {return value<A.value;}
	bool operator >(const Node A) {return value>A.value;}
};
Node num[maxn],up[maxn],down[maxn];
int main()
{
	int n,k,start=1,end=1;
	Node temp;
	scanf("%d %d",&n,&k);
	if(k>n) k=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i].value),num[i].dex=i;
	if(k==1){
		for(int i=1;i<=n;i++){
			printf("%d",num[i].value);
			printf(i==n?"\n":" ");
		}
		for(int i=1;i<=n;i++){
			printf("%d",num[i].value);
			printf(i==n?"\n":" ");
		}
		return 0;
	}
	down[1].dex=1,down[1].value=num[1].value;
	for(int i=2;i<=k-1;i++){
		temp.dex=num[i].dex,temp.value=num[i].value;
		while(end>0 && down[end]>temp) end--;
		down[++end]=temp;
	}
	for(int i=k;i<=n;i++){
		temp.dex=num[i].dex,temp.value=num[i].value;
		while(end>=start && down[end]>temp) end--;
		down[++end]=temp;
		while(down[start].dex<i-k+1) start++;
		printf("%d",down[start].value);
		printf(i==n?"\n":" ");
	}
	up[1].dex=1,up[1].value=num[1].value,start=1,end=1;
	for(int i=2;i<=k-1;i++){
		temp.dex=num[i].dex,temp.value=num[i].value;
		while(end>0 && up[end]<temp) end--;
		up[++end]=temp;
	}
	for(int i=k;i<=n;i++){
		temp.dex=num[i].dex,temp.value=num[i].value;
		while(end>=start && up[end]<temp) end--;
		up[++end]=temp;
		while(up[start].dex<i-k+1) start++;
		printf("%d",up[start].value);
		printf(i==n?"\n":" ");
	}
}
