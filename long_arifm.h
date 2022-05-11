#pragma once
#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
using namespace std;

class big_integer {
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
	big_integer operator +(big_integer left, const big_integer& right);

	// разность чисел 
	big_integer operator -(big_integer left, const big_integer& right);

};

#endif
