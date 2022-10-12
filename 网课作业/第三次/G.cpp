#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
	int s[5];
	int count;
	bool operator == (const int A){
		int temp=s[0]*1000+s[1]*100+s[2]*10+s[3];
		if(temp==A) return true;
		else return false;
	}
	bool operator <=(const int a){
		int temp=s[0]*1000+s[1]*100+s[2]*10+s[3];
		if(temp<=a) return true;
		else return false;
	}
};
int prime[5000],state[5000];
int num[10010]={0};         //1表示已经不可能了 
Node a;
queue <Node> q;
bool find(int prime[5000],Node num,int start,int end,int state[5000])
{
	if(start==end){
		if(num==prime[start] && !state[start]) {state[end]=1;return true;}
		else return false;
	}
	else if(start==end-1){
		if(num==prime[start] && !state[start]) {state[start]=1;return true;}
		if(num==prime[end] && !state[end]) {state[end]=1;return true;}
		return false;
	}
	else{
		int mid=(start+end)/2;
		if(num<=prime[mid]) return find(prime,num,start,mid,state);
		else return find(prime,num,mid+1,end,state);
	}
}
void advance(queue <Node> &q,Node p,int length,int state[5000])
{
	for(int i=1;i<=9;i++){
		//Node a;
		memcpy(a.s,p.s,4*sizeof(int));
		a.count=p.count+1,a.s[0]=i;
		if(find(prime,a,0,length-1,state)) q.push(a);
		//else delete a.s;		
	}
	for(int i=1;i<=3;i++){
		for(int j=0;j<=9;j++){
			//Node a;
			memcpy(a.s,p.s,4*sizeof(int));
			a.count=p.count+1,a.s[i]=j;
			if(find(prime,a,0,length-1,state)) q.push(a);
			//else delete a.s;
		}
	}
}

int bfs(int prime[5000],int pre,int length,int target,int state[5000],queue <Node> &q)
{
	memset(state,0,sizeof(state));
	Node p;
	p.count=0;
	for(int i=3;i>=0;i--) p.s[i]=pre%10,pre/=10;
	q.push(p);
	while(!q.empty()){
		p=q.front(),q.pop();
		if(p==target) return p.count;
		advance(q,p,length,state);
	}
	return -1;
}

int main()
{
	int length=0,mut,n;
	for(int i=2;i<=9997;i++){
		if(!num[i]){
			if(i>=1000) prime[length++]=i;
			mut=i;
			while(mut<=10000) num[mut]=1,mut+=i;
		}
	}             //打表完成 
	scanf("%d",&n);
	int a,b,res;
	for(int i=0;i<n;i++){
		memset(state,0,sizeof(state));
		while(!q.empty()) q.pop();
		scanf("%d %d",&a,&b);
		res=bfs(prime,a,length,b,state,q);
		if(res!=-1) printf("%d\n",res);
		else printf("Impossible.\n");
	}
}
