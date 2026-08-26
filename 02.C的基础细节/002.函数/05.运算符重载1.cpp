#include <iostream>
using namespace std;

// 成员函数重载加号运算符
class person{
    public:
    int m_a;
    int m_b;

    person operator+ (const person &p){
        person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }

    //函数重载版本
    person operator+ (int num){
        person temp;
        temp.m_a = this->m_a + num;
        temp.m_b = this->m_b + num;
        return temp;
    }
};

void test01(){

    person p1;
    p1.m_a = 10;
    p1.m_b = 10;
    person p2;
    p2.m_a = 10;
    p2.m_b = 10;

    person p3 = p1 + p2;
    person p4 = p1 + 20;
// 本质：person p3 = p1.operator+(p2);

    cout << "p3.m_a = " << p3.m_a << endl;
    cout << "p3.m_b = " << p3.m_b << endl;

    cout << "p4.m_a = " << p4.m_a << endl;
    cout << "p4.m_b = " << p4.m_b << endl;
}

int main(){

    test01();

    return 0;
}