#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream> 
using namespace std;
#define maxn 3000+5
#define ll long long
const ll INF=1e15;
ll dp[maxn];
ll c[maxn],d[maxn];
struct classroom{
    ll c,d;
    bool operator<(const classroom &a)
    {return d<a.d;}
} cr[maxn];
int main()
{
	ios::sync_with_stdio(false);
    int n;
    ll sm,cnt,res=INF;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            dp[i]=INF;
        for(int i=1;i<=n;i++)
            cin>>cr[i].d>>cr[i].c;
        sort(cr+1,cr+n+1);
        dp[1]=cr[1].c;
        for(int i=2;i<=n;i++){
            sm=0,cnt=0;
            for(int j=i-1;j>0;j--){
                sm+=cnt*(cr[j+1].d-cr[j].d);
                dp[i]=min(dp[i],sm+dp[j]+cr[i].c);
                cnt++;
            }
        }
        sm=0,cnt=1;
        res=dp[n];
        for(int i=n-1;i>=1;i--){
            sm+=cnt*(cr[i+1].d-cr[i].d);
            res=min(res,dp[i]+sm);
            cnt++;
        }
        cout<<res<<endl;
    }
}
