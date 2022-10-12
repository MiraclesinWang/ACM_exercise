#include <cstdio>
#include <cstring>
 
int A,B,dp[11][50000],a[25];
int len;
 
int f(int n){
    int ans = 0,len = 1;
    while(n){
        ans += n % 10 * len;
        len *= 2;
        n /= 10;
    }
    return ans;
}
 
int dfs(int len,int ans,int flag){
    if(len < 0)
	   	return ans >= 0;
    if(ans < 0) 
		return 0;
    int sum = 0;
    if(!flag && dp[len][ans] != -1)
		return dp[len][ans];
    int m = flag ? a[len] : 9;
    for(int i = 0; i <= m; i++) {
        sum += dfs(len - 1, ans - i * (1 << len), flag && i == m);
    }
    if(!flag)
		dp[len][ans] = sum;
    return sum;
}
int main(){
    int t,cas = 1;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--){
        scanf("%d%d",&A,&B);
        len=0;
        while(B){
            a[len++] = B % 10;
            B /= 10;
        }
        printf("Case #%d: %d\n",cas++ ,dfs(len - 1,f(A) , 1));
    }
    return 0;
}
