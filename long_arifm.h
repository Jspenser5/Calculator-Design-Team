#pragma once
#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
using namespace std;

class long_arithmetic {
public:

	// �������� �����
	vector <int> _digits;

	// ���� �����
	bool _is_negative;

	// �������� �����
	void num_create(string str);

	// �������� ���������� �����
	void _remove_zeros();

	// �������� �����
	long_arithmetic operator +(long_arithmetic left, const long_arithmetic& right);

	// �������� ����� 
	long_arithmetic operator -(long_arithmetic left, const long_arithmetic& right);

};

#endif
