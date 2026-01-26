#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8

typedef struct{
    int *data;
    int front;
    int rear;
}queue;

//初始化
queue *initial(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->data=(int*)malloc(sizeof(int)*MAXSIZE);
    q->front=0;
    q->rear=0;
    return q;
}

//判断队列是否为空
int isEmpty(queue *q){
    if(q->front==q->rear){
        printf("empty");
        return 1;
    }else{
        return 0;
    }
}

//入队
int enqueue(queue *q,int e){
    if((q->rear+1)%MAXSIZE==q->front){//!!!!!!
        printf("full");
        return 0;
    }
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;//!!!!!!
    return 1;
}

//出队
int dequeue(queue *q){
    if(!isEmpty(q)){
    int e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;//!!!!!!
    return e;
    }
    return 0;
}

//获取队头元素
int gethead(queue *q,int *e){
    *e=q->data[q->front];
    return 1;
}


int main()
{
    queue *q=initial();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    int e;
    printf("delete elem is:%d\n",dequeue(q));
    gethead(q,&e);
    printf("head elem is:%d\n",e);
    printf("delete elem is:%d\n",dequeue(q));
    gethead(q,&e);
    printf("head elem is:%d\n",e);
    return 0;
}