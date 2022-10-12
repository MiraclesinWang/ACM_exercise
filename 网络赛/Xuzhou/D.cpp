#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
char s[maxn], t[maxn];
int nxt[maxn];

void getnext(char *m)
{

    int i = 0, n=strlen(m), k = -1;
    nxt[0]=-1;
    while(i<n)
    {
        if(k==-1 || m[i]==m[k])
        {
            i++; k++;
            nxt[i]=k;
        }
        else k=nxt[k];
    }
}
bool kmp(char *a,char *b)//Æ¥ÅäabÁ½´®£¬aÎª¸¸´®
{
    int i=0,j=0;
    int len1=strlen(a);
    int len2=strlen(b);
    getnext(b);
    while(i<len1&&j<len2)
    {
      if(j==-1||a[i]==b[j])
        ++i,++j;
      else
        j=nxt[j];
    }
    if(j==len2) return true;
    else return false;
}

int main()
{
	scanf("%s", t);
	int q, l = strlen(t);
	scanf("%d", &q);
	while(q--){
		scanf("\n%s", s);
		if(strlen(s) == l){
			bool flag = true;
			for(int i = 0; i < l; i++)
				if(s[i] != t[i]) {printf("friend!\n");flag = false;break;}
			if(flag) printf("jntm!\n");
		}
		else if(strlen(s) > l){
			if(kmp(s, t)) printf("my teacher!\n");
			else printf("senior!\n");
		}
		else{
			if(kmp(t, s)) printf("my child!\n");
			else printf("oh, child!\n");
		}
	}
}

