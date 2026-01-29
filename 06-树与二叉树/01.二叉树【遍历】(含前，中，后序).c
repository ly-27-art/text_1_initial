//最后有二叉树图对照
#include <stdio.h>
#include <stdlib.h>


typedef struct treenode{
    char data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;


char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;


void createtree(treenode **T){

    char ch;
    ch=str[idx++];

    if(ch=='#'){
        *T=NULL;
    }
    else{

        *T=(treenode*)malloc(sizeof(treenode));
        (*T)->data=ch;  //优先级：'()' > '->' > '*' = '&'
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;

        createtree(&(*T)->lchild);//等价与：&((*T)->data)
        createtree(&(*T)->rchild);

    }
}

//前序遍历
void preorder(treenode *T){
    if(T==NULL){
        return ;
    }

    printf("%c ",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}//根-左-右  ！！！

//中序遍历
void inorder(treenode *T){
    if(T==NULL){
        return ;
    }

    inorder(T->lchild);
    printf("%c ",T->data);
    inorder(T->rchild);
}//左-根-右  ！！！

//后序遍历
void postorder(treenode *T){
    if(T==NULL){
        return ;
    }

    postorder(T->lchild);
    postorder(T->rchild);
    printf("%c ",T->data);
}//左-右-根  ！！！


int main()
{
    treenode *T;

    createtree(&T);

    printf("preorder:");
    preorder(T);
    printf("\n\n");

    printf("inorder:");
    inorder(T);
    printf("\n\n");

    printf("postorder:");
    postorder(T);

    return 0;
}



/*
                   A
                /     \
               B       C
             /   \   /   \
            D     E F     G
          /         /      \
         H         I        J
          \
           K
*/