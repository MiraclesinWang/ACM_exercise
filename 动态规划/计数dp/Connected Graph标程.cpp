#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int ll;
inline ll read()
{
    ll s=0; bool f=0; char ch=' ';
    while(!isdigit(ch)) {f|=(ch=='-'); ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
    return (f)?(-s):(s);
}
#define R(x) x=read()
inline void write(ll x)
{
    if(x<0) {putchar('-'); x=-x;}
    if(x<10) {putchar(x+'0'); return;}
    write(x/10); putchar((x%10)+'0');
}
#define W(x) write(x),putchar(' ')
#define Wl(x) write(x),putchar('\n')
const int power=4,Base=10000;
struct Int
{
    int a[205];
    Int() {memset(a,0,sizeof a);}
    Int(int x)
    {
        memset(a,0,sizeof a);
//        cout<<"x="<<x<<endl;
        while(x>0)
        {
            a[++a[0]]=x%Base; x/=Base;
        }
    }
    inline void print()
    {
        int i;
        write(a[a[0]]);
        for(i=a[0]-1;i>=1;i--)
        {
            if(a[i]<1000) putchar('0');
            if(a[i]<100) putchar('0');
            if(a[i]<10) putchar('0');
            write(a[i]);
        }
    }
}Bin[2005],C[55][55],Ans[55];
#define P(x) x.print(),putchar(' ')
#define Pl(x) x.print(),putchar('\n')
inline Int operator+(Int p,Int q)
{
    int i; Int res=p; res.a[0]=max(p.a[0],q.a[0]);
    for(i=1;i<=q.a[0];i++)
    {
        res.a[i]+=q.a[i];
        res.a[i+1]+=res.a[i]/Base;
        res.a[i]%=Base;
    }
    while(res.a[res.a[0]+1]) res.a[0]++;
    return res;
}
inline Int operator-(Int p,Int q)
{
    int i; Int res=p;
    for(i=1;i<=q.a[0];i++)
    {
        res.a[i]-=q.a[i];
        if(res.a[i]<0)
        {
            res.a[i+1]--; res.a[i]+=Base;
        }
    }
    while(!res.a[res.a[0]]) res.a[0]--;
    return res;
}
inline Int operator*(Int p,int q)
{
    int i; Int res=p;
    for(i=1;i<=res.a[0];i++) res.a[i]*=q;
    for(i=1;i<=res.a[0];i++)
    {
        res.a[i+1]+=res.a[i]/Base; res.a[i]%=Base;
    }
    while(res.a[res.a[0]+1])
    {
        res.a[0]++; res.a[res.a[0]+1]+=res.a[res.a[0]]/Base; res.a[res.a[0]]%=Base;
    }
    return res;
}
inline Int operator*(Int p,Int q)
{
    int i,j; Int res; res.a[0]=p.a[0]+q.a[0];
    for(i=1;i<=p.a[0];i++) for(j=1;j<=q.a[0];j++)
    {
        res.a[i+j-1]+=p.a[i]*q.a[j];
        res.a[i+j]+=res.a[i+j-1]/Base;
        res.a[i+j-1]%=Base;
    }
    while(!res.a[res.a[0]]) res.a[0]--;
    return res;
}
int main()
{
//    freopen("data.in","r",stdin);
    int i,j,n;
    Bin[0]=Int(1); for(i=1;i<=1500;i++) Bin[i]=Bin[i-1]*2;
//    for(i=1;i<=32;i++) Pl(Bin[i]);
    C[0][0]=Int(1);
    for(i=1;i<=50;i++)
    {
        C[i][0]=Int(1);
        for(j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
//    for(i=0;i<=4;i++)
//    {
//        for(j=0;j<=i;j++) P(C[i][j]);
//        puts("");
//    }
    Ans[1]=Int(1);
    for(i=2;i<=50;i++)
    {
        Ans[i]=Bin[i*(i-1)/2];
        for(j=1;j<i;j++)
        {
            Ans[i]=Ans[i]-Ans[j]*C[i-1][j-1]*Bin[(i-j)*((i-j)-1)/2];
        }
    }
    for(;;)
    {
        R(n); if(n==0) break; Pl(Ans[n]);
    }
    return 0;
}
