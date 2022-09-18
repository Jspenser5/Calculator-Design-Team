#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
#include <stack>
#define SIZE_LL 14
#define SIZE_CELL 100000000
using namespace std;
class ll {
private:
	long long num[SIZE_LL];
public:
	ll() {
		for (int i = 0; i < SIZE_LL; i++)
			num[i] = 0;
	}
	ll(long long _num[SIZE_LL]) {
		for (int i = 0; i < SIZE_LL; i++)
			num[i] = _num[i];
	}
	ll(ll& _num) {
		for (int i = 0; i < SIZE_LL; i++)
			num[i] = _num.get_ind(i);
	}
	long long get_ind(int i) {
		return num[i];
	}
	void set_ind(int i, long long x) {
		num[i] = x;
	}
	ll operator +(ll other) {
		ll a;
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL-1)
				a.set_ind(i + 1, a.get_ind(i + 1)+(a.get_ind(i) + other.get_ind(i) + num[i]) / SIZE_CELL);
			a.set_ind(i, (a.get_ind(i) + other.get_ind(i) + num[i]) % SIZE_CELL);
		}
		return a;
	}
	ll operator -(ll other) {
		ll a;
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL-1&& a.get_ind(i) + num[i] - other.get_ind(i) < 0) {
				a.set_ind(i + 1, a.get_ind(i+1) - 1);
				a.set_ind(i, a.get_ind(i) + SIZE_CELL);
			}
			a.set_ind(i,a.get_ind(i) + num[i] - other.get_ind(i));
		}
		return a;
	}
	ll operator *(ll other) {
		ll a;
		for (int i = 0; i < SIZE_LL; i++) 
			for (int j = 0; j < SIZE_LL; j++) 
				if (i + j < SIZE_LL)
					a.set_ind(i+j,a.get_ind(i+j) + num[i] * other.get_ind(j));
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL - 1)
				a.set_ind(i + 1, a.get_ind(i + 1) + a.get_ind(i) / SIZE_CELL);
			a.set_ind(i, a.get_ind(i) % SIZE_CELL);
		}
		return a;
	}
	friend ostream& operator <<  (ostream& os, ll& a) {
		int flag = 0;
		for (int i = SIZE_LL - 1; i >= 0; i--) {
			long long help = a.get_ind(i);
			if (flag == 1 && help * 10 < SIZE_CELL) 
				if (help == 0)
					os << "00000000";
				else{
					while (help * 10 < SIZE_CELL) {
						os << 0;
						help *= 10;
					}
					os << a.get_ind(i);
				}			
			else 
				if (flag == 1 || flag == 0 && help != 0) {
					os << help;
					flag = 1;
				}
			}
		if (flag == 0)
			os << 0;
		return os;
	}
}; 
