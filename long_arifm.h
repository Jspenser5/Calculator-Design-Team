#pragma once
#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
using namespace std;

class long_arithmetic {
public:

	// хранение числа
	vector <int> _digits;

	// знак числа
	bool _is_negative;

	// создание числа
	void num_create(string str);

	// удаление лидирующих нулей
	void _remove_zeros();

	// сложение чисел
	long_arithmetic operator +(long_arithmetic left, const long_arithmetic& right);

	// разность чисел 
	long_arithmetic operator -(long_arithmetic left, const long_arithmetic& right);

};

#endif
