#include<cstdio>
using namespace std;
int star[5010]={0};
int con[5010]={0};
void connect(int star[5010],int node,int tree,int &count)
{
	con[tree]++,con[node]++;
	int temp=tree,cpy,count1=0,count2=0;
	while(star[tree]!=tree) tree=star[tree],count1++;
	//while(temp!=tree) cpy=star[temp],star[temp]=tree,temp=cpy;
	//while(star[node]!=node) temp=star[node],star[node]=tree,node=temp;
	while(star[node]!=node) node=star[node],count2++;
	if(node!=tree) count--;
	if(count1>count2) star[tree]=node;
	else star[node]=tree;
	//star[node]=star[tree];
}

int main()
{
	int n,m,a,b,q,count,f,h;
	char c;
	for(int i=1;i<=5000;i++) star[i]=i;
	scanf("%d %d",&n,&m);
	count=n;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		if(star[a]==a && star[b]==b) star[a]=b,count--,con[a]++,con[b]++;
		else if(star[a]==a &&star[b]!=b) connect(star,a,b,count);
		else if(star[a]!=a &&star[b]==b) connect(star,b,a,count);
		else connect(star,a,b,count);
		//printf("%d\n",count);
	}
	for(int i=1;i<=n;i++) printf("%d ",con[i]);
	printf("\n");
	scanf("%d",&q);
	if(q<=0) return 0;
	for(int i=0;i<q;i++){
		scanf("\n%c",&c);
		if(c=='Q') printf("%d\n",count);
		else if(c=='D'){
			scanf("%d %d",&a,&b);
			con[a]--,con[b]--;
			if(con[a]==1|| con[b]==1){
				count++;
				if(con[a]==1) star[a]=a;
				else star[b]=b;
			}		
		}
		else{
			scanf("%d %d",&a,&b);
			connect(star,a,b,count);
		}
	}
}
/*7 10
1 2
2 3
3 4
4 1
1 3
2 4
5 6
6 7
7 5
2 5
10
Q
D 2 5
Q
D 5 6
D 5 7
Q
A 2 5
Q
A 5 6
Q*/
