#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e6 + 10;
char s[maxn];
char res[maxn];
int cnt[5];

int main()
{
	int dex = 0;
	scanf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l/4; i++){
		for(int j = 0; j < 3; j++)
			cnt[j] = 0;
		cnt[s[2*i]-'a']++, cnt[s[2*i+1]-'a']++;
		cnt[s[l-2*i-1]-'a']++, cnt[s[l-2*i-2]-'a']++;
		/*for(int j =0; j < 3; j++)
			printf("%d ", cnt[j]);
		printf("\n");*/
		if(cnt[0] >= 2) res[++dex] = 'a';
		else if(cnt[1] >= 2) res[++dex] = 'b';
		else res[++dex] = 'c'; 
	}
	for(int i = 1; i <= dex; i++)
		printf("%c", res[i]);
	if(l%4 == 3) printf("%c", s[l/2]);
	else if(l%4==2) printf("%c", s[l/2-1]);
	for(int i = dex; i > 0; i--)
		printf("%c", res[i]);
	printf("\n");
}
