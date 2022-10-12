#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n" 

int k;
string s;
int stuck[40];

int char2dex(char c)
{
	if(c>='0' && c<='9') return c-'0';
	else if(c=='_') return 36;
	else return c-'a'+10;
}

char dex2char(int dex)
{
	if(dex<=9) return '0'+dex;
	else if(dex==36) return '_';
	else return dex-10+'a';
}

int main()
{
	MEM(stuck, false);
	cin >> k; cin >> s;
	for(int i=0; i < s.length(); i++){
		bool stk = false;
		char c = s[i];
		if(i <= s.length()-k){
			stk = true;
			int j = i+1;
			for(;j<i+k;j++)
				if(s[i]!=s[j]) {stk=false;break;}
			i = j-1;
		}
		if(stk){
			if(!stuck[char2dex(c)]) stuck[char2dex(c)] = 2;
		}
		else stuck[char2dex(c)]=1;
	}
	for(int i=0; i < s.length(); i++){
		bool stk = false;
		char c = s[i];
		if(i <= s.length()-k){
			stk = true;
			int j = i+1;
			for(;j<i+k;j++)
				if(s[i]!=s[j]) {stk=false;break;}
			i = j-1;
		}
		if(stk && stuck[char2dex(c)]==2) cout << c, stuck[char2dex(c)]=-1;
	}
	cout << "\n";
	for(int i=0; i < s.length(); i++){
		//printf("%d\n", i);
		cout << s[i];
		if(stuck[char2dex(s[i])]==-1) i+=k-1;
	}
}
