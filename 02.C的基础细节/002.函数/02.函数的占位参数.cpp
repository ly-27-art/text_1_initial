#include <iostream>
using namespace std;

void fun1(int a ,int){  //这就是占位参数
    cout << "this is fun1" << endl;
}

void fun2(int a ,int = 20){  //占位参数也可以有默认值
    cout << "this is fun2" << endl;
}

int main()
{
    fun1(10 ,10);
    fun2(20);
    return 0;
}