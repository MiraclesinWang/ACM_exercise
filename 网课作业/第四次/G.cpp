#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long int
#define maxn 150000+5
struct build{
	ll cost,ddln;
	ll strt;
	//bool operator < (const build b) {return cost<b.cost;}
} s[maxn];
struct cmp{
    bool operator ()(const build &a, const build &b)
    {
        return a.cost<b.cost;// 按照value从小到大排列
    }
};
priority_queue <build,vector<build>,cmp> res;
bool compare(build a,build b)
{
	if(a.ddln<b.ddln) return true;
	else return false;
}
int main()
{
	int n,dex=0,count=0;
	ll time=0,t1,t2;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",&s[i].cost,&s[i].ddln),s[i].strt=s[i].ddln-s[i].cost;
	if(n==0) {printf("0\n");return 0;}
	sort(s,s+n,compare);
	for(int i=0;i<n;i++){
		if(time<=s[i].strt) time+=s[i].cost,res.push(s[i]),count++;
		else if(s[i].cost<res.top().cost)
			time-=res.top().cost,time+=s[i].cost,res.pop(),res.push(s[i]);
	}
	printf("%d\n",count);
}
