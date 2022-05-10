#include<bits/stdc++.h>
using namespace std;

// рекурсивная процедура, возвращающая greatest common divisor (НОД)
static int gcd(int a, int b){
    a = abs(a),b = abs(b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
    
class Rational{
private:
    int _m, _n;
public:
    // по умолчанию
    Rational(){
        _m = 0;
        _n = 1;
    }
    // по полям
    Rational(int n, int m){
        _m = n;
        _n = m;
    }
    // копирования
    Rational(const Rational& cl_obj){
        _m = cl_obj._m;
        _n = cl_obj._n;
    }
    ~Rational(){}
    
    int get_numerator() const{return _m;}
    int get_denominator() const{return _n;}
    
    const Rational& operator =(const Rational& cl_obj){
        if (&cl_obj == this)
		    return *this;
        else{
            _m = cl_obj._m;
            _n = cl_obj._n;
        }
    }
    bool operator >(const Rational& obj){
        if (_m * obj._n > obj._m * _n)
            return true;
        else
            return false;
    }
    bool operator <(const Rational& obj){
        if (_m * obj._n < obj._m * _n)
            return true;
        else
            return false;
    }
    
    Rational operator +(const Rational& obj){
        int m, n;
        m = (_m * obj._n + obj._m * _n) / gcd(_m * obj._n + obj._m * _n, _n * obj._n);
        n = (_n * obj._n) / gcd(_m * obj._n + obj._m * _n, _n * obj._n);
        return Rational(m, n);
    }
    Rational operator -(const Rational& obj){
        int m, n;
        m = (_m * obj._n - obj._m * _n) / gcd(_m * obj._n - obj._m * _n, _n * obj._n);
        n = (_n * obj._n) / gcd(_m * obj._n - obj._m * _n, _n * obj._n);
        return Rational(m, n);
    }
    Rational operator *(const Rational& obj){
        int m, n;
        m = (_m * obj._m) / gcd(_m * obj._m, _n * obj._n);
        n = (_n * obj._n) / gcd(_m * obj._m, _n * obj._n);
        return Rational(m, n);
    }
    Rational operator /(const Rational& obj){
        int m, n;
        m = (_m * obj._n) / gcd(_m * obj._n, _n * obj._m);
        n = (_n * obj._m) / gcd(_m * obj._n, _n * obj._m);
        return Rational(m, n);
    }
    // вызывать операцию обязательно в скобках! Пример: (rn1 ^ 3)
    Rational operator ^(const int num){
        long long temp_m = 1, temp_n = 1;
        int m, n;
        for (int i = 0; i < num; i++){
            temp_m *= _m;
            temp_n *= _n;
        }
        m = temp_m / gcd(temp_m, temp_n);
        n = temp_n / gcd(temp_m, temp_n);
        return Rational(m, n);
    }
    
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