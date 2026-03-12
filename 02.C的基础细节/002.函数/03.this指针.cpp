#include <iostream>
using namespace std;

class person{
    public:
    person(int age){
        //this 指针指向 被调用的成员函数 所属的对象
        this->age = age;
    }

    person& PersonAddAge(person &p){
        this->age += p.age;
        return *this;
    }

    int age; //最好命名为 m_age

    
};

void test01(){
        person p1(18);
        cout << "the age of p1 is: " << p1.age <<endl;
}

    //返回对象本身的 *this
void test02(){

        person p1(10);

        person p2(10);
        //链式编程思想
        p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

        cout << "the age of p2 is: " << p2.age << endl;
}

int main()
{
    test01();

    test02();

    return 0;
}