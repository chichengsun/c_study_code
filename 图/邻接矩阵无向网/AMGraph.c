#include<stdio.h>
#include<stdlib.h>

#define MaxInt 0 //表示极大值
#define MaxSize 10 //最大定点数
typedef struct{
    char vexs[MaxSize];//顶点表
    int arcs[MaxSize][MaxSize];//邻接矩阵
    int vertex_num;//当前顶点总数
    int edge_num;//当前边数
}AMGraph;

void InitAMGraph(AMGraph *G, int a, int b);
int LocateAMGraph(AMGraph *G, char v);
void CreateAMGraph(AMGraph *G);
void DisplayAMGraph(AMGraph *G);

//初始化无向网
void InitAMGraph(AMGraph *G, int a, int b)
{
    for (int i = 0; i < MaxSize; i ++){
        G->vexs[i] = '\0';
    }
    for (int i = 0; i < MaxSize; i ++){
        for (int j = 0; j < MaxSize; j ++){
            G->arcs[i][j] = MaxInt;
        }
    }
    for (int i = 0; i < MaxSize; i ++){
        for (int j = 0; j < MaxSize; j ++){
            printf("%5d", G->arcs[i][j]);
        }
        printf("\n");
    }
    G->vertex_num = a;
    G->edge_num = b;
}

//通过顶点的值找到下标
int LocateAMGraph(AMGraph *G, char v)
{
    for (int i = 0; i < G->vertex_num; i ++){
        if (G->vexs[i] == v){
            return i;
        }
    }
    return -1;
}

//创建无向网
void CreateAMGraph(AMGraph *G)
{
    for (int i = 0; i < G->vertex_num; i ++){
        printf("Input value of vertex:");
        scanf("%c", &(G->vexs[i]));
        getchar();
        printf("%5c\n", G->vexs[i]);  
    }
    for (int j = 0; j < G->edge_num; j ++){
        char v1, v2;
        int weight;
        printf("Input vertex and weight:");
        scanf("%c %c %d", &v1, &v2, &weight);
        getchar();
        printf("%5c %5c %5d\n", v1, v2, weight);
        int m = LocateAMGraph(G, v1);
        int n = LocateAMGraph(G, v2); 
        G->arcs[m][n] = weight;
        G->arcs[n][m] = G->arcs[m][n];
    }
}

//打印邻接矩阵
void DisplayAMGraph(AMGraph *G)
{
    printf("The adjacency matrix of graph:\n");
    printf("     ");
    for (int i = 0; i < G->vertex_num; i ++){
        printf("%5c", G->vexs[i]);
    }
    printf("\n");
    for (int i = 0; i < G->vertex_num; i ++){
        printf("%5c", G->vexs[i]);
        for (int j = 0; j < G->vertex_num; j ++){
            printf("%5d", G->arcs[i][j]);
        }
        printf("\n");
    }
}