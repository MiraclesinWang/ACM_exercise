#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int>,less<int> > pre;
priority_queue<int,vector<int>,greater<int> > back; 
int lst[5];
int main()
{
	int n,NO,len,dex,a,b,now;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		while(!pre.empty()) pre.pop();
		while(!back.empty()) back.pop();
		scanf("%d %d",&NO,&len);
		printf("%d %d\n",NO,len/2+1);
		if(len==1){
			scanf("%d",&a);
			printf("%d\n",a);			
		}
		else{
			scanf("%d%d%d",&lst[0],&lst[1],&lst[2]);
			printf("%d ",lst[0]);
			sort(lst,lst+3);
			now=lst[1],pre.push(lst[0]),back.push(lst[2]);
			printf("%d ",lst[1]);
			for(int j=2;j<=len/2;j++){
				scanf("%d%d",&a,&b);
				if(a>b) swap(a,b);
				if(a>now) pre.push(now),back.push(a),back.push(b),now=back.top(),back.pop();
				else if(b<now) back.push(now),pre.push(a),pre.push(b),now=pre.top(),pre.pop();
				else pre.push(a),back.push(b);
				//printf("%d %d %d\n",pre.top(),now,back.top());
				printf("%d",now);
				if(j<len/2) printf(j%10==9?"\n":" ");
			}
			printf("\n");			
		}

	}
}
 
