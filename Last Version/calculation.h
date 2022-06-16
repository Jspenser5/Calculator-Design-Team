#ifndef CALCULATION_H
#define CALCULATION_H
#include<string>
#include"MyComplex.h"
#include "Rational.h"
#include"Long_arifm.h"
#include"Stack.h"

template <typename T>
void type_calc(string& OPZ, T rez) {
	Stack<T> st;
	T temp1, temp2, result;
	while (OPZ.size() != 0) {
		if (OPZ[0] != '+' and OPZ[0] != '-' and OPZ[0] != '*' and OPZ[0] != '/' and OPZ[0] != '^' and OPZ[0] != '!') {
			temp1.extract(OPZ);
			st.push(temp1);
		}
		else {
			switch (OPZ[0])
			{
			case '!':
				temp1 = st.look_top();
				st.pop();
				!temp1;
				st.push(temp1);
				break;
			case '+':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 + temp2;
				st.push(result);
				break;
			case '-':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 - temp2;
				st.push(result);
				break;
			case '*':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 * temp2;
				st.push(result);
				break;
			case '/':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 / temp2;
				st.push(result);
				break;
			}
		}
		OPZ.erase(OPZ.begin(), OPZ.begin() + 1);
	}
	if (st.get_size() > 1)
		throw exception("Проверьте корректность введённого выражения и перезапустите этап вычислений!");
	rez = st.look_top();
	cout << rez << endl;
}
#endif // _CALCULATION_
