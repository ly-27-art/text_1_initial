//运用运算符有优先级的原理进行操作
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

char expre[]="x/(i-j)*y";


stack *initial(){
    stack *s=(stack*)malloc(sizeof(stack));
    s->data=(int*)malloc(sizeof(int)*MAXSIZE);
    s->top=-1;
    return s;
}


int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

//这次进栈的为运算符，即enum
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
    *index+=1;  //'*'的运算符优先级高于'+='，低于'++'
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

//输出运算符（因为token不是字符，是enum）
int printtoken(contenttype token){
    switch(token){
        case add:
        printf("+");
        break;
        case sub:
        printf("-");
        break;
        case mul:
        printf("*");
        break;
        case divi:
        printf("/");
        break;
        case mod:
        printf("%%");
        break;
        default :
        return 0;
    }
    return 1;
}

//中转后关键函数
void postfix(stack *s){

    int in_stack[]={0,19,12,12,13,13,13,0};//栈内元素优先级
    int out_stack[]={20,19,12,12,13,13,13,0};//栈内元素优先级

    int index=0;//此时的字符串对应下标
    int e;//接收栈顶元素并用printtoken输出
    char symbol;//接收此时的字符

    push(s,eos);//在开始前先在栈中压入优先级最低的元素，方便之后运算符进栈

    contenttype token;
    token=gettoken(&symbol,&index);//判断字符

    while(token!=eos){

        if(token==num){
            printf("%c",symbol);
        }

        else if(token==right_pare){

            while(s->data[s->top]!=left_pare){//直到遇到左括号之前所有元素出栈
                pop(s,&e);
                printtoken(e);
            }
            pop(s,&e);//左括号出栈

        }
        else{
            //判断运算符优先级
            while(in_stack[s->data[s->top]]>=out_stack[token]){
                pop(s,&e);
                printtoken(e);
            }
            push(s,token);
        }
        token=gettoken(&symbol,&index);

    }
    while(!isEmpty(s)){//出栈剩余运算符
        pop(s,&e);
        if(e!=eos){
            printtoken(e);
        }
    }
}

int main()
{
    stack *s=initial();
    printf("%s\n",expre);
    postfix(s);
    return 0;
}