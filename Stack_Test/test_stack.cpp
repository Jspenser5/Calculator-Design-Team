#include<iostream>
#include<string>
#include <windows.h>
#include"stack.h"
#include"tmp_class.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack<int> int_st;
    Stack<Point> points_st;
    Point pt;
    try {
        cin >> pt;
        points_st.push(pt);
        int_st.push(1);
        int_st.push(2);
        int_st.push(3);
        int_st.push(12);
        cout << points_st.look_top() << endl;
        cout << int_st.look_top() << endl;
        points_st.pop();
        points_st.pop();
        cout << points_st.get_size() << endl;
        cout << points_st.look_top() << endl;
    }
    catch (string str) {
        cout << str << endl;
    }

    int_st.clear();
    cout << int_st.get_size() << endl;

    return 0;
}


