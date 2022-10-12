#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
char a[maxn];
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%s",a);
        int len=strlen(a);
        sort(a,a+len);
        bool flag=true;
        for (int i=1;i<len&flag;++i){
            if (a[i]-a[i-1]!=1) flag=false;
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}

