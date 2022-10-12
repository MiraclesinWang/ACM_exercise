#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long
#define maxn 3000 + 5
ll h[maxn][maxn];
struct Node{
	int dex;
	ll value;
	bool operator <(const Node A) {return value<A.value;}
	bool operator >(const Node A) {return value>A.value;}
} down[maxn];
Node up[maxn];
ll groud[maxn][maxn];

void init(int a,int b,int n)
{
	int head1,tail1,head2,tail2;
	Node temp;
	for(int i=1;i<=a;i++){       //ÐÐ 
		temp.dex=1,temp.value=h[i][1];
		head1=1,tail1=1,head2=1,tail2=1;
		down[1]=temp;
		for(int j=2;j<=n-1;j++){
			temp.dex=j,temp.value=h[i][j];
			while(tail2>0 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
		}
		//floor[i][1]=up[1].value,groud[i][1]=down[1].value;
		for(int j=n;j<=b;j++){
			temp.dex=j,temp.value=h[i][j];
			while(tail2>=head2 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
			while(down[head2].dex<j-n+1) head2++;
			groud[i][j-n+1]=down[head2].value;
		}
	}
}
void advance(int a,int b,int n)
{
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b-n+1;j++) h[i][j]=groud[i][j];
	int head1,tail1,head2,tail2;
	Node temp;
	for(int i=1;i<=b-n+1;i++){       //ÐÐ 
		head1=1,tail1=1,head2=1,tail2=1;
		//floor[i][1]=up[1].value,groud[i][1]=down[1].value;
		temp.dex=1,temp.value=h[1][i];
		down[1]=temp;
		for(int j=2;j<=n-1;j++){
			temp.dex=j,temp.value=h[j][i];
			while(tail2>0 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
		}
		for(int j=n;j<=a;j++){
			temp.dex=j,temp.value=h[j][i];
			while(tail2>=head2 && down[tail2]>temp) tail2--;
			down[++tail2]=temp;
			while(down[head2].dex<j-n+1) head2++;
			groud[j-n+1][i]=down[head2].value;
		}
	}
}

int main()
{
	int n, m, a, b;
	ll g, x, y, z;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	cin >> g >> x >> y >>z;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			h[i][j] = g;
			g = (x*g + y) % z;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%lld ", h[i][j]);
		printf("\n");
	}	
	init(n, m, b), advance(n, m, a);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%lld ", groud[i][j]);
		printf("\n");
	}
}
