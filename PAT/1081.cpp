#include <bits/stdc++.h>
using namespace std;

#define MEM(A, b) memset(A, b, sizeof(A))
#define rep(i, x, y) for(int i = x; i < y; i++)
typedef long long LL;

LL gcd(LL a, LL b)
{
	a = abs(a), b = abs(b);
	if(a > b) swap(a, b);
	if(!a) return 1ll;
	LL c;
	while(c=b%a){
		b = a, a=c;
	}
	return a;
}

struct rational{
	LL up, down;
	rational(LL _up, LL _down){
		if(_down<0) _up = -_up, _down=-_down;
		this->down = _down, this->up = _up;
	}
	rational operator + (const rational &oth) const{
		LL d = down*oth.down, u = down*oth.up + up*oth.down;
		LL g = gcd(d, u);
		d /= g, u /= g;
		return rational(u, d);
	}
	friend ostream & operator << (ostream &out, const rational &r){
		if(r.down==1) {out<<r.up;return out;}
		if(!r.up) {out<<0;return out;}
		LL up = r.up;
		bool flag = false;
		if(abs(r.up) >= r.down){
			int tmp = r.up < 0?-abs(r.up) / r.down -1:r.up / r.down;
			up -= r.down * tmp;
			if(tmp) out << tmp, flag = true;
		}
		if(r.up){
			if(flag) out << ' ';
			out << up << '/' << r.down;
		}
		return out;
	}
};

int main()
{
	int n;
	LL a, b;
	cin >> n;
	scanf("%lld/%lld", &a, &b);
	rational r = rational(a, b);
	rep(i, 1, n) scanf("%lld/%lld", &a, &b), r= r+ rational(a, b);
	cout << r;
}
