#include <stdio.h>
int main()
{
    int a = 10;
    int b = 10;

    //常量指针
    const int *p = &a;     // const(常量) *(指针)
    //特点：指针的指向可以修改，但指针指向的值不可修改

    //指针常量
    int * const q = &a;    // *(指针) const(常量)
    //特点：指针的指向可以修改，但指针指向的值不可修改
}