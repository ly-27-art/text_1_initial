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

node* insertnode(node *tail,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

int finddata(node *l,int k){
    node *fast=l->next;
    node *slow=l->next;
    for(int i=0;i<k;i++){
        if(fast==NULL){
            printf("k超出链表长度\n");
            return 0;
        }
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    printf("倒数第%d个节点的值为:%d\n",k,slow->data);
    return 1;
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
    tail=insertnode(tail,3);
    tail=insertnode(tail,6);
    tail=insertnode(tail,8);
    tail=insertnode(tail,10);
    tail=insertnode(tail,15);
    listprint(list);
    int k;
    scanf("%d",&k);
    finddata(list,k);
    return 0;
}