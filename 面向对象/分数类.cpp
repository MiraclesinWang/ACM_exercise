#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    a = abs(a), b = abs(b);
    if(a > b) swap(a, b);
    while(b%a){
        int c = b%a;
        b = a, a = c;
    }
    return a;
}

class Fraction{
    private:
    int s, m;
    public:
    Fraction();
    Fraction(int, int);
    Fraction(const Fraction &oth);
    Fraction operator + (const Fraction &);
    Fraction operator - (const Fraction &);
    Fraction operator * (const Fraction &);
    Fraction operator / (const Fraction &); 
    friend ostream& operator<<(ostream &, const Fraction &); 
};

Fraction::Fraction()
{
    s = m = 1;
}

Fraction::Fraction(int molecule, int denominator)
{
    if(molecule <= 0){
        if(denominator < 0) molecule = -molecule, denominator = -denominator;
    }
    else if(molecule >= 0 && denominator < 0) molecule = -molecule, denominator = -denominator;
    s = molecule, m = denominator;
}

Fraction::Fraction(const Fraction &oth)
{
    s = oth.s, m = oth.m;
}

Fraction Fraction:: operator + (const Fraction &oth)
{
    int denominator = m * oth.m;
    int molecule = m * oth.s + s*oth.m;
    int _g = gcd(denominator, molecule);
    return Fraction(molecule/_g, denominator/_g);
}

Fraction Fraction:: operator - (const Fraction &oth)
{
    int denominator = m * oth.m;
    int molecule = -m * oth.s + s*oth.m;
    int _g = gcd(denominator, molecule);
    return Fraction(molecule/_g, denominator/_g);
}

Fraction Fraction:: operator * (const Fraction &oth)
{
    int denominator = m * oth.m;
    int molecule = s*oth.s;
    int _g = gcd(denominator, molecule);
    return Fraction(molecule/_g, denominator/_g);
}

Fraction Fraction:: operator / (const Fraction &oth)
{
    int denominator = m * oth.s;
    int molecule = m*oth.m;
    int _g = gcd(denominator, molecule);
    return Fraction(molecule/_g, denominator/_g);
}

ostream& operator<<(ostream& out, const Fraction &oth)
{
    if(!oth.m) out << "NaN";
    else if(!oth.s) out << "0";
    else if(oth.m == 1) out << oth.s;
    else{
    	out << oth.s << "/" << oth.m;
    }
    return out;
}


int main()
{
	Fraction a(1, 3);
	Fraction b = a;
	std::cout << (a+b) << std::endl;
}


