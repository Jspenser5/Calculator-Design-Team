#include<iostream>
#include"reverse_polish_notation.h"
using namespace std;


int main() {
	string expression;
	cin >> expression;
	vector<char> operators{'-','+','/','*','!'};
	vector<int> priorities{ 0,0,1,1,2 };
	cout << reverse_polish_notation(expression, operators,priorities) << endl;
	return 0;
}
