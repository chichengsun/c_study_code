#include<stdio.h>
#include<stdlib.h>
#include"Lnode.c"

//合并线性表
void MergeLnode(Lnode *A, Lnode *B)
{
    // 取B中的元素值，如果在A中找不到，则添加进A
    int B_length = LengthLnode(B);
    for (int i = 0; i < B_length; i ++){
        int A_length = LengthLnode(A);
        ElemType e = 0;
        GetLnode(B, i + 1, &e);
        if (LocateNumberLnode(A, e) == FALSE){
            InsertLnode(A, A_length + 1, e);
        }
    }
    DisplayLnode(A);
}

int main(void)
{
    LnodeList A, B;
    printf("请输入A中的元素\n");
    CreateLnode_R(&A, 4);
    printf("请输入B中的元素\n");
    CreateLnode_R(&B, 3);
    printf("A表：\n");
    DisplayLnode(A);
    printf("B表：\n");
    DisplayLnode(B);
    printf("合并之后的A表：\n");
    MergeLnode(A, B);
}