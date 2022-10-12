#include<cstdio>
#include<map>
#include<iostream>
#include<queue> 
#include<cstring>
using namespace std;
#define maxn 1005
#define limit 200000+5     //队列数组的最大值 
map <int,int> mp;
char command[10];
int dex[maxn];         //记录每个group的位置 
int q[limit];      //实际队列,只记录每组的编号 
queue <int> group[maxn];         //各组的队列 
void init(int n)
{
	for(int i=1;i<=n;i++) while(!group[i].empty()) group[i].pop();
	memset(q,0,sizeof(q));
	memset(dex,-1,sizeof(dex));
}
int main()
{
	int t,c,temp,g,l=0,r=0,d=1;
	while(scanf("%d",&t),t){
		init(t),l=0,r=0;
		printf("Scenario #%d\n",d++);
		for(int i=1;i<=t;i++){
			scanf("%d",&c);
			for(int j=0;j<c;j++) scanf("%d",&temp),mp[temp]=i;    //记录group编号 
		}
		while(scanf("\n%s",&command),command[0]!='S'){
			if(command[0]=='E'){
				scanf("%d",&temp);
				g=mp[temp];
				group[g].push(temp);
				if(dex[g]<0) dex[g]=r,q[r++]=g;
				//printf("%d %d\n",g,r);
			}
			else{
				temp=group[q[l]].front();
				printf("%d\n",temp);
				group[q[l]].pop();
				if(group[q[l]].empty()) dex[q[l]]=-1,l++;
			}
		}
		printf("\n");
	}
 } 

