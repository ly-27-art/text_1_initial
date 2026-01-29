#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    int binary[32];
    int i = 0;
    if(a == 0){
        printf("0");
        return 0;
    }
    while(a != 0){
        binary[i] = a % 2;
        a /= 2;
        i++;
    }
    for(int j = i - 1;j >= 0;j--){
        printf("%d",binary[j]);
    }
    return 0;
}