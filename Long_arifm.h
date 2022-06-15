#ifndef LONG_ARIFM_H
#define LONG_ARIFM_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Big_integer {
private:
	string _num;
	bool _neg;

	void difference(vector<int> x, vector<int> y, vector<int> &result, int length)
	{
		int i, j;
		for (i = 0; i < (length - 1); i++) // проход по всем разр€дам числа, начина€ с последнего, не доход€ до первого
		{
			if (i < (length - 1)) // если текущий разр€д чисел не первый
			{
				x[i + 1]--; // в следующуем разр€де большего числа занимаем 1.
				result[i] = (10 + x[i] - y[i]) % 10;
				cout << result[i] << " ";
				x[i + 1] += (10 + x[i] - y[i]) / 10;
			}
			else if (x[i] >= y[i]) {
				result[i] += x[i] - y[i];
				for (j = i-1; j < length; j++)
					result[j] = x[j];
			}
			else {
				x[i + 1]--; // в следующуем разр€де большего числа занимаем 1.
				result[i] = (10 + x[i] - y[i]) % 10;
			}
		}
		return;
	}
public:
	Big_integer() : _num(""), _neg(true) {}
	Big_integer(string str, bool flag) : _num(str), _neg(flag){}
	Big_integer(const Big_integer& cl_obj) {
		_num = cl_obj._num;
		_neg = cl_obj._neg;
	}
	bool get_sign() {
		return _neg;
	}

	const Big_integer& operator =(const Big_integer& cl_obj) {
		if (&cl_obj == this)
			return *this;
		else {
			_num = cl_obj._num;
			_neg = cl_obj._neg;
		}
	}

	// перед вызовом учесть знак числа
	Big_integer operator+(const Big_integer& obj) {
		string str1 = "", str2 = "", rev_result = "", result = "", str_n = "";
		int tmp = 0, i;

		if (_num.size() >= obj._num.size()) {
			str1 = _num;
			str2 = obj._num;
		}
		else {
			str1 = obj._num;
			str2 = _num;
		}
		int tmp2 = 0;
		if (str1.size() == str2.size())
			tmp2 = (str1[0] - '0') + (str2[0] - '0');
		for (i = 0; i < str2.size(); i++) {
			rev_result += to_string((str1[str1.size() - (i + 1)] - '0' + str2[str2.size() - (i + 1)] - '0' + tmp) % 10);
			tmp = (str1[str1.size() - (i + 1)] - '0' + str2[str2.size() - (i + 1)] - '0') / 10;
		}
		reverse(rev_result.begin(), rev_result.end());
		result = str1.substr(0, str1.size() - str2.size());
		result += rev_result;
		if (tmp2 > 9)
			return Big_integer("1" + result, true);
		else
			return Big_integer(result, true);
	}

	// 1536987420-1536987402
	// 1536987420+9536987402 +++

	// перед вызовом учесть знак числа
	Big_integer operator-(const Big_integer& obj) {
		int k = 3; // определитель знаkа результата операции: к = 3 - числа равны по длине, к = 1 - уменьшаемое €вно больше, к = 2 - вычитаемое €вно больше
		vector<int> a, b;
		int length = max(_num.size(), obj._num.size());
		vector<int> result(length, 0);
		string str_result = "";
		if (_num.size() > obj._num.size())
			k = 1;
		else if (_num.size() < obj._num.size())
			k = 2;
		// закидываем числа в вектора "перевЄрнутыми"
		for (int i = _num.size()-1; i >= 0; i--)
			a.push_back(_num[i] - '0');
		for (int i = obj._num.size()-1; i >= 0; i--)
			b.push_back(obj._num[i] - '0');

		if (_num.size() == obj._num.size())
			for (int i = length - 1; i >= 0; i--)
				if (a[i] > b[i])
				{
					k = 1;
					break;
				}
				else if (b[i] > a[i])
				{
					k = 2;
					break;
				}

		if (k == 3) {
			str_result += "0";
			return Big_integer(str_result, true);
		}
		if (k == 1) {
			difference(a, b, result, length); 
			for (int i = result.size() - 1; i >= 0; i--)
				if (result[i] != 0)
					str_result += to_string(result[i]);
			return Big_integer(str_result, true);
		}
		if (k == 2) {
			difference(b, a, result, length);
			for (int i = result.size() - 1; i >= 0; i--)
				if (result[i] != 0)
					str_result += to_string(result[i]);
			return Big_integer(str_result, false);
		}
	}

	void extract(string& str) {
		int idx = 0;
		string res = "";
		if (str[idx] != 0)
			while (int(str[idx]) <= 57 && int(str[idx]) >= 48 && idx < str.size()) {
				res += str[idx];
				idx++;
			}
		else
			throw exception("Ќекорректный ввод выражени€ ");
		_num = res;
		str.erase(str.begin(), str.begin() + idx);
	}
	friend ostream& operator <<(ostream&, const Big_integer&);
};

inline ostream& operator <<(ostream& output, const Big_integer& obj) {
	output << obj._num << endl;
	return output;
}


#endif
