#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

struct Tuple{
  long long a,b,c;
  int ind;
}tup[100010];

bool cmp(Tuple x,Tuple y){
  unsigned long long l=x.a*y.c+x.b*y.c;
  unsigned long long r=y.a*x.c+y.b*x.c;
  if(l==r) return x.ind<y.ind;
  return l<r;
}

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++){
        cin>>tup[i].a>>tup[i].b>>tup[i].c;
        tup[i].ind=i;
    }
    sort(tup+1,tup+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(i!=1) printf(" ");
        cout<<tup[i].ind;
    }
    printf("\n");
  }
  return 0;
}
