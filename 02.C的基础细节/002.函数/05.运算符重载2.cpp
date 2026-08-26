#include <iostream>
using namespace std;

// 全局函数重载加号运算符
class person{

    public:
    int m_a;
    int m_b;

};

person operator+ (person &p1,person &p2){

    person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    
    return temp;
}

void test01(){

    person p1;
    p1.m_a = 10;
    p1.m_b = 10;
    person p2;
    p2.m_a = 10;
    p2.m_b = 10;

    person p3 = p1 + p2;
// 本质：person p3 = operator+(p1,p2);

    cout << "p3.m_a = " << p3.m_a << endl;
    cout << "p3.m_b = " << p3.m_b << endl;
}

int main(){

    test01();

    return 0;
}