/*

   注意：
   声明和实现只能有一个有默认参数
   
*/

#include <iostream>
using namespace std;

int fun(int a = 20 ,int b = 20);  // 声明

int main()
{
   cout << fun() <<endl;
   return 0;
}

/* int fun(int a = 20 ,int b = 20){
   return a + b;
}
*/

int fun(int a ,int b){  //实现
    return a + b;
}