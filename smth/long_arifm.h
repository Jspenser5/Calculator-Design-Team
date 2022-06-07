#pragma once
#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
using namespace std;

class big_integer {
    // ��������� ������� ��������� (1 000 000 000)
    static const int BASE = 1000000000;

    // ���������� ��������� �����
    vector<int> _digits;

    // ���� �����
    bool _is_negative;

    void _remove_leading_zeros();
    void _shift_right();

public:
    // �����-����������, ��������� ��� ������� �� ����
    class divide_by_zero : public exception {  };

    big_integer();
    big_integer(string);
    big_integer(signed char);
    big_integer(unsigned char);
    big_integer(signed short);
    big_integer(unsigned short);
    big_integer(signed int);
    big_integer(unsigned int);
    big_integer(signed long);
    big_integer(unsigned long);
    big_integer(signed long long);
    big_integer(unsigned long long);

    friend ostream& operator <<(ostream&, const big_integer&);
    operator string() const;
    const big_integer operator +() const;
    const big_integer operator -() const;
    const big_integer operator ++();
    const big_integer operator ++(int);
    const big_integer operator --();
    const big_integer operator --(int);
    friend bool operator ==(const big_integer&, const big_integer&);
    friend bool operator <(const big_integer&, const big_integer&);
    friend bool operator !=(const big_integer&, const big_integer&);
    friend bool operator <=(const big_integer&, const big_integer&);
    friend bool operator >(const big_integer&, const big_integer&);
    friend bool operator >=(const big_integer&, const big_integer&);
    friend const big_integer operator +(big_integer, const big_integer&);
    big_integer& operator +=(const big_integer&);
    friend const big_integer operator -(big_integer, const big_integer&);
    big_integer& operator -=(const big_integer&);
    friend const big_integer operator *(const big_integer&, const big_integer&);
    big_integer& operator *=(const big_integer&);
    friend const big_integer operator /(const big_integer&, const big_integer&);
    big_integer& operator /=(const big_integer&);
    friend const big_integer operator %(const big_integer&, const big_integer&);
    big_integer& operator %=(const big_integer&);

    bool odd() const;
    bool even() const;
    const big_integer pow(big_integer) const;
};



#endif