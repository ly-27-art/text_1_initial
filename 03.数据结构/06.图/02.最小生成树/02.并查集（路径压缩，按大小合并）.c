#include <stdio.h>
#define MAXN 100


int parent[MAXN];  // 保存每个结点的父亲
int s[MAXN];  // 保存每个树的结点数

/* 初始化 */
void initial(int n){  // n 为元素个数
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
        s[i] = 1;
    }
}

/* 查询元素 x 属于哪个集合 */
int find(int x){
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = find(parent[x]);  //关键（路径压缩）
    }
}

/* 合并两个元素所属集合（合并根结点） */
void Union(int x,int y){
    int rootx = find(x);
    int rooty = find(y);
    if(rootx != rooty){
        if(s[rootx] < s[rooty]){
            parent[rootx] = rooty;  //按大小合并
            s[rooty] += s[rootx];
        }
        else{
            parent[rooty] = rootx;
            s[rootx] += s[rooty];
        }
    }
}