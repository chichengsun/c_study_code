#include<stdio.h>
#include"Queue.c"

int main(void)
{
    Squeue Q;
    ElemType e;
    InitSqueue(&Q);
    EmptySqueue(&Q);
    EnSqueue(&Q, 0);
    EnSqueue(&Q, 1);
    EnSqueue(&Q, 2);
    EnSqueue(&Q, 3);
    EnSqueue(&Q, 4); 
    printf("队头的元素值为：%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("一次出队之后，队头的元素值为：%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("两次出队之后，队头的元素值为：%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("三次出队之后，队头的元素值为：%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("四次出队之后，队头的元素值为：%d\n", GetSqueue(&Q));
    return 0;
}