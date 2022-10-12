#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL l,r,p[25];
int bit[25];
 
struct node
{
    LL cnt,sum,sqsum;
} dp[25][10][10];
 
node dfs(int len,int sum1,int sum2,int flag)
{
    if(len<0)
    {
        node tmp;
        tmp.cnt=(sum1!=0&&sum2!=0);
        tmp.sum=tmp.sqsum=0;
        return tmp;
    }
    if(flag==0&&dp[len][sum1][sum2].cnt!=-1)return dp[len][sum1][sum2];
    node ans,tmp;
    int end=flag?bit[len]:9;
    ans.cnt=ans.sqsum=ans.sum=0;
    for(int i=0; i<=end; i++)
    {
        if(i==7)continue;
        tmp=dfs(len-1,(sum1+i)%7,(sum2*10+i)%7,flag&&i==end);
        ans.cnt+=tmp.cnt;
        ans.cnt%=mod;
        ans.sum+=(tmp.sum+i*p[len]%mod*tmp.cnt%mod)%mod;
        ans.sum%=mod;
        ans.sqsum+=(tmp.sqsum+2*p[len]*i%mod*tmp.sum%mod)%mod;
        ans.sqsum%=mod;
        ans.sqsum+=(tmp.cnt*p[len]%mod*p[len]%mod*i*i%mod);
        ans.sqsum%=mod;
    }
    if(flag==0)dp[len][sum1][sum2]=ans;
    return ans;
}
LL solve(LL n)
{
    int len=0;
    while(n)
    {
        bit[len++]=n%10;
        n/=10;
    }
    return dfs(len-1,0,0,1).sqsum;
}
int main()
{
    p[0]=1;
    for(int i=1; i<20; i++)
        p[i]=(p[i-1]*10)%mod;
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                dp[i][j][k].cnt=-1;
            }
        }
    }
    while(scanf("%lld", &l), l)
		printf("%lld\n", solve(l));
    /*int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",((solve(r)-solve(l-1))%mod+mod)%mod);
    }*/
    return 0;
}


