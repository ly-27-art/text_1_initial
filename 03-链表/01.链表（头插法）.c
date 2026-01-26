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

//头插法
int inserthead(node *l,int e){
    node *p=(node*)malloc(sizeof(node));
    p->data=e;
    p->next=l->next;
    l->next=p;
    return 1;
}

//插入节点
int insertnode(node *l,int posi,int e){
    //用来保存前驱节点
    node *p=l;
    int i=0;
    //遍历链表找到插入位置的前驱节点
    while(i<=posi-2){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    node *q=(node*)malloc(sizeof(node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}

//删除节点
int deletenode(node *l,int posi){
    //用来保存前驱节点
    node *p=l;
    int i=0;
    //遍历链表找到插入位置的前驱节点
    while(i<=posi-2){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    node *q=p->next;//p->next即要删除节点的首地址
    p->next=q->next;//所以q->next是要删除节点下一个节点的首地址
    free(q);//释放内存（删除节点）
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

//获取链表长度
int listlen(node *l){
    node *p=l->next;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

//释放链表
void freelist(node *l){
    node *p=l->next;
    node *q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    l->next=NULL;
}

int main()
{
    node *list=initial();
    inserthead(list,10);
    inserthead(list,20);
    inserthead(list,30);
    listprint(list);
    insertnode(list,3,15);
    listprint(list);
    deletenode(list,2);
    listprint(list);
    printf("%d\n",listlen(list));
    freelist(list);
    printf("%d",listlen(list));
    return 0;
}
