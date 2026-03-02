//不能返回局部变量，只能返回静态变量
#include <iostream>
using namespace std;

int &fun(){
    static int a = 10;
    return a;
}

int main()
{
    int &ref = fun();
    cout << ref << endl;
    return 0;
}