#include <stdio.h>
#define MAXN 100


int parent[MAXN];  // 保存每个结点的父亲
int h[MAXN];  //保存每个树的高度

/* 初始化 */
void initial(int n){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
        h[i] = 1;
    }
}

/* 查询元素 x 属于哪个集合 */
int find(int x){
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);  //关键
    }
}

/* 合并两个元素所属集合（合并根结点） */
void Union(int x,int y){
    int rootx = find(x);
    int rooty = find(y);
    if(rootx != rooty){
        if(h[rootx] < h[rooty]){
            parent[rootx] = parent[rooty];
        }
        else if(h[rootx] > h[rooty]){
            parent[rooty] = parent[rootx];
        }
        else{
            parent[rootx] = parent[rooty];
            h[rooty]++;
        }
    }
}