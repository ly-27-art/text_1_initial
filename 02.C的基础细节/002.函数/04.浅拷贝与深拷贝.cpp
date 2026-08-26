#include <iostream>
using namespace std;

class person{
    public:
    int m_age;
    int *m_height;

    person(int age,int height){
        m_age = age;
        m_height = new int(height);
        cout << "constructor has been used" << endl;
    }

    //自己实现拷贝构造函数 解决浅拷贝带来的问题

    person(const person &p){
        cout << "copy has been used" << endl;

        m_age = p.m_age;

        //m_height = p.m_height; 编译器默认实现就是这行代码
        
        //深拷贝操作
        m_height = new int(*p.m_height);
    }

    ~person(){
        if(m_height != NULL){
            delete m_height;
            m_height = NULL;
        }
        cout << "destructor has been used" << endl;
    }
};

void test01(){
    person p1(18,160);
    cout << p1.m_age << "  " << *p1.m_height << endl;

    person p2(p1);
    cout << p2.m_age << "  " << *p2.m_height << endl;
}  // 析构函数是先 p2 再 p1 就跟栈一样, p1先进后出, p2后进先出

int main()
{
    test01();
    return 0;
}