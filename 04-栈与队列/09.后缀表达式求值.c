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

char expre[]="82/2+56*-";

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

int gettop(stack *s,int *e){
    if(isEmpty(s)){
        printf("empty");
        return 0;
    }
    *e=s->data[s->top];
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
        default: return num;
    }
}

int eval(stack *s){
    char symbol;
    int op1,op2;
    int index=0;
    contenttype token;
    token=gettoken(&symbol,&index);
    int result;
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
                default:
                break;
            }
        }
        token=gettoken(&symbol,&index);
    }
    pop(s,&result);
    printf("%d\n",result);
    return 1;
}

int main()
{
    stack *s=initial();
    eval(s);
    return 0;
}