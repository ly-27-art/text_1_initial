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

char expre[]="12 3 / 25 + 6 *";

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

    while (expre[*index] == ' ') {
        (*index)++;
    }//跳过空格

    *symbol=expre[*index];

    if(*symbol>='0'&&*symbol<='9'){
        return num;
    }   //当symbol等于num时index不进行任何操作

    *index+=1;   //symbol为运算符时index加1

    switch(*symbol){
        case '(': return left_pare;
        case ')': return right_pare;
        case '+': return add;
        case '-': return sub;
        case '*': return mul;
        case '/': return divi;
        case '%': return mod;
        case '\0': return eos;
        default : return ;
    }
}

int eval(stack *s){
    int index=0;   //此时的字符串对应下标
    char symbol;   //接收此时的字符

    contenttype token;
    token=gettoken(&symbol,&index);   //判断字符

    int op1,op2;   //接收出栈的两个数
    int result;   //接收结果

    while(token!=eos){

        if(token==num){
            int value=0;

            while(expre[index]>='0'&&expre[index]<='9'){
                value=value*10+(expre[index]-'0');
                index++;
            }   //多位数压栈

            push(s,value);

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