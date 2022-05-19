#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H
#include<vector>
#include<string>
using namespace std;
//Функция для проверки наличия Данного элемента в векторе символов
int in_vector(vector<char> v, char value);
//Функция для приведения выражения по ОПЗ в соотвецтвии с приоритетами операций
string reverse_polish_notation(string& expression, vector<char>& priorities);
#endif
