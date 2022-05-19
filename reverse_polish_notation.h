#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H
#include<vector>
#include<string>
using namespace std;
int in_vector(vector<char> v, char value);
string reverse_polish_notation(string& expression, vector<char>& priorities);
#endif
