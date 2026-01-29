#include <stdio.h>

void printbinary(int a){
    if(a == 0){
        return ;
    }
    printbinary(a / 2);
    printf("%d",a % 2);   //倒序输出 %2 的值
}                         //递归到最后要执行完成函数才能输出

int main()
{
    int a;
    scanf("%d",&a);
    if(a == 0){
        printf("0");
        return 0;
    }
    printbinary(a);
    return 0;
}