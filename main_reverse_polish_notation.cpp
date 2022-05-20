#include<iostream>
#include<string>
#include<vector>
using namespace std;

int in_vector(vector<char> v, char value) {
	int f = -1;
	for (int i = 0; i < v.size(); i++) {
		if (value == v[i]) {
			f = i;
			return f;
		}
	}
	return f;
}
string reverse_polish_notation(string& expression, vector<char>& operators, vector<int> priorities) {
	string rezult;
	int gap_index = -1;
	int min_priority = operators.size();
	if (expression.size() == 0)
		return "";
	//Если выражение заключено в общие скобки то их убираем
	if (expression[0] == '(') {
		for (int i = 1; i < expression.size(); i++) {
			if (expression[i] == ')') {
				if (i == expression.size() - 1) {
					expression.erase(0, 1);
					expression.erase(expression.size() - 1);
				}
				else break;
			}
		}
	}
	//Находим последнюю операцию с минимальным приоритетом
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '(') {
			while (expression[i] != ')')
				i++;
			continue;
		}
		int f = in_vector(operators, expression[i]);
		if (f != -1) {
			if (priorities[f] <= min_priority) {
				gap_index = i;
				min_priority = priorities[f];
			}
		}
	}
	//Если не нашли знаков операций , то интерпретируем это как переменную
	if (gap_index == -1)
		return expression + " ";
	string expressionL(expression, 0, gap_index);
	string expressionR;
	//Добавляем к результату последнюю неучтённую часть , учитывая при этом , 
	//что последний знак операции с нужным приоритетом может оказаться на конце выражения.
	if (gap_index < expression.size() - 1) expressionR.append(expression, gap_index + 1, expression.size() - gap_index);
	else expressionR = "";
	return reverse_polish_notation(expressionL, operators, priorities) + reverse_polish_notation(expressionR, operators, priorities) + expression[gap_index];
}
int main() {
	string expression;
	cin >> expression;
	vector<char> priorities{'-','+','/','*','!'};
	vector<int> priorities{ 0,0,1,1,2 };
	cout << reverse_polish_notation(expression, operators,priorities) << endl;
	return 0;
}
