#pragma once
#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
using namespace std;

class big_integer {
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
	big_integer operator +(big_integer left, const big_integer& right);

	// �������� ����� 
	big_integer operator -(big_integer left, const big_integer& right);

};

#endif
