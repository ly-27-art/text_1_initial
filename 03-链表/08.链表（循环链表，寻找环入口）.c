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
//找环入口的原理（带有计算环长）
node *findbegin1(node *l){
    node *fast=l;
    node *slow=l;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            node *p=fast;
            int cout=1;
            while(p->next!=slow){
                cout++;
                p=p->next;
            }
            fast=l;
            slow=l;
            for(int i=0;i<cout;i++){
                fast=fast->next;
            }
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}//原理是：链总长-环长=头结点到环入口距离
//最佳寻找环入口代码
node *findbegin2(node *l){
    node *fast=l;
    node *slow=l;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            fast=l;
            while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}


int main()
{
     node *list=initial();
    node *tail=gettail(list);
    tail=insertelem(tail,1);
    tail=insertelem(tail,2);
    tail=insertelem(tail,3);
    node *three=tail;
    tail=insertelem(tail,4);
    tail=insertelem(tail,5);
    tail=insertelem(tail,6);
    tail=insertelem(tail,7);
    tail=insertelem(tail,8);
    tail->next=three;
    node *p=findbegin1(list);
    node *q=findbegin2(list);
    printf("%d\n",p->data);
    printf("%d\n",q->data);
    return 0;
}