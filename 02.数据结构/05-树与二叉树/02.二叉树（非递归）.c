/*

其他跟递归遍历二叉树相同，区别在需要先创立一个栈，以及order部分不同（前序为例）：

void iterpreorder(stack *s,treenode *T){

    while(T!=NULL||!isEmpty(s)){

        while(T!=NULL){

            printf("%c ",T->data);
            push(s,T);
            T=T->lchild;

        }

        pop(s,&T);
        T=T->rchild;
        
    }
}

*/