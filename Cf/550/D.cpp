#include<bits/stdc++.h>
#define maxn 200000+10
int a[maxn],cnt[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0,buf,k,res;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]]>sum){
            sum=cnt[a[i]];
            buf=a[i];
        }
    }
    k=0;
    for (int i=0;i<n;++i){
        if (a[i]==buf) ++k;
    }
    res=n-k;
    printf("%d\n",res);
    int left=0;
    for (int i=0;i<n;++i){
        if (a[i]!=buf){
            if (i==n-1){
                for (int j=left;j<n;++j)
                    printf("%d %d %d\n",a[j]<buf?1:2,j+1,j);
            }
            continue;
        }
        for (int j=i-1;j>=left;--j){
            printf("%d %d %d\n",a[j]<buf?1:2,j+1,j+2);
        }
        left=i+1;
    }
}

