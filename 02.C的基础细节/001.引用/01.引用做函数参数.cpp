#include <iostream>
using namespace std;

void fun(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << a <<',' << b << endl;

    fun(a,b);  //不用 * ，编译器帮忙解引用了
    
    cout << a <<',' << b << endl;
}