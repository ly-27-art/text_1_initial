#include <stdio.h>
#include <stdlib.h>

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
//反转链表
node *reverselist(node *l){
    node *first=NULL;   //关键步骤,first不能为任何一节点,必须为NULL,不然链表会循环
    node *second=l->next;
    node *third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    node *final=initial();
    final->next=first;   //加个头
    return final;
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
    tail=insertelem(tail,1);
    tail=insertelem(tail,2);
    tail=insertelem(tail,3);
    tail=insertelem(tail,4);
    tail=insertelem(tail,5);
    tail=insertelem(tail,6);
    listprint(list);
    node *listre=reverselist(list);
    listprint(listre);
    return 0;
}