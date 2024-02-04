#include<stdio.h>
#include<stdlib.h>
#include"Lnode.c"

//合并有序表
LnodeList MergeLnode_Order(Lnode *A, Lnode *B)
{
    LnodeList C;
    InitLnode(&C);
    Lnode *pa = A->next;
    Lnode *pb = B->next;
    int i = 1;
    while (pa && pb){
        if (pa->data < pb->data){         
            InsertLnode(C, i, pa->data);
            pa = pa->next;
        }else{
            InsertLnode(C, i, pb->data);
            pb = pb->next;
        }
        i ++;
    }
    while (pa){
        InsertLnode(C, i, pa->data);
        pa = pa->next;
        i ++;
    }
    while (pb){
        InsertLnode(C, i, pb->data);
        pb = pb->next;
        i ++;
    }
    DestroyLnode(pa);
    DestroyLnode(pb);
    return C;
}

int main(void)
{
    LnodeList A, B;
    printf("请按顺序输入A中的元素：\n");
    CreateLnode_R(&A, 4);
    printf("请按顺序输入B中的元素：\n");
    CreateLnode_R(&B, 7);
    printf("A中的元素为：\n");
    DisplayLnode(A);
    printf("B中的元素为：\n");
    DisplayLnode(B);
    LnodeList C = MergeLnode_Order(A, B);
    printf("合并有序表的结果为：\n");
    DisplayLnode(C);
    return 0;
}