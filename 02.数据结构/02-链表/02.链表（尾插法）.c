#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

//初始化
node *initial(){
    node *head=(node*)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
}

//获取尾节点
node* gettail(node *l){
    node *p=l;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}

//尾插法
node* inserttail(node *tail,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}

//插入节点
int insertnode(node *l,int posi,int e){
    //用来保存前驱节点
    node*p=l;
    int i=0;
    //遍历链表找到插入位置的前驱节点
    while(i<=posi-2){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    //要插入的新节点 
    node *q=(node*)malloc(sizeof(node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}

//删除节点
int deletenode(node *l,int posi){
    //要删除节点的前驱
    node *p=l;
    int i=0;
    while(i<=posi-2){
        p=p->next;
        i++;
        if(p->next==NULL){
            return 0;
        }
    }
    if(p->next==NULL){
        printf("要删除的位置错误\n");
        return 0;
    }

    node *q=p->next;   //p->next即要删除节点的首地址
    p->next=q->next;   //所以q->next是要删除节点下一个节点的首地址
    free(q);   //释放内存（删除节点）
    return 1;
}

//遍历
void listprint(node *l){
    node *p=l->next;
    if(l->next==NULL)return;
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
    tail=inserttail(tail,10);
    tail=inserttail(tail,20);
    tail=inserttail(tail,30);
    listprint(list);
    insertnode(list,2,15);
    listprint(list);
    deletenode(list,3);
    listprint(list);
    return 0;
}