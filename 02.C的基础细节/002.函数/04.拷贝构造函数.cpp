#include <iostream>
using namespace std;

//1、创建一个类，C++编译器会给每个类都添加至少3个函数
// 默认构造 （空实现）
// 析构函数 （空实现）
// 拷贝构造 （值拷贝）

class person{
    public:
    int m_age;

    person(int age){
        m_age = age;
        cout << "default construction has been used" << endl;
    }
};

void copy(){
    person p1(18);

    person p2(p1); // 默认拷贝构造函数
    cout << p2.m_age << endl;
}

int main()
{
    copy();
    return 0;
}