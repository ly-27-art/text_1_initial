#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAX 0x7fffffff

/* ---------- 图的定义 ---------- */
typedef struct {
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} matrix_graph;

/* ---------- 边结构 ---------- */
typedef struct {
    int u;          // 起点下标
    int v;          // 终点下标
    int weight;     // 权值
} Edge;

/* ---------- 并查集 ---------- */
int parent[MAXSIZE];

int find(int x) {
    if (parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy){
        parent[fy] = fx;
    }
}

/* ---------- 创建图 ---------- */
void create_graph(matrix_graph *g) {
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

    for (int i = 0; i < g->vertex_num; i++) {
        for (int j = 0; j < g->vertex_num; j++) {
            if (i == j)
                g->arc[i][j] = 0;
            else
                g->arc[i][j] = MAX;
        }
    }

    g->arc[0][1] = 10;  // A-B
    g->arc[0][5] = 11;  // A-F

    g->arc[1][2] = 18;  // B-C
    g->arc[1][6] = 16;  // B-G
    g->arc[1][8] = 12;  // B-I

    g->arc[2][3] = 22;  // C-D
    g->arc[2][8] = 8;   // C-I

    g->arc[3][4] = 20;  // D-E
    g->arc[3][6] = 24;  // D-G
    g->arc[3][7] = 16;  // D-H
    g->arc[3][8] = 21;  // D-I

    g->arc[4][5] = 26;  // E-F
    g->arc[4][7] = 7;   // E-H

    g->arc[5][6] = 17;  // F-G
    g->arc[6][7] = 19;  // G-H

    /* 无向图，对称 */
    for (int i = 0; i < g->vertex_num; i++) {
        for (int j = 0; j < g->vertex_num; j++) {
            g->arc[j][i] = g->arc[i][j];
        }
    }
}

/* ---------- Kruskal 算法 ---------- */
void kruskal(matrix_graph *g) {
    Edge edges[MAXSIZE];
    int edge_count = 0;

    /* 1. 提取所有边 */
    for (int i = 0; i < g->vertex_num; i++) {
        for (int j = i + 1; j < g->vertex_num; j++) {
            if (g->arc[i][j] != 0 && g->arc[i][j] != MAX) {
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].weight = g->arc[i][j];
                edge_count++;
            }
        }
    }

    /* 2. 初始化并查集 */
    for (int i = 0; i < g->vertex_num; i++)
        parent[i] = i;

    /* 3. 按权值排序（冒泡排序） */
    for (int i = 0; i < edge_count - 1; i++) {
        for (int j = 0; j < edge_count - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    /* 4. 构造最小生成树 */
    int mst_edges = 0;
    printf("Kruskal 最小生成树：\n");

    for (int i = 0; i < edge_count && mst_edges < g->vertex_num - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            unite(u, v);
            printf("(%c,%c) 权值=%d\n",
                   g->vertex[u],
                   g->vertex[v],
                   edges[i].weight);
            mst_edges++;
        }
    }
}

/* ---------- 主函数 ---------- */
int main() {
    matrix_graph g;
    create_graph(&g);
    kruskal(&g);
    return 0;
}
