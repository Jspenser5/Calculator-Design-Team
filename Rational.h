#ifndef _RATIONAL_
#define _RATIONAL_
#include <iostream>
#include <cmath>
using namespace std;

// ðåêóðñèâíàÿ ïðîöåäóðà, âîçâðàùàþùàÿ greatest common divisor (ÍÎÄ)
static int gcd(int a, int b) {
    a = abs(a), b = abs(b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

class Rational {
private:
    int _m, _n;
public:
    // ïî óìîë÷àíèþ
    Rational();
    // ïî ïîëÿì
    Rational(int n, int m);
    // êîïèðîâàíèÿ
    Rational(const Rational& cl_obj);
    ~Rational() {}

    int get_numerator() const { return _m; }
    int get_denominator() const { return _n; }

    const Rational& operator =(const Rational& cl_obj);
    bool operator >(const Rational& obj);
    bool operator <(const Rational& obj);
    Rational operator +(const Rational& obj);
    Rational operator -(const Rational& obj);
    Rational operator *(const Rational& obj);
    Rational operator /(const Rational& obj);

    // âûçûâàòü îïåðàöèþ îáÿçàòåëüíî â ñêîáêàõ! Ïðèìåð: (rn1 ^ 3)
    Rational operator ^(const int num);

    friend ostream& operator <<(ostream&, const Rational&);
    friend istream& operator >>(istream&, Rational&);
};

inline ostream& operator <<(ostream& output, const Rational& obj) {
    output << obj._m << " / " << obj._n << endl;
    return output;
}
inline istream& operator >>(istream& input, Rational& obj) {
    input >> obj._m;
    input >> obj._n;
    return input;
}

#endif //_RATIONAL_
