// 类似二叉树的  前序遍历  ，可将图转化成二叉树看  ！！！
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100


typedef struct{
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}matrix_graph;

//记录是否重复
int visited[MAXSIZE] = {};

//创建矩阵
void create_graph(matrix_graph *g){
    g->vertex_num = 9;
    g->edge_num = 15;
    g->vertex[0] = 'A';
    g->vertex[1] = 'B';
    g->vertex[2] = 'C';
    g->vertex[3] = 'D';
    g->vertex[4] = 'E';
    g->vertex[5] = 'F';
    g->vertex[6] = 'G';
    g->vertex[7] = 'H';
    g->vertex[8] = 'I';

    for(int i = 0 ; i < g->vertex_num ; i++){
        for(int j = 0 ; j < g->vertex_num ; j++){
            g->arc[i][j] = 0;
        }
    }

    // A-B  A-F
    g->arc[0][1] = 1;
    g->arc[0][5] = 1;

    // B-C  B-G  B-I
    g->arc[1][2] = 1;
    g->arc[1][6] = 1;
    g->arc[1][8] = 1;

    // C-D  C-I
    g->arc[2][3] = 1;
    g->arc[2][8] = 1;

    // D-E  D-G  D-H  D-I
    g->arc[3][4] = 1;
    g->arc[3][6] = 1;
    g->arc[3][7] = 1;
    g->arc[3][8] = 1;

    // E-F E-H
    g->arc[4][5] = 1;
    g->arc[4][7] = 1;

    // F-G
    g->arc[5][6] = 1;

    // G-H
    g->arc[6][7] = 1;

    for(int i = 0 ; i < g->vertex_num ; i++){
        for(int j = 0 ; j < g->vertex_num ; j++){
            g->arc[j][i] = g->arc[i][j];
        }
    }
}

//深度优先遍历（deep first search）
void DFS(matrix_graph g,int i){

    visited[i] = 1;
    printf("%c ",g.vertex[i]);

    for(int j = 0 ; j < g.vertex_num ; j++){
        if(g.arc[i][j] == 1 && visited[j] == 0){
            DFS(g,j);
        }
    }
}


int main()
{
    matrix_graph g;
    create_graph(&g);
    DFS(g,0);  // 0 表示从 A 开始
    return 0;
}