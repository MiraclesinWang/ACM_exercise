#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;

bool judge_legal(string s)
{
	int dot = -1;
	rep(i, 0, s.length()){
		if(s[i] == '-'){
			if(i) return false;
		}
		else if(s[i]=='.'){
			if(dot<0) dot=0;
			else return false;
		}
		else if(s[i] >= '0' && s[i] <= '9'){
			if(~dot) dot++;
		}
		else return false;
	}
	if(dot > 2) return false;
	double d;
	stringstream(s) >> d;
	if(d < -1000 || d > 1000) return false;
	return true;
}

int main()
{
	int n, m;
	cin >> n;
	m = 0;
	double sm = 0, tmp;
	string s;
	rep(i, 0, n){
		cin >> s;
		if(!judge_legal(s)) cout << "ERROR: " << s << " is not a legal number\n";
		else stringstream(s) >> tmp, sm += tmp, m++;
	}
	if(m>1) printf("The average of %d numbers is %.2f", m, sm/m);
	else if(m==1) printf("The average of 1 number is %.2f", sm/m);
	else cout << "The average of 0 numbers is Undefined";
	return 0;
}

