#include <iostream>
#include <vector>
#include"long_arifm.h"
using namespace std;

// создание числа
void long_arithmetic::num_create(string num) {
	if (num.length() == 0) {
		this->_is_negative = false;
	}
	else {
		if (num[0] == '-') {
			num = num.substr(1);
			this->_is_negative = true;
		}
		else {
			this->_is_negative = false;
		}
		for (size_t i = num.length(); i > 0; i -= 9) {
			if (i < 9)
				this->_digits.push_back(atoi(num.substr(0, i).c_str()));
			else
				this->_digits.push_back(atoi(num.substr(i - 9, 9).c_str()));
		}
		// удаление ведущих нулей
		this->_remove_zeros();
	}
}

// удаление лидирующих нулей
void long_arithmetic::_remove_zeros() {
	while (this->_digits.size() > 1 && this->_digits.back() == 0) {
		this->_digits.pop_back();
	}
	// чтобы у нас не было отрицательного нуля
	if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}

// сложение чисел
long_arithmetic operator +(long_arithmetic left, const long_arithmetic& right) {
	int flag = 0; // флаг переноса 

	if (left._is_negative) {
		if (right._is_negative) return -(-left + (-right));
		else return right - (-left);
	}
	else if (right._is_negative)
		return left - (-right);
	
	for (size_t i = 0; i <  max(left._digits.size(), right._digits.size()) || flag != 0; ++i) {
		if (i == left._digits.size()) 
			left._digits.push_back(0);
		left._digits[i] += flag + (i < right._digits.size() ? right._digits[i] : 0);
		flag = left._digits[i] >= long_arithmetic::base;
		if (flag != 0)
			left._digits[i] -= long_arithmetic::base;
	}

	return left;
}

// разность чисел 
long_arithmetic operator -(long_arithmetic left, const long_arithmetic& right) {
	if (right._is_negative)
		return left + (-right);
	else if (left._is_negative) 
		return -(-left + right);
	else if (left < right) 
		return -(right - left);
	int flag = 0;
	for (size_t i = 0; i < right._digits.size() || flag != 0; ++i) {
		left._digits[i] -= flag + (i < right._digits.size() ? right._digits[i] : 0);
		flag = left._digits[i] < 0;
		if (flag != 0) 
			left._digits[i] += long_arithmetic::BASE;
	}

	left._remove_zeros();
	return left;
}

