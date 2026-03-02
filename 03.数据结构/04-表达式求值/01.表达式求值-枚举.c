#include <stdio.h>
//枚举结构体
enum weekday{
    mon,tue,wed,thu,fri,sat,sun
//   0   1   2   3   4   5   6
};

/*
enum weekday{
    mon=1,tue,wed,thu,fri,sat,sun
     1     2   3   4   5   6   7
};
*/

int main()
{
    enum weekday a;
    a=mon;
    enum weekday b;
    b=wed;
    printf("%d %d",a,b);
    return 0;
}

/*

enum weekday{
    mon,tue,wed,thu,fri,sat,sun
};

可以变成：

typedef enum{
    mon,tue,wed,thu,fri,sat,sun
}weekday;

之后就不用weekday前加enum了

*/