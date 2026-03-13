#include <iostream>
using namespace std;

void showvalue(const int val){
    // val = 1000; 修改没有用了
    cout << "val = " << val <<endl;
}

int main()
{
    int a = 10;
    showvalue(a);
    cout << "a = " << a <<endl;


    // int &ref = 100;  错误的，右值必须是地址
    const int &ref = 100;  // 正确的，等价于 int temp = 100;  int &ref = temp;
    cout << "ref = " << ref << endl;

    return 0;
}