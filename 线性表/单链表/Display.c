#include<stdio.h>
#include<stdlib.h>
#include"Lnode.c"

void func(void)
{
    LnodeList L;
    InitLnode(&L);
    ElemType e;
    CreateLnode_R(&L, 5);
    DisplayLnode(L);
    printf("链表的长度为%d\n", LengthLnode(L));
    GetLnode(L, 3, &e);
    printf("链表中第3个位置的数据域为%d\n", e);
    Lnode *p = LocateLnode(L, e);
    printf("第三个位置的数据域为%d\n", p->data);
    printf("%d在链表中的位置序号为%d\n", e, LocateNumberLnode(L, e));
    InsertLnode(L, 4, 8);
    printf("链表的长度为%d\n", LengthLnode(L));
    DisplayLnode(L);
    DeleteLnode(L, 6);
    printf("链表的长度为%d\n", LengthLnode(L));
    DisplayLnode(L);
}

int main(void)
{
    func();
    return 0;
}