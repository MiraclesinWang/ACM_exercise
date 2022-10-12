#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
#define maxn 1000+5
#define limit 0x3f3f3f3f
struct Node{
	int dex,value;
	bool operator <(const Node A) {return value<A.value;}
	bool operator >(const Node A) {return value>A.value;}
};
int s[maxn][maxn];
int floor[maxn][maxn];
int groud[maxn][maxn];
int s1[maxn][maxn];
int s2[maxn][maxn];
Node up[maxn],down[maxn];     //分别是单调递增，递减序列 
void init(int a,int b,int n)
{
	int head1,tail1,head2,tail2;
	Node temp;
	for(int i=1;i<=a;i++){       //行 
		temp.dex=1,temp.value=s[i][1];
		head1=1,tail1=1,head2=1,tail2=1;
		up[1]=temp,down[1]=temp;
		for(int j=2;j<=n-1;j++){
			temp.dex=j,temp.value=s[i][j];
			while(tail1>0 && up[tail1]<temp) tail1--;
			up[++tail1]=temp;
			while(tail2>0 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
		}
		//floor[i][1]=up[1].value,groud[i][1]=down[1].value;
		for(int j=n;j<=b;j++){
			temp.dex=j,temp.value=s[i][j];
			while(tail1>=head1 && up[tail1]<temp) tail1--;
			up[++tail1]=temp;
			while(up[head1].dex<j-n+1) head1++;
			while(tail2>=head2 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
			while(down[head2].dex<j-n+1) head2++;
			floor[i][j-n+1]=up[head1].value,groud[i][j-n+1]=down[head2].value;
		}
	}
}
void advance(int a,int b,int n)
{
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b-n+1;j++) s1[i][j]=floor[i][j],s2[i][j]=groud[i][j];
	int head1,tail1,head2,tail2;
	Node temp;
	for(int i=1;i<=b-n+1;i++){       //行 
		temp.dex=1,temp.value=s1[1][i];
		head1=1,tail1=1,head2=1,tail2=1;
		up[1]=temp;
		for(int j=2;j<=n-1;j++){
			temp.dex=j,temp.value=s1[j][i];
			while(tail1>0 && up[tail1]<temp) tail1--;
			up[++tail1]=temp;
		}
		//floor[i][1]=up[1].value,groud[i][1]=down[1].value;
		for(int j=n;j<=a;j++){
			temp.dex=j,temp.value=s1[j][i];
			while(tail1>=head1 && up[tail1]<temp) tail1--;
			up[++tail1]=temp;
			while(up[head1].dex<j-n+1) head1++;
			floor[j-n+1][i]=up[head1].value;
		}
		temp.dex=1,temp.value=s2[1][i];
		down[1]=temp;
		for(int j=2;j<=n-1;j++){
			temp.dex=j,temp.value=s2[j][i];
			while(tail2>0 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
		}
		for(int j=n;j<=a;j++){
			temp.dex=j,temp.value=s2[j][i];
			while(tail2>=head2 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
			while(down[head2].dex<j-n+1) head2++;
			groud[j-n+1][i]=down[head2].value;
		}
	}
}
int main()
{
	int a,b,n,res=limit;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++) scanf("%d",&s[i][j]),floor[i][j]=s[i][j],groud[i][j]=s[i][j];
	init(a,b,n),advance(a,b,n);
	for(int i=1;i<=a-n+1;i++)
		for(int j=1;j<=b-n+1;j++)
			if(res>floor[i][j]-groud[i][j]) res=floor[i][j]-groud[i][j];
	printf("%d\n",res);
}
