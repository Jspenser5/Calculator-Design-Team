#include"MyComplex.h"
double power(double a, int p) {
	double rez = 1;
	for (int i = 0; i < p; i++)
		rez = rez * a;
	return rez;
}
double extract_double_num(const string& str, int& idx) {
	double rez = 0;
	int f = 1;
	if (str[idx] == '-' and str[idx + 1] != ',' and str[idx + 1] != ']') {
		f = -1;
		idx++;
	}
	if (str[idx] != '0') {
		int step = 0;
		while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
			rez = rez * 10 + double(str[idx]) - 48;
			idx++;
			step++;
		}
		if (str[idx] == '.') {
			idx++;
			step = 1;
			while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
				rez = rez + (double(str[idx]) - 48) / power(10, step);
				idx++;
				step++;
			}
		}
		return rez * f;
	}
	idx++;
	return 0;
}
void Complex::set(double R, double I) {
	_Re = R;
	_Im = I;
}
void Complex::print() {
	cout << _Re << " + " << _Im << "i\n";
}
void Complex::extract(string& str) {
	int count = 1, lc = 1;
	if (str.size() < 5)
		throw exception("Не верный формат ввода");
	if (str[0] == '[') {
		this->_Re = extract_double_num(str, count);
		if (str[count] != ',' or count == lc) throw exception("Не верный формат ввода");
		count++;
		lc = count;
		this->_Im = extract_double_num(str, count);
		if (str[count] != ']' or count == lc) throw exception("Не верный формат ввода");
		str.erase(str.begin(), str.begin() + count + 1);
	}
	else throw exception("Не верный формат ввода");
}
Complex Complex::operator +(Complex c2) {
	Complex tmp;
	tmp.set(this->_Re + c2._Re, this->_Im + c2._Im);
	return tmp;
}
Complex Complex::operator -(Complex c2) {
	Complex tmp;
	tmp.set(this->_Re - c2._Re, this->_Im - c2._Im);
	return tmp;
}
Complex Complex::operator !() {
	Complex tmp;
	tmp.set(-(this->_Re), -(this->_Im));
	return tmp;
}
Complex Complex::operator *(Complex c2) {
	Complex tmp;
	tmp.set((this->_Re) * (c2._Re) - (this->_Im) * (c2._Im), (this->_Re) * (c2._Im) + (this->_Im) * (c2._Re));
	return tmp;
}
Complex Complex::operator /(Complex c2) {
	Complex tmp;
	if (c2._Re == 0 and c2._Im == 0)
		throw exception("В результате вычислений произошло деление на ноль");
	tmp.set(((this->_Re) * (c2._Re) + (this->_Im) * (c2._Im)) / (c2._Re * c2._Re + c2._Im * c2._Im), ((this->_Im) * (c2._Re) - (this->_Re) * (c2._Im)) / (c2._Re * c2._Re + c2._Im * c2._Im));
	return tmp;
}
Complex Complex::operator =(Complex cm)
{
	_Re = cm._Re;
	_Im = cm._Im;
	return *this;
}
