#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    char data;
    struct node *next;
}node;

node *initial(){
    node *head=(node*)malloc(sizeof(node));
    head->data='0';
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

node *insertelem(node *tail,char e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

int listlen(node *l){
    node *p=l->next;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

char findcommend(node* list1,node*list2){
    int step=abs(listlen(list1)-listlen(list2));
    node *fast,*slow;
    if(listlen(list1)>listlen(list2)){
            fast=list1->next;
            slow=list2->next;
    }else{
            fast=list2->next;
            slow=list1->next;
    }
    for(int i=0;i<step;i++){
        fast=fast->next;
    }
    //注意，判断的是相同后缀的首字母，一定要是地址相同的时候才停止，不然不同后缀但相同字母也会停！！！！
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return fast->data;
}

node *newnode(char e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=NULL;
    return p;
}

int main()
{
    node *i=newnode('i');
    node *n=newnode('n');
    node *g=newnode('g');
    i->next=n;
    n->next=g;
    node *list1=initial();
    node *list2=initial();
    node *tail1=gettail(list1);
    tail1=insertelem(tail1,'l');
    tail1=insertelem(tail1,'o');
    tail1=insertelem(tail1,'a');
    tail1=insertelem(tail1,'d');
    tail1->next=i;
    node *tail2=gettail(list2);
    tail2=insertelem(tail2,'b');
    tail2=insertelem(tail2,'e');
    tail2->next=i;
    printf("%c",findcommend(list1,list2));
    return 0;
}