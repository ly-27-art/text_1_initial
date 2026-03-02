/*

   注意：
   如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有默认值

*/

#include <iostream>
using namespace std;

/*

int fun(int a ,int b = 20 ,int c ,int d){  错误的，c 和 d 必须有默认值
    return a + b + c;
}

*/

int fun(int a ,int b = 20 ,int c = 30){
    return a + b + c;
}

int main()
{
   cout << fun(10 ,30) <<endl;
   return 0;
}