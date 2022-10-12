#include <cstdio>
#include <iostream>
using namespace std;

bool prime(int n)
{
    if (2==n) return true;
    if ((n&1)==0) return false;
    for (int j=3;j*j <= n;j += 2)
        if (n%j==0) return false;
    return true;
}

int main()
{
	int n, cnt;
    cin >> n;
    if (prime(n)){
        printf("%d\n",n);
        for (int i = 1; i<n; ++i)
            printf("%d %d\n",i,i+1);
        printf("%d %d\n",n,1);
    }
    else{
        cnt = 0;
        int cpy = n;
        while (!prime(cpy))
            cpy++, cnt++;
        printf("%d\n",n+cnt);
        for (int i = 1;i < n; ++i)
            printf("%d %d\n",i,i+1);
        printf("%d %d\n",n,1);
        for (int i = 2;i < cnt+2; ++i)
            printf("%d %d\n",i,n-i+2);
    }
}

