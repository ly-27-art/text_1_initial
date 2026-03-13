#include <iostream>
using namespace std;

int fun(int a ,int b = 20 ,int c = 30){
    return a + b + c;
}

int main()
{
   cout << fun(10) <<endl;  // 10 是传给 a 的
   return 0;
}

//  答案的 60 说明可以有默认值
