#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000


typedef struct{
    int *data;
    int len;
}list;

//初始化（二级malloc）
list* initial(){
    list *l=(list *)malloc(sizeof(list));
    l->data=(int *)malloc(sizeof(int)*MAXSIZE);
    l->len=0;
    return l;
}

//添加数据
int append(list *l,int e){
    if(l->len>=1000){
        printf("顺序表已经满了\n");
        return 0;
    }
    l->data[l->len]=e;
    l->len++;
    return 1;
}

//遍历此时表中全部数据
void listprint(list *l){
    for(int i=0;i<l->len;i++){
        printf("%d ",l->data[i]);
    }
    printf("\n");
}

//插入数据
int insertelem(list *l,int posi,int e){
    if(posi<=l->len){
        for(int i=l->len;i>posi-1;i--){
            l->data[i+1]=l->data[i];
        }
        l->data[posi-1]=e;
        l->len++;
    }
    return 1;
}

//删除数据
int deleteelem(list *l,int posi,int *e){
    *e=l->data[posi-1];
    if(posi<l->len){
        for(int i=posi;i<l->len;i++){
            l->data[i-1]=l->data[i];
        }
        l->len--;
        return 0;
    }
    return 1;
}

//寻找数据位置
int findelem(list *l,int e){
    for(int i=0;i<l->len;i++){
        if(l->data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//释放内存
void destroy(list *l){
    if(l!=NULL){
    free(l->data);
    free(l);
    }
}


int main()
{
    list *p=initial();
    append(p,88);
    append(p,76);
    append(p,0);
    append(p,6);
    append(p,13);
    listprint(p);
    insertelem(p,2,1);
    listprint(p);
    int delete;
    deleteelem(p,3,&delete);
    listprint(p);
    printf("delete:%d\n",delete);
    printf("%d\n",findelem(p,6));
    destroy(p);
    return 0;
}