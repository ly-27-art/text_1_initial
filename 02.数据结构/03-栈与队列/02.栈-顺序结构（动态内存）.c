#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    int *data;
    int top;
}stack;

//初始化
stack *initial(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->data=(int*)malloc(sizeof(int)*MAXSIZE);
    s->top=-1;
    return s;
}

//判断栈是否为空
int iseEmpty(stack *s){
    if(s->top==-1){
        printf("empty");
        return 1;
    }else{
        return 0;
    }
}

//进栈/压栈
int push(stack *s,int e){
    if(s->top==MAXSIZE-1){
        printf("fill");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//出栈
int pop(stack *s,int *e){
    *e=s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int gettop(stack *s,int *e){
    *e=s->data[s->top];
    return 1;
}


int main()
{
    stack *s=initial();
    push(s,10);
    push(s,20);
    push(s,30);
    int e;
    pop(s,&e);
    printf("%d\n",e);
    gettop(s,&e);
    printf("%d\n",e);
    return 0;
}