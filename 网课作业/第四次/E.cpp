#include<cstdio>
#include<iostream>
#include<iostream>
using namespace std;
#define maxn 1010
bool reachable[maxn][maxn];
bool repair[maxn];
int fa[maxn];
int x[maxn],y[maxn];
int dis(int i,int j) {return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);}
int frt(int i) {return (fa[i]==i?i:fa[i]=frt(fa[i]));}
void connect(int p,int n)
{
	for(int i=1;i<=n;i++){
		if(reachable[p][i] && repair[i]){
			if(fa[p]==p) fa[p]=frt(i);
			else fa[frt(i)]=fa[frt(p)];
		}
	}
}
int main()
{
	int N,d,p,q;
	char s[100],c;
	scanf("%d %d",&N,&d);
	d*=d;
	for(int i=1;i<=N;i++) scanf("%d%d\n",&x[i],&y[i]);
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			reachable[i][j]=reachable[j][i]=(dis(i,j)<=d);
	for(int i=1;i<=N;i++) fa[i]=i,repair[i]=false;
	while(cin.getline(s,100)){
		if(s[0]=='O'){
			sscanf(s,"%c %d",&c,&p);
			repair[p]=true;
			connect(p,N);
		}
		else{
			sscanf(s,"%c %d%d",&c,&p,&q);
			printf(frt(p)==frt(q)?"SUCCESS\n":"FAIL\n");
		}
	}
}
