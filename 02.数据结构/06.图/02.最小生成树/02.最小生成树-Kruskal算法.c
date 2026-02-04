#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff


typedef struct{
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}matrix_graph;


typedef struct{
    int begin;
    int end;
    int weight;  //权重
}edge;


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
            if(i == j){
                g->arc[i][j] = 0;
            }
            else{
                g->arc[i][j] = MAX;
            }
        }
    }

    // A-B  A-F
    g->arc[0][1] = 10;
    g->arc[0][5] = 11;

    // B-C  B-G  B-I
    g->arc[1][2] = 18;
    g->arc[1][6] = 16;
    g->arc[1][8] = 12;

    // C-D  C-I
    g->arc[2][3] = 22;
    g->arc[2][8] = 8;

    // D-E  D-G  D-H  D-I
    g->arc[3][4] = 20;
    g->arc[3][6] = 24;
    g->arc[3][7] = 16;
    g->arc[3][8] = 21;

    // E-F E-H
    g->arc[4][5] = 26;
    g->arc[4][7] = 7;

    // F-G
    g->arc[5][6] = 17;

    // G-H
    g->arc[6][7] = 19;

    for(int i = 0 ; i < g->vertex_num ; i++){
        for(int j = 0 ; j < g->vertex_num ; j++){
            g->arc[j][i] = g->arc[i][j];
        }
    }
}

//按权重对边排序
void sortedges(edge edges[],int edge_num){
    for(int i = 0 ; i < edge_num - 1 ; i++){
        for(int j = 0 ; j < edge_num - 1 - i ; j++){
            if(edges[j].weight > edges[j + 1].weight){
            edge temp = edges[j];
            edges[j] = edges[j + 1];
            edges[j + 1] = temp;
            }
        }
    }
}

//类并查集，查找
int find(int parent[],int index){
    while(parent[index] > 0){
        index = parent[index];  //找到对应的根
    }
    return index;
}


void kruskal(matrix_graph g){

    edge edges[MAXSIZE];
    int k = 0;

    for(int i = 0 ; i < g.vertex_num ; i++){
        for(int j = i + 1 ; j < g.vertex_num ; j++){
            if(g.arc[i][j] < MAX){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = g.arc[i][j];
                k++;
            }
        }
    }

    sortedges(edges,g.edge_num);

    int parent[MAXSIZE];  //伪并查集

    for(int i = 0 ; i < g.edge_num ; i++){
        parent[i] = 0;
    }

    int n,m;
    for(int i = 0 ; i < g.edge_num ; i++){
        n = find(parent,edges[i].begin);
        m = find(parent,edges[i].end);

        if(n != m){
            parent[n] = m;  //相当于 union
            printf("(%c,%c) weight:%d\n",g.vertex[edges[i].begin],g.vertex[edges[i].end],edges[i].weight);
        }
    }
}


int main()
{
    matrix_graph g;
    create_graph(&g);
    kruskal(g);
    return 0;
}