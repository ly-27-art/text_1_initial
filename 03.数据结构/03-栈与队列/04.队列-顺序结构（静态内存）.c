#include <stdio.h>
#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int front;
    int rear;
}queue;

//初始化
void initial(queue *q){
    q->front=0;
    q->rear=0;
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

//队尾满了，调整队列
int queuefull(queue *q){
    if(q->front!=0){
        int step=q->front;
        for(int i=q->front;i<=q->rear;i++){
            q->data[i-step]=q->data[i];
        }
        q->front=0;
        q->rear-=step;
        return 1;
    }else{
        printf("really full");
        return 0;
    }
}

//入队
int enqueue(queue *q,int e){
    if(q->rear>=MAXSIZE){
        if(!queuefull(q)){
            return 0;
        }
    }
    q->data[q->rear]=e;
    q->rear++;
    return 1;
}

//获取队头元素
int gethead(queue *q,int *e){
    *e=q->data[q->front];
    return 1;
}

//出队
int dequeue(queue *q){
    int e=q->data[q->front];
    q->front++;
    return e;
}


int main()
{
    queue q;
    initial(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    int e;
    printf("delete elem is:%d\n",dequeue(&q));
    gethead(&q,&e);
    printf("head elem is:%d\n",e);
    printf("delete elem is:%d\n",dequeue(&q));
    gethead(&q,&e);
    printf("head elem is:%d\n",e);
    return 0;
}

