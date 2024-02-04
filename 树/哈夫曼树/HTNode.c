#include<stdio.h>
#include<stdlib.h>

typedef struct HTNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode, *HuffmanTree;

void InitHTNode(HTNode *H);
void SelectHuffmanTree(HTNode *H, int n, int *s1, int *s2);
void CreateHuffmanTree(HTNode *H, int n);
void DisplayHuffmanTree(HTNode *H, int n);
void CreateHuffmanCode(HTNode *H, int n, char string[][10]);

//初始化哈夫曼树
void InitHTNode(HTNode *H)
{
    H->weight = 0;
    H->parent = 0;
    H->lchild = 0;
    H->rchild = 0;
}

//返回结点数组中权值最小的两个结点下标
void SelectHuffmanTree(HTNode *H, int n, int *s1, int *s2)
{
    int index[100] = {0};
    int *p = index;
    //将叶子结点的下标一次装进index数组
    //printf("index数组：\n");
    for (int i = 1; i < n; i ++){
        if (H[i].parent == 0 && H[i].weight != 0){
            *p = i;
            //printf("%d\n", *p);
            p ++;
        }else{
            continue;
        }
    }
    //*s1存放最小weight下标，*s2存放第二小weight下标
    if (H[index[0]].weight <= H[index[1]].weight){
        *s1 = index[0];
        *s2 = index[1]; 
    }else{
        *s1 = index[1];
        *s2 = index[0];
    }
    //printf("一开始s1=%d,s2=%d\n", *s1, *s2);
    for (int i = 1; i < n; i ++){
        if (H[i].parent == 0 && H[i].weight != 0){
            if (H[i].weight < H[*s1].weight){
                *s2 = *s1;
                *s1 = i;
            }else if (H[i].weight < H[*s2].weight && H[i].weight >= H[*s1].weight && i != *s1){
                *s2 = i;
            }else{
                continue;
            }
        }else{
            continue;
        }
    }
}

//构造哈夫曼树
//n为权值结点个数，构造一个HTNode数组，从下标1开始到2n-1结束
void CreateHuffmanTree(HTNode *H, int n)
{
    for (int i = 1; i < 2 * n; i ++){
        InitHTNode(&H[i]);
    }
    for (int i = 1; i <= n; i ++){
        printf("Input a number:");
        scanf("%d",&(H[i].weight));
    }
    for (int i = n + 1; i < 2 * n; i ++){
        int s1, s2;
        SelectHuffmanTree(H, 2 * n, &s1, &s2);
        printf("%d->weight=%d %d->weight=%d\n", s1, H[s1].weight, s2, H[s2].weight);
        H[s1].parent = i;
        H[s2].parent = i;
        H[i].lchild = s1;
        H[i].rchild = s2;
        H[i].weight = H[s1].weight + H[s2].weight;
    } 
}

//打印哈夫曼树的终态表
void DisplayHuffmanTree(HTNode *H, int n)
{
    printf("nodei  weight  parent  lchild  rchild\n");
    for (int i = 1; i < 2 * n; i ++){
        printf("%5d  %6d  %6d  %6d  %6d\n", i, H[i].weight, H[i].parent, H[i].lchild, H[i].rchild);
    }
}

//根据哈夫曼树求解哈夫曼编码
void CreateHuffmanCode(HTNode *H, int n, char string[][10])
{
    for (int i = 1; i <= n; i ++){
        int start = 9;
        int c = i;
        int f = H[i].parent;
        while(f != 0){
            start --;
            if (H[f].lchild == c){
                string[i][start] = '0';
            }else{
                string[i][start] = '1';
            }
            c = f;
            f = H[f].parent;
        }
    }
}