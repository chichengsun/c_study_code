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
    printf("��ͷ��Ԫ��ֵΪ��%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("һ�γ���֮�󣬶�ͷ��Ԫ��ֵΪ��%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("���γ���֮�󣬶�ͷ��Ԫ��ֵΪ��%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("���γ���֮�󣬶�ͷ��Ԫ��ֵΪ��%d\n", GetSqueue(&Q));
    DeSqueue(&Q, &e);
    printf("�Ĵγ���֮�󣬶�ͷ��Ԫ��ֵΪ��%d\n", GetSqueue(&Q));
    return 0;
}