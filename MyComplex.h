#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H
#include<string>
#include<iostream>
using namespace std;
//������� ���������� � ������� 
double power(double a, int p);
// ��������� �� ������ ����� ���� double �� �� ������� , � ���������� ������ ����� � ���������� id
//��������������� ��� extract(string& str) ������ complex
double extract_double_num(const string& str, int& idx);
class complex {
public:
	double Re;
	double Im;
	//������� ������ ��������� ��������
	void set(double R, double I);
	//������� ������ �� �������
	void print();
	//������� ��������� ��������. �� ������ ������ � ������� � ������ ������ , ����� ������ exception
	void extract(string& str);
	complex operator +(complex c2);
	complex operator -(complex c2);
	complex operator *(complex c2);
	complex operator /(complex c2);
	complex operator =(complex cm);
};
#endif
