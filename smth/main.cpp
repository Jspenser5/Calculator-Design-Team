#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>
#include"long_arifm.h"
using namespace std;

int main() {
    big_integer bi("2"), bi2 = 100;
    cout << bi.pow(1000) << endl;
    big_integer f = 1;
    for (big_integer i = 2; i <= bi2; ++i) f *= i;
    cout << f << endl;
}
/*


*/