#include<cstdio>
using namespace std;
#define maxn 50000
int fa[maxn+10],son[maxn+10],same[maxn+10]; //��������ֱ��Ǹ��ס����ӡ�����Ԫ 
/*˼·������ÿһ����ͨ�飬��3������Ԫ��¼�����㼶�Ķ���������в������ô���Ԫ�����ж���ϲ�*/ 
bool equal(int a,int b)
{
	int cpy1=a,cpy2=b,temp;
	while(same[a]!=a) a=same[a];      //�Ҵ���Ԫ 
	while(same[b]!=b) b=same[b];
	if(a==b){       //��ȷ 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp; //·��ѹ�� 
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;
		return true;	
	}
	else if(fa[a]==b || son[a]==b) return false;      //��ͻ 
	else{           //�����޹أ���ʼ�ϲ� 
		same[b]=a;           //�ϲ�aͬ�� 
		if(fa[b]!=b && fa[a]!=a) same[fa[b]]=fa[a];       //�ϲ�a��һ�� 
		else if(fa[b]!=b) fa[a]=fa[b],son[fa[a]]=a;
		if(son[b]!=b && son[a]!=a) same[son[b]]=son[a];        //�ϲ�a��һ�� 
		else if(son[b]!=b) son[a]=son[b],fa[son[a]]=a;
		if(son[a]!=a && fa[a]!=a) fa[fa[a]]=son[a],son[son[a]]=fa[a];		
		while(same[cpy2]!=a) temp=same[cpy2],same[cpy2]=a,cpy2=temp; //·��ѹ�� 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp;
		return true;
	}
}

bool eat(int a,int b)          //a��b
{
	int cpy1=a,cpy2=b,temp;
	while(same[a]!=a) a=same[a];     //�Ҵ���Ԫ 
	while(same[b]!=b) b=same[b];
	if(a==b || fa[a]==b) return false;      //��ͻ 
	else if(son[a]==b){         //��ȷ 
		while(same[cpy1]!=a) temp=same[cpy1],same[cpy1]=a,cpy1=temp;      //·��ѹ�� 
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;
		return true;
	}
	else{           //����ͨ 
		if(fa[b]!=b) same[fa[b]]=a;       //�ϲ�aͬ�� 
		if(son[a]==a) son[a]=b,fa[son[a]]=a;          //�ϲ�a��һ�� 
		else same[b]=son[a];
		if(fa[a]==a && son[b]!=b) fa[a]=son[b],son[fa[a]]=a;        //�ϲ�a��һ�� 
		else if(son[b]!=b) same[son[b]]=fa[a];
		if(son[a]!=a && fa[a]!=a) fa[fa[a]]=son[a],son[son[a]]=fa[a];
		//fa[fa[a]]=son[a],son[son[a]]=fa[a];
		while(same[cpy2]!=b) temp=same[cpy2],same[cpy2]=b,cpy2=temp;   //·��ѹ�� 
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
		if(t==1) {if(!equal(a,b)) res++;}
		else {if(!eat(a,b)) res++;}
	}
	printf("%d\n",res);
}
