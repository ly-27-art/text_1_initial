//最后有二叉树图对照
//中序的线索二叉树
#include <stdio.h>
#include <stdlib.h>

typedef struct threadnode{
    char data;
    struct threadnode *lchild;
    struct threadnode *rchild;
    int ltag;   //0表示有子树，1表示线索
    int rtag;
}threadnode;   //ltag为 0 指前驱 ， rtag为 0 指后继

typedef threadnode* threadtree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

threadtree prev;

//创建树(前序)
void createtree(threadtree *T){  //用二级指针是为减少特判，直接修改节点（指针）
    char ch;
    ch = str[idx++];
    if(ch=='#'){
        *T = NULL;
    }
    else{
        *T = (threadtree)malloc(sizeof(threadnode));
        (*T)->data = ch;

        createtree(&(*T)->lchild);
        if((*T)->lchild != NULL){
            (*T)->ltag = 0;
        }

        createtree(&(*T)->rchild);
        if((*T)->rchild != NULL){
            (*T)->rtag = 0;
        }

    }
}

//具体线索化
void threading(threadtree T){
    if(T != NULL){

        threading(T->lchild);

        if(T->lchild == NULL){  //前驱
            T->ltag = 1;
            T->lchild = prev;
        }
                                  //中序遍历所以建立线索在中间
        if(prev->rchild == NULL){
            prev->rtag = 1;
            prev->rchild = T;  
        }                       //后继

        prev = T;   //标记当前节点为前驱
        threading(T->rchild);
    }
}

//开始线索化
void inorderthread(threadtree *head,threadtree T){
    //头结点
    *head = (threadtree)malloc(sizeof(threadnode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->lchild = *head;

    if(T == NULL){
        (*head)->lchild = *head;
    }
    else{
        (*head)->lchild = T;
        prev = (*head);   //开始时头节点为前驱

        threading(T);   //建立线索

        //最后一个节点线索化
        prev->rchild = *head;
        prev->rtag = 1;

        //头结点右孩子指向最后一个节点（非必须的，是为代码对称性与完整性，方便之后操作）
        (*head)->rchild = prev;
    }
}

//使用线索进行中序遍历
void inorder(threadtree head){
    threadtree curr;
    curr = head->lchild;

    while(curr != head){
        while(curr->ltag == 0){
            curr = curr->lchild;   //最左下角是最先输出的
        }

        printf("%c ",curr->data);
    //根据线索路线遍历节点
        while(curr->rtag == 1 && curr->rchild != head){
            curr = curr->rchild;
            printf("%c ",curr->data);
        }
        curr = curr->rchild;   //实际是继续遍历第一节点的右子树
    }
    printf("\n");
}


int main()
{
    threadtree head;
    threadtree T;
    //创建
    createtree(&T);
    //线索化
    inorderthread(&head,T);
    //基于线索遍历
    inorder(head);

    return 0;
}


/*
                   A
                /      \
               B        C
             /   \    /   \
            D     E  F     G
          /   \    \      
         H     I    J        
*/