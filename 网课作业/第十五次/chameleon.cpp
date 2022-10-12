#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100010
#define LD (o<<1)
#define RD ((o<<1)|1)
struct Tree{
    int l,r,sum;
    int lc,rc;
    int cg;
}T[4*N];
struct Edge{int v,next;}E[N];
struct Node{
    int dep,siz,fa,w,hson,num,top;
    Node(){dep=siz=fa=w=hson=num=top=0;}
}P[N];
int first[N],pred[N];
int n,m,last,tot;
void init(){
    last=tot=0;
    memset(first,0,sizeof(first));
    memset(pred,0,sizeof(pred));
}
void addedge(int u,int v){
    E[++last].v=v;
    E[last].next=first[u];
    first[u]=last;
}
void dfs1(int s){
    P[s].siz=1;
    P[s].hson=0;
    for(int i=first[s];i;i=E[i].next){
        int &son=E[i].v;
        if(son==P[s].fa)continue;
        P[son].dep=P[s].dep+1;
        P[son].fa=s;
        dfs1(son);
        P[s].siz+=P[son].siz;
        if(P[P[s].hson].siz<P[son].siz)
            P[s].hson=son;
    }
}
void dfs2(int s,int tp){
    P[s].top=tp;
    P[s].num=++tot;
    pred[tot]=s;
    if(P[s].hson)dfs2(P[s].hson,tp);
    for(int i=first[s];i;i=E[i].next){
        int &son=E[i].v;
        if(son!=P[s].fa&&son!=P[s].hson)
            dfs2(son,son);
    }
}
void pushup(int o){
    T[o].lc=T[LD].lc;T[o].rc=T[RD].rc;
    T[o].sum=T[LD].sum+T[RD].sum;
    if(T[LD].rc==T[RD].lc)T[o].sum--;
}
void pushdown(int o){
    if(T[o].cg){
        int t=T[o].cg;
        T[LD].cg=T[RD].cg=t;
        T[LD].lc=T[LD].rc=t;
        T[RD].lc=T[RD].rc=t;
        T[o].lc=T[o].rc=t;
        T[LD].sum=T[RD].sum=T[o].sum=1;
        T[o].cg=0;
    }
}
void build(int o,int l,int r){
    T[o].l=l;T[o].r=r;
    if(l==r){
        T[o].lc=T[o].rc=-1;
        T[o].sum=0;T[o].cg=-1;
        return;
    }
    int mid=(l+r)>>1;
    build(LD,l,mid);
    build(RD,mid+1,r);
}
void update(int o,int l,int r,int val){
    if(T[o].l>r||T[o].r<l)return;
    if(l<=T[o].l&&T[o].r<=r){
        T[o].cg=T[o].lc=T[o].rc=val;
        T[o].sum=1;
        return;
    }
    pushdown(o);
    int mid=(T[o].l+T[o].r)>>1;
    if(l<=mid)update(LD,l,r,val);
    if(r>=mid+1)update(RD,l,r,val);
    pushup(o);
}
Tree query(int o,int l,int r){
    if(l<=T[o].l&&T[o].r<=r)return T[o];
    pushdown(o);
    int mid=(T[o].l+T[o].r)>>1;
    if(mid>=r)return query(LD,l,r);
    if(mid<l)return query(RD,l,r);
    Tree ans;
    Tree LL=query(LD,l,mid);
    Tree RR=query(RD,mid+1,r);
    ans.l=LL.l;ans.r=RR.r;
    ans.lc=LL.lc;ans.rc=RR.rc;
    ans.sum=LL.sum+RR.sum;
    if(LL.rc==RR.lc)ans.sum--;
    return ans;
}
int get_sum(int x,int y){
    int lastx=-1,lasty=-1,ans=0;
    while(P[x].top!=P[y].top){
        if(P[x].num<P[y].num)swap(x,y),swap(lastx,lasty);
        Tree tmp=query(1,P[P[x].top].num,P[x].num);
        ans+=tmp.sum;
        if(lastx==tmp.rc)ans--;
        lastx=tmp.lc;
        x=P[P[x].top].fa;
    }
    if(P[x].num>P[y].num)swap(x,y),swap(lastx,lasty);
    Tree tmp=query(1,P[x].num,P[y].num);
    ans+=tmp.sum;
    if(lastx==tmp.lc)ans--;
    if(lasty==tmp.rc)ans--;
    return ans;
}
void get_update(int x,int y,int val){
    while(P[x].top!=P[y].top){
        if(P[x].num<P[y].num)swap(x,y);
        update(1,P[P[x].top].num,P[x].num,val);
        x=P[P[x].top].fa;
    }
    if(P[x].num>P[y].num)swap(x,y);
    update(1,P[x].num,P[y].num,val);
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=1;i<=n;i++) scanf("%d",&P[i].w);
    for(int i=1;i<n;i++){
    	scanf("%d%d",&a,&b);
        addedge(a,b);addedge(b,a);
    }
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1;i<=n;++i)update(1,P[i].num,P[i].num,P[i].w);
    for(int i=1;i<=m;++i){
        char t[2];
        scanf("\n%s",t);
        scanf("%d%d",&a,&b);
        if(t[0]=='Q')printf("%d\n",get_sum(a,b));
        if(t[0]=='C'){
            scanf("%d",&c);
            get_update(a,b,c);
        }
    }
    return 0;
}
