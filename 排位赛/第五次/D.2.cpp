#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000+5
struct Node{
	int dex,val;
	bool operator <(const Node &n) {return val<n.val;}
};
Node cnt[maxn]; 
int main()
{
	bool can=true;
	ios::sync_with_stdio(false);
	int k,m,tmp;
	cin>>k>>m;
	for(int i=1;i<=k;i++)
		cnt[i].dex=i,cnt[i].val=0;
	for(int i=1;i<=m;i++)
		cin>>tmp,cnt[tmp].val+=1;
	sort(cnt+1,cnt+k+1);
	if(cnt[k].val-cnt[1].val>2) {printf("*\n");return 0;}
	else if(cnt[k].val-cnt[1].val==2){
		tmp=(cnt[1].val+cnt[k].val)/2;
		if(cnt[k-1].val!=tmp || cnt[2].val!=tmp) {printf("*\n");return 0;}
		else printf("-%d +%d\n",cnt[k].dex,cnt[1].dex);
	}
	else{
		if(cnt[2].val!=cnt[k].val && cnt[2].val!=cnt[1].val) {printf("*\n");return 0;}
		else if(cnt[2].val!=cnt[k-1].val) {printf("*\n");return 0;}
		else{
			if(cnt[2].val!=cnt[1].val) printf("+%d\n",cnt[1].dex);
			else printf("-%d\n",cnt[k].dex);
		}
	}
}
