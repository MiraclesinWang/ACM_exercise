#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, y) for(int i = x; i < y; i++)
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)
#define frt(x) x==fa[x]?x:fa[x]=frt(fa[x])
#define MEM(A, b) memset(A, b, sizeof(A))
#define debug(x) cout<<#x<<":"<<x<<"\n"
typedef long long LL;
const int maxn = 1e5 + 10;

struct student{
	string id, name;
	int grade;
	friend ostream& operator <<(ostream &out, const student &oth){
		out << oth.id << " " << oth.name << " " << oth.grade;
		return out;
	}
	student(string _i, string _name, int _g):id(_i), name(_name), grade(_g){}
	student():grade(0){}
} s[maxn];

bool cmp1(student &s1, student &s2)
{return s1.id < s2.id;}

bool cmp2(student &s1, student &s2)
{
	if(s1.name == s2.name) return s1.id < s2.id;
	return s1.name < s2.name;
}

bool cmp3(student &s1, student &s2)
{
	if(s1.grade == s2.grade) return s1.id < s2.id;
	return s1.grade < s2.grade;
}

int main()
{
	int n, c;
	cin >> n >> c;
	rep(i, 0, n){
		string id, name;
		int score;
		getchar();
		cin >> id >> name >> score;
		s[i] = student(id, name, score);
	}
	if(c==1) sort(s, s+n, cmp1);
	else if(c==2) sort(s, s+n, cmp2);
	else sort(s, s+n, cmp3);
	rep(i, 0, n){
		cout << s[i];
		if(i < n-1) cout << "\n";
	}
	return 0;
}

