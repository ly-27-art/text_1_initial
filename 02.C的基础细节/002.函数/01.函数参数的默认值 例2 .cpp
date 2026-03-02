#include <iostream>
using namespace std;

int fun(int a ,int b = 20 ,int c = 30){
    return a + b + c;
}

int main()
{
   cout << fun(10 ,30) <<endl;  // 10 是传给 a 的
   return 0;
}

//  答案是 70 说明传的值优先，默认的值其次