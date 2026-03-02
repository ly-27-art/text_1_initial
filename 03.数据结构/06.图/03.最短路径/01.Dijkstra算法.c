#include <stdio.h>
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

typedef struct{
    int vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}matrix_graph;


void creategraph(matrix_graph *g){
    g->vertex_num = 9;
    g->edge_num = 16;

    for(int i = 0 ; i < g->vertex_num ; i++){
        g->vertex[i] = i;  //少个 V 在之后的输出中
    }

    for(int i = 0 ; i < g->vertex_num ; i++){
        for(int  j = 0 ; j < g->vertex_num ; j++){
            if(i == j){
                g->arc[i][j] = 0;
            }
            else{
                g->arc[i][j] = MAX;
            }
        }
    }


    g->arc[0][1] = 1;
    g->arc[0][2] = 5;

    g->arc[1][2] = 3;
    g->arc[1][3] = 7;
    g->arc[1][4] = 5;

    g->arc[2][4] = 1;
    g->arc[2][5] = 7;

    g->arc[3][4] = 2;
    g->arc[3][6] = 3;

    g->arc[4][5] = 3;
    g->arc[4][6] = 6;
    g->arc[4][7] = 9;

    g->arc[5][7] = 5;

    g->arc[6][7] = 2;
    g->arc[6][8] = 7;

    g->arc[7][8] = 4;
    
    for(int i = 0 ; i < g->vertex_num ; i++){
        for(int j = 0 ; j < g->vertex_num ; j++){
            g->arc[j][i] = g->arc[i][j];
        }
    };
}


int choose(int distance[],int found[],int vertex_num){
    int min = MAX;
    int minposition = -1;

    for(int i = 0 ; i < vertex_num ; i++){
        if(distance[i] < min && found[i] == 0){
            min =distance[i];
            minposition = i;
        }
    }

    return minposition;

}


void Dijkstra(matrix_graph g,int begin){

    int found[MAXSIZE];  //顶点是否走过

    int path[MAXSIZE];  //路径

    int distance[MAXSIZE];  //begin到达每一个顶点的距离
    //初始化
    for(int i = 0 ; i < g.vertex_num ; i++){
        found[i] = 0;
        path[i] = -1;
        distance[i] = g.arc[begin][i];
    }

    found[begin] = 1;
    distance[begin] = 0;

    int next;  //下一个要观察的顶点

    for(int i =1 ; i < g.vertex_num ; i++){
        next = choose(distance,found,g.vertex_num);
        //printf("%d",next);
        found[next] = 1;
        for(int j = 0 ; j < g.vertex_num ; j++){
            if(found[j] == 0){
                if(distance[next] + g.arc[next][j] < distance[j]){
                    distance[j] = distance[next] + g.arc[next][j];
                    path[j] = next;
                }
            }
        }
    }


    for(int i = 1 ; i < g.vertex_num ; i++){
        printf("V0 -> V%d : %d\n",i,distance[i]);

        int j = i;
        printf("V%d <- ",i);
        while(path[j] != -1){
            printf("V%d <- ",path[j]);
            j = path[j];
        }
        printf("V0\n\n");
    }
}


int main()
{
    matrix_graph g;
    creategraph(&g);
    int begin = 0;
    Dijkstra(g,begin);
    return 0;
}