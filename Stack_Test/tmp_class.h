#ifndef _TMP_CLASS_
#define _TMP_CLASS_
#include<iostream>
#include<string>
#include"stack.h"
using namespace std;

class Point {
public:
    int a, b;
    Point() {
        a = b = c = d = 0;
    }
    friend ostream& operator <<(ostream&, const Point&);
    friend istream& operator >>(istream&, Point&);

private:
    int c, d;

};

inline ostream& operator <<(ostream& output, const Point& pt) {
    output << "a = " << pt.a << ", " << "b = " << pt.b << ", " << "c = " << pt.c << ", " << "d = " << pt.d;
    return output;
}

inline istream& operator >>(istream& input, Point& pt) {
    input >> pt.a;
    input >> pt.b;
    input >> pt.c;
    input >> pt.d;
    return input;
}

#endif //_TMP_CLASS_