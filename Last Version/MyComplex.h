#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include<string>
#include<iostream>
using namespace std;
//Функция возведения в степень 
double power(double a, int p);
// Извлекает из строки число типа double но не удаляет , а возвращает индекс конца в переменную id
//Вспомогательная для extract(string& str) класса Complex
double extract_double_num(const string& str, int& idx);
class Complex {
private:
	double _Re;
	double _Im;
public:
	Complex() : _Re(0), _Im(0) {}
	//Функция ручной установки значений
	void set(double R, double I);
	//Функция печати на консоль
	void print();
	//Функция извлекает комплекс. из начала строки и удаляет в случае успеха , иначе кидает exception
	void extract(string& str);
	Complex operator +(Complex c2);
	Complex operator -(Complex c2);
	Complex operator *(Complex c2);
	Complex operator /(Complex c2);
	Complex operator =(Complex cm);
	void operator !();

	friend ostream& operator <<(ostream&, const Complex&);
};

inline ostream& operator <<(ostream& output, const Complex& obj) {
	output << obj._Re << " + " << obj._Im << "i\n";
	return output;
}
#endif
