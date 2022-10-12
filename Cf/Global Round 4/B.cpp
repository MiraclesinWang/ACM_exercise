#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
#define maxn 1000000 + 10

char a[maxn];
ll b[maxn][3]; 

int main()
{
	ll res = 0;
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='o') b[i][0]=0;
		else b[i][0]=1;
	}
	int lc = 0, rc = 0;
	for(int i = 1; i < len; i++){
		if(b[i-1][0]==1 && b[i][0]==1) lc += 1;
		else if(b[i][0] == 0) b[i][1] = lc;
	}
	for(int i = len-2; i >= 0; i--){
		if(b[i+1][0] == 1 && b[i][0]==1) rc += 1;
		else if(b[i][0] == 0) b[i][2] = rc;
	}
	for(int i = 0;i < len; i++)
		if(b[i][0]==0) res+=b[i][1]*b[i][2];
	printf("%lld\n", res);
}

