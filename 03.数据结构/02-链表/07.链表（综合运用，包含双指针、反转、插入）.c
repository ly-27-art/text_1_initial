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
//重整链表（让 1-2-3-4-5-6 变成 1-6-2-5-3-4 即 1-n-2-(n-1)-3-(n-2)-4-......）
void reorderlist(node *l){
    node *fast=l->next;
    node *slow=l;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    node *first=NULL;
    node *second=slow->next;
    slow->next=NULL;
    node*third;
    while(second!=NULL){
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    node *p1=l->next;
    node *q1=first;
    node *p2,*q2;
    while(p1!=NULL&&q1!=NULL){
        p2=p1->next;
        q2=q1->next;
        p1->next=q1;
        q1->next=p2;
        p1=p2;
        q1=q2;
    }
}

void listprint(node *l){
    node *p=l->next;
    while(p!=NULL){
        printf("%d",p->data);
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
    reorderlist(list);
    listprint(list);
    return 0;
}