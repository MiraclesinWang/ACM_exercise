#include <bits/stdc++.h> 
using namespace std;
#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long ll;
const int N = 5e5 + 5;


int trie[N][27], top, fail[N];

void init(){top=1; mem(trie[0],0);}
void ins(char *s){
    int rt, nxt;
    for (rt=0; *s; rt=nxt, ++s){
        nxt=trie[rt][*s-97];
        if (!nxt) mem(trie[top],0), trie[rt][*s-97]=nxt=top++;
    }
    ++trie[rt][26];
}
void makefail(){
    int u, v, bg, ed;
    static int q[N];
    fail[0]=bg=ed=0;
    FO(i,0,26) if ((v=trie[0][i])) fail[q[ed++]=v]=0;
    while (bg<ed){
        u=q[bg++];
        rep(i,0,26) {
            if ((v=trie[u][i])) fail[q[ed++]=v]=trie[fail[u]][i];
            else trie[u][i]=trie[fail[u]][i];
        }
    }
}
int ac(char *s){
    static bool vis[N];
    int ans=0; mem(vis,0);
    for (int i=0; *s; ++s) {
        i=trie[i][*s-97];
        for (int j=i; j&&!vis[j]; j=fail[j]) vis[j]=1, ans+=trie[j][26];
    }
    return ans;
}
char str[1000005];
int main ()
{
    int T, n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n); init();
        while (n--) scanf("%s",str), ins(str);
        scanf("%s",str); makefail();
        printf("%d\n",ac(str));
    }
    return 0;
}
