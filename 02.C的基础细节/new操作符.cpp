#include <iostream>
using namespace std;

int *func(){
    int *p = new int(10);
    return p;
}
//创建一个变量
void test01(){
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    delete p;

    //cout << *p << endl; *p已经被释放了，再次访问就是非法操作
}
//创建一个数组
void test02(){
    int *arr = new int[10]; //10 代表有 10 个元素

    for(int i = 0 ; i < 10 ; i++){
        arr[i] = i + 100;
    }

    for(int i = 0 ; i < 10 ; i++){
        cout << arr[i] << endl;
    }

    delete [] arr; //释放数组要加一个中括号
}

int main()
{
    test01();
    test02();
    return 0;
}