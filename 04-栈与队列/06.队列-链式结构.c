#include <stdio.h>
#include <stdlib.h>

typedef struct queuenode{
    int data;
    struct queuenode *next;
}queuenode;

//队头，队尾
typedef struct{
    queuenode *front;
    queuenode *rear;
}queue;

//初始化
queue *initial(){
    queue *q=(queue*)malloc(sizeof(queue));
    queuenode *head=(queuenode*)malloc(sizeof(queuenode));
    head->data=0;
    head->next=NULL;
    q->front=head;
    q->rear=head;
    return q;
}

//判断队列是否为空
int isEmpty(queue *q){
    if(q->front==q->rear){
        return 1;
    }else{
        return 0;
    }
}

//入队
void enqueue(queue *q,int e){
    queuenode *p=(queuenode*)malloc(sizeof(queuenode));
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

//出队
int dequeue(queue *q,int *e){
    if(isEmpty(q)){
        printf("empty");
        return 0;
    }
    queuenode *p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==q->front){
        q->rear=q->front;
    }
    free(p);
    return 1;
}

//获取队头元素
int getfront(queue *q){
    if(isEmpty(q)){
        printf("empty");
        return 0;
    }
    return q->front->next->data;
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
    dequeue(q,&e);
    printf("dequeue:%d\n",e);
    dequeue(q,&e);
    printf("dequeue:%d\n",e);
    printf("list top is:%d",getfront(q));
    return 0;
}