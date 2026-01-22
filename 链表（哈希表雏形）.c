#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *initial(){
    node *head=(node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
}

node *gettail(node *l){
    node *p=l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

node *insertelem(node *tail,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

int listlen(node *l){
    node *p=l;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}
//(哈希表雏形)利用另一个数组记录是否出现过相同数（这道题是绝对值）
void removenode(node *l,int len){
    node *p=l;
    int index;//做数组下标
    int *q=(int*)malloc(sizeof(int)*(len+1));//记录数组（data当下标）
    for(int i=0;i<len+1;i++){
        *(q+i)=0;
    }
    while(p->next!=NULL){
        index=abs(p->next->data);
        if(*(q+index)==0){
            *(q+index)=1;
            p=p->next;
        }else{
            node *temp=p->next;
            p->next=temp->next;
            free(temp);
        }
    }
    free(q);//记得释放堆内存
}

void listprint(node *l){
    node *p=l->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    node *list=initial();
    node *tail=gettail(list);
    tail=insertelem(tail,21);
    tail=insertelem(tail,-15);
    tail=insertelem(tail,-15);
    tail=insertelem(tail,7);
    tail=insertelem(tail,15);
    listprint(list);
    removenode(list,listlen(list));
    listprint(list);
    return 0;
}