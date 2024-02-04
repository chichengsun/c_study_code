#include<stdio.h>
#include<stdlib.h>
#include"Stack.c"

int main()
{
    LinkStack L;
    InitStack(&L);
    printf("链栈的长度为：%d\n", LengthStack(L));
    PushStack(&L, 1);
    PushStack(&L, 2);
    PushStack(&L, 3);
    PushStack(&L, 4);
    PushStack(&L, 5);
    PushStack(&L, 6);
    DisplayStack(L);
    printf("链栈的长度为：%d\n", LengthStack(L));
    printf("栈顶的元素值为：%d\n", GetStack(L));
    PopStack(&L);
    printf("出栈之后......\n");
    printf("链栈的长度为：%d\n", LengthStack(L));
    printf("栈顶的元素值为：%d\n", GetStack(L));
    DisplayStack(L);
    DestroyStack(L);
    return 0;
}