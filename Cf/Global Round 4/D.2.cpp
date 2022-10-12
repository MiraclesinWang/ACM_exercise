#include <cstdio>
bool is_prime(int x){
    if (x==2) return true;
    if ((x&1)==0) return false;
    for (int i=3;i*i<=x;i+=2){
        if (x%i==0) return false;
    }
    return true;
}
int n;
int main(){
    scanf("%d",&n);
    if (is_prime(n)){
        printf("%d\n",n);
        for (int i=1;i<n;++i){
            printf("%d %d\n",i,i+1);
        }
        printf("%d %d\n",n,1);
    }
    else{
        int cnt=0;
        int nn=n;
        while (!is_prime(nn)){
            ++nn;
            ++cnt;
        }
        printf("%d\n",n+cnt);
        for (int i=1;i<n;++i){
            printf("%d %d\n",i,i+1);
        }
        printf("%d %d\n",n,1);
        for (int i=2;i<cnt+2;++i){
            printf("%d %d\n",i,n-i+2);
        }
    }
    return 0;
}

