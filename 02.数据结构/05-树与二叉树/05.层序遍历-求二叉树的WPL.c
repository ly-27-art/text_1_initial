#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef struct treenode{
    int data_w;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;


int idx = 0;
int weigth[] = {100,42,15,-1,-1,27,-1,-1,58,28,13,5,-1,-1,8,-1,-1,15,-1,-1,30,-1,-1};
//-1表示空

void createtree(treenode **T){
    int ch;
    ch = weigth[idx++];

    if(ch == -1){
        *T = NULL;
    }
    else{
        *T = (treenode*)malloc(sizeof(treenode));
        (*T)->data_w = ch;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;

        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}


int WPL(treenode *T){

    if(T == NULL){
        return 0;
    }

    treenode **queue;  //创建队列
    queue = (treenode**)malloc(sizeof(treenode*)*MAXSIZE);
    int front = 0;
    int rear = 0;

    int wpl = 0;
    int depth = 0;

    queue[rear] = T;
    rear++;

    while(rear != front){

        int count = rear - front;

        while(count > 0){

            treenode *curr = queue[front];
            front++;

            if(curr->lchild == NULL && curr->rchild == NULL){
                wpl += depth * curr->data_w;  //只有叶结点参与权重计算
            }

            if(curr->lchild != NULL){
                queue[rear] = curr->lchild;
                rear++;
            }

            if(curr->rchild != NULL){
                queue[rear] = curr->rchild;
                rear++;
            }

            count--;
        }

        depth++;

    }

    return wpl;

}


int main()
{
    treenode *T;
    createtree(&T);
    printf("%d",WPL(T));
    return 0;
}


/*
                   100
                /      \
               42       58
             /   \    /   \
           15    27  28    30
                    /  \
                  13    15
                 /  \
               5     8 

               WPL = 241
*/