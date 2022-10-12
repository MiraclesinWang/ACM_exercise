#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 2000+5
struct cl{
    ll c,d;
    bool operator<(const cl &a)
    {return d<a.d;}
} cr[maxn];
int main()
{
    int n,ldex,rdex;
    ll res,cst;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            scanf("%lld%lld",&cr[i].d,&cr[i].c);
        res=cr[1].c,cst=0;
        ldex=1,rdex=2;
        while(rdex<=n){
            cst=cr[rdex].d-cr[ldex].d;
            //printf("%d %lld %lld\n",rdex,cst,cr[rdex].c);
            if(cst>=cr[rdex].c){
                cst=0;
                res+=cr[rdex].c;
                ldex=rdex;
            }
            else
                res+=cst;
            rdex++;
        }
        printf("%d\n",res);
    }
}
