#include"AMGraph.c"

int main(void)
{
    AMGraph G;
    InitAMGraph(&G, 3, 2);
    for (int i = 0; i < G.vertex_num; i ++){
        printf("Input value of vertex:");
        scanf("%c", &(G.vexs[i]));
        getchar();
        printf("%5c\n", G.vexs[i]);
    }
    // CreateAMGraph(&G);
    // DisplayAMGraph(&G);
    for (int j = 0; j < G.edge_num; j ++){
        char v1, v2;
        int weight;
        printf("Input two vertex and weight:");
        scanf("%c %c %d", &v1, &v2, &weight);
        getchar();
        printf("%5c %5c %5d\n", v1, v2, weight);
        G.arcs[LocateAMGraph(&G, v1)][LocateAMGraph(&G, v2)] = weight;
        G.arcs[LocateAMGraph(&G, v2)][LocateAMGraph(&G, v1)] = G.arcs[LocateAMGraph(&G, v1)][LocateAMGraph(&G, v2)];
    }

    printf("     ");
    for (int i = 0; i < G.vertex_num; i ++){
        printf("%5c", G.vexs[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vertex_num; i ++){
        printf("%5c", G.vexs[i]);
        for (int j = 0; j < G.vertex_num; j ++){
            printf("%5d", G.arcs[i][j]);
        }
        printf("\n");
    }

    return 0;
}