#include<cstdio>
using namespace std;
#define maxn 50000
int fa[maxn+10],son[maxn+10],same[maxn+10]; //三个数组分别是父亲、儿子、代表元 
/*思路：对于每一个连通块，用3个代表元记录三个层级的动物，对于所有操作，用代表元进行判断与合并*/ 
bool equal(int a,int b)
{
	int cpy1=a,cpy2=b,temp;
	while(same[a]!=a) a=same[a];      //找代表元 
	while(same[b]!=b) b=same[b];
	if(a==b){       //正确 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp; //路径压缩 
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;
		return true;	
	}
	else if(fa[a]==b || son[a]==b) return false;      //冲突 
	else{           //互相无关，开始合并 
		same[b]=a;
		if(fa[b]!=b) same[fa[b]]=fa[a];
		if(son[b]!=b) same[son[b]]=son[a];
		while(same[cpy2]!=a) temp=same[cpy2],same[cpy2]=a,cpy2=temp; //路径压缩 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp;
		return true;
	}
}

bool eat(int a,int b)          //a吃b
{
	int cpy1=a,cpy2=b,temp;
	while(same[a]!=a) a=same[a];     //找代表元 
	while(same[b]!=b) b=same[b];
	if(a==b || fa[a]==b) return false;      //冲突 
	else if(son[a]==b){         //正确 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp;      //路径压缩 
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;
		return true;
	}
	else{           //不连通 
		if(fa[b]!=b) same[fa[b]]=a;       //合并a同级 
		if(son[a]==a) son[a]=b,fa[b]=a;          //合并a下一级 
		else same[son[a]]=b,son[a]=b,fa[b]=a;
		if(fa[a]==a && son[b]!=b) fa[a]=son[b],son[fa[a]]=a;        //合并a上一级 
		else if(son[b]!=b) same[fa[a]]=son[b],fa[a]=son[b],son[fa[a]]=a;
		if(fa[fa[a]]!=a) fa[fa[a]]=son[a];
		if(son[son[a]]!=a) son[son[a]]=fa[a];
		//fa[fa[a]]=son[a],son[son[a]]=fa[a];
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;   //路径压缩 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp;
		return true;
	}
}

int main()
{
	int N,K,res=0,a,b,t;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) fa[i]=i,son[i]=i,same[i]=i;
	for(int i=0;i<K;i++){
		scanf("%d%d%d",&t,&a,&b);
		if(a>N || b>N) {res++;continue;}
		if(t==2 && a==b) {res++;continue;}
		if(t==1){
			if(same[a]==a && same[b]==b) same[a]=b;
			else if(!equal(a,b)) res++;
		}
		else {if(!eat(a,b)) res++;}
	}
	printf("%d\n",res);
}
