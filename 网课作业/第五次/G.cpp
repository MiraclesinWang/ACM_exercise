#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 5000+5
#define INF 0x3f3f3f3f
struct Node{
	int dex;
	ll h,v;
	ll mtply;
};
bool cmp(Node A,Node B) {return A.mtply<B.mtply;}
bool cmp1(Node A,Node B) {return A.h<B.h;}
bool cmp2(Node A,Node B) {return A.v<B.v;}
Node h[maxn],v[maxn];
bool slctd[maxn];
int main()
{
	int n,cnt,r,res=1;
	ll a,b,c,minv=INF,minh=INF,temp;
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&h[i].h,&h[i].v);
		h[i].dex=i,h[i].mtply=a*h[i].h+b*h[i].v;
		v[i]=h[i]; 
	}
	sort(h+1,h+n+1,cmp1);
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=n;i++){
		memset(slctd,false,sizeof(slctd));
		r=1,cnt=0;
		for(int j=1;j<=n;j++){
			/*if(v[j].v>h[i].v) break;
			if(v[j].h<h[i].h) {cnt-=slctd[j];continue;}
			if(h[i].mtply-v[j].mtply>c || v[j].mtply-h[i].mtply>c)
				{cnt-=slctd[j];continue;}
			if(r<j) r=j;*/
			temp=a*h[i].h+b*v[j].v+c;
			while(r<=n && v[r].mtply<=temp){
				if(v[r].h>=h[i].h && v[r].v>=v[j].v) cnt++,slctd[r]=true;
				r++;
			}
			if(j>1) cnt-=slctd[j-1];
			if(cnt>res) res=cnt;
		}
	}
	printf("%d\n",res);
}
