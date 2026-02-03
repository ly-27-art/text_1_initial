#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef struct treenode{
    char data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;


typedef struct{
    treenode **data;   //存的是节点地址
    int front;
    int rear;
}queue;


char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;


void createtree(treenode **T){
    char ch;
    ch = str[idx++];
    if(ch == '#'){
        *T = NULL;
    }
    else{
        *T = (treenode*)malloc(sizeof(treenode));
        (*T)->data = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;

        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}


queue *initial(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->data = (treenode**)malloc(sizeof(treenode*)*MAXSIZE);//注意data类型是treenode*
    q->front = 0;
    q->rear = 0;
    return q;
}


int isEmpty(queue *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}


int enqueue(queue *q,treenode *e){
    if(q->rear == MAXSIZE-1){
        printf("full");
        return 0;
    }
    q->data[q->rear] = e;
    q->rear++;
    return 1;
}


int dequeue(queue *q,treenode **e){
    if(isEmpty(q)){
        printf("empty");
        return 0;
    }
    *e = q->data[q->front];
    q->front++;
    return 1;
}

//判断队列中元素的数量
int queuesize(queue *q){
    if(!isEmpty(q)){
        return q->rear - q->front;
    }
    else{
        return 0;
    }
}

//判断层数
int maxdepth(treenode *T){
    if(T == NULL){
        return 0;
    }

    queue *q = initial();   //创建队列
    enqueue(q,T);  //将第一个节点压入队列
    int depth = 0;

    while(!isEmpty(q)){
        int count = queuesize(q);  //用来记录一层中的节点是否全部出栈（count是节点数）
    while(count > 0){
        treenode *curr;  //获取当前出队节点，以让其左右孩子入队
        dequeue(q,&curr);
        if(curr->lchild != NULL){
            enqueue(q,curr->lchild);
        }
        if(curr->rchild != NULL){
            enqueue(q,curr->rchild);
        }
        count--;
    }
    depth++;
    }
    return depth;
}


int main()
{
    treenode *T;
    createtree(&T);
    printf("%d",maxdepth(T));
    return 0;
}


/*
                   A
                /      \
               B        C
             /   \    /   \
            D     E  F     G
          /         /       \
         H         I         J
          \
           K
*/