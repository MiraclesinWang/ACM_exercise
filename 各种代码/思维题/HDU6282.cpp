#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn], b[maxn];
char s[maxn], t[maxn];

int main()
{
	while(scanf("%s", s) != EOF){
		scanf("%s", t);
		int c1 = 0, cnt = 0, c2 = 0;
		for(int i = 0; i < strlen(s); i++){
			if(s[i] == 'c') a[++c1] = cnt, cnt = 0;
			else cnt++;
		}
		a[++c1] = cnt, cnt = 0;
		for(int i = 0; i < strlen(t); i++){
			if(t[i] == 'c') b[++c2] = cnt, cnt = 0;
			else cnt++;
		}
		b[++c2] = cnt;
		if(c1 != c2) {printf("No\n");continue;}
		bool flag = true;
		for(int i = 1; i <= c1; i++)
			if(abs(a[i]-b[i]) % 2) {printf("No\n");flag = false;break;}
		if(flag) printf("Yes\n");
	}
}
