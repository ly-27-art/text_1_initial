#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    int *data;
    int top;
}stack;

typedef enum{
    left_pare,right_pare,add,sub,mul,divi,mod,eos,num
}contenttype;

stack *initial(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->data=(int*)malloc(sizeof(int)*MAXSIZE);
    s->top=-1;
    return s;
}

char expre[]="82/2+56*-";

int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}
//进栈的为数字
int push(stack *s,int e){
    if(s->top>=MAXSIZE-1){
        printf("full");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

int pop(stack *s,int *e){
    if(isEmpty(s)){
        printf("empty");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}

contenttype gettoken(char *symbol,int *index){
    *symbol=expre[*index];
    *index+=1;
    switch(*symbol){
        case '(': return left_pare;
        case ')': return right_pare;
        case '+': return add;
        case '-': return sub;
        case '*': return mul;
        case '/': return divi;
        case '%': return mod;
        case '\0': return eos;
        default : return num;
    }
}

int eval(stack *s){
    int index=0;//此时的字符串对应下标
    char symbol;//接收此时的字符

    contenttype token;
    token=gettoken(&symbol,&index);//判断字符

    int op1,op2;//接收出栈的两个数
    int result;//接收结果
    while(token!=eos){
        if(token==num){
            push(s,symbol-'0');
        }else{
            pop(s,&op2);
            pop(s,&op1);
            switch(token){
                case add:
                push(s,op1+op2);
                break;
                case sub:
                push(s,op1-op2);
                break;
                case mul:
                push(s,op1*op2);
                break;
                case divi:
                push(s,op1/op2);
                break;
                case mod:
                push(s,op1%op2);
                break;
                default :
                break;
            }
        }
        token=gettoken(&symbol,&index);
    }
    pop(s,&result);
    printf("%d",result);
    return 1;
}

int main()
{
    stack *s=initial();
    eval(s);
    free(s->data);
    free(s);
    return 0;
}