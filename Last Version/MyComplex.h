#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include<string>
#include<iostream>
using namespace std;
//������� ���������� � ������� 
double power(double a, int p);
// ��������� �� ������ ����� ���� double �� �� ������� , � ���������� ������ ����� � ���������� id
//��������������� ��� extract(string& str) ������ Complex
double extract_double_num(const string& str, int& idx);
class Complex {
private:
	double _Re;
	double _Im;
public:
	Complex() : _Re(0), _Im(0) {}
	//������� ������ ��������� ��������
	void set(double R, double I);
	//������� ������ �� �������
	void print();
	//������� ��������� ��������. �� ������ ������ � ������� � ������ ������ , ����� ������ exception
	void extract(string& str);
	Complex operator +(Complex c2);
	Complex operator -(Complex c2);
	Complex operator *(Complex c2);
	Complex operator /(Complex c2);
	Complex operator =(Complex cm);
	Complex operator !();

	friend ostream& operator <<(ostream&, const Complex&);
};

inline ostream& operator <<(ostream& output, const Complex& obj) {
	output << obj._Re << " + " << obj._Im << "i\n";
	return output;
}
#endif