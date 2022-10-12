#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],cnt[maxn];
int main(){
    int n;
    scanf("%d",&n);
    int ma=-1;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        ma=std::max(ma,a[i]);
        ++cnt[a[i]];
    }
    bool flag=true;
    int sum=0;
    for (int i=0;i<=ma;++i){
        if (cnt[i]>2) flag=false;
        else if (cnt[i]==2) ++sum;
    }
    if (!flag){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    sort(a,a+n);
    printf("%d\n",sum);
    for (int i=0;i<n;++i){
        if (cnt[a[i]]==2) printf("%d ",a[i]);
        cnt[a[i]]=1;
    }
    printf("\n%d\n",n-sum);
    sort(a,a+n,greater<int>());
    for (int i=0;i<n;++i){
        if (cnt[a[i]]) printf("%d ",a[i]);
        --cnt[a[i]];
    }
    printf("\n");
    return 0;
}
