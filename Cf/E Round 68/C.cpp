#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 105
char p[maxn], s[maxn], t[maxn];
int cnt[30];

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	scanf("\n");
	scanf("%s\n%s\n%s", s, p, t);
	int d1 = 0, d2 = 0;
	int l1 = strlen(s), l2 = strlen(p), l3 = strlen(t);
	if(l1 > l2) {printf("NO\n");return;}
	while(d2 < l2){
		if(d1 == l1) break;
		if(s[d1] == p[d2]) d1++;
		d2++;
	}
	if(d1 != l1) {printf("NO\n");return;}
	for(int i = 0; i < l2; i++)
		cnt[p[i] - 'a'] += 1;
	for(int i = 0; i < l1; i++)
		cnt[s[i] - 'a'] -= 1;
	for(int i = 0; i < l3; i++)
		cnt[t[i] - 'a'] -= 1;
	bool flag = true;
	for(int i = 0; i < 26; i++)
		if(cnt[i] > 0) flag = false;
	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve();
}
