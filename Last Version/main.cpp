#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include"reverse_polish_notation.h"
#include"calculation.h"
using namespace std;

int get_norm_input() {
	while (true) {
		int value;
		cin >> value;
		if (cin.fail() or value <= 0 or value > 4) {
			cout << "Введено либо не число , либо число вышло за допустимые значения , повторите ввод : ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}

// -(-[1,2]+[5,4])/[1 ,  1] =-3 + 1i
// -3 | 4 + 2 | 4
// (-(-(-(1))))

int main() {
	setlocale(LC_ALL, "rus");
	cout << "ФФФ" << endl;
	int dialog_tmp = 0;
	string OPZ;
	string expression;
	vector<char> operators{ '-','+','/','*', '^', '!'};
	vector<int> priorities{ 0,0,1,1,2,3 };
	while (dialog_tmp != 4) {
		try {
			cout << "Выберите тип чисел для работы:" << endl;
			cout << " Комплексные числа  - 1" << endl;
			cout << " Рациональные числа - 2" << endl;
			cout << " Длинная арифметика - 3" << endl;
			cout << " Завершение работы программы - 4" << endl;
			cout << "Введите ключ : ";
			dialog_tmp = get_norm_input();
			system("cls");
			switch (dialog_tmp) {
			case 1:
			{
				cout << "Вы выбрали комплексные числа!" << endl << "Формат ввода каждого числа: [a,b], где  a и b рациональные числа вида ****.****" << endl;
				cout << "Введите выражение комплексных чисел: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				complex a;
				OPZ = reverse_polish_notation(expression, operators, priorities);
				cout << OPZ << endl;
				type_calc(OPZ, a);
				break;
			}
			case 2:
			{
				cout << "Вы выбрали рациональные числа!" << endl << "Формат ввода каждого числа: a|b , где  a - целое, b - натуральное" << endl;
				cout << "Введите выражение рациональных чисел: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				Rational b;
				OPZ = reverse_polish_notation(expression, operators, priorities);
				type_calc(OPZ, b);
				break;
			}
			case 3:
			{
				cout << "Вы выбрали длинную арифметику!" << endl << "Формат ввода каждого числа вида ****.****" << endl;
				cout << "Введите выражение комплексных чисел: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				Big_integer c;
				OPZ = reverse_polish_notation(expression, operators, priorities);
				//type_calc(OPZ,c);
				break;
			}
			case 4:
				cout << "Вы успешно завершили работу программы!" << endl;
				break;
			}
			system("pause");
			system("cls");
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}
