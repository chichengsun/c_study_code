#include<stdio.h>
#include<stdlib.h>
#include"Stack.c"

int main(void)
{
    Stack S;
    InitStack(&S);
    printf("%p %p\n", S.top, S.base);
    printf("栈的长度为：%d\n", LengthStack(&S));
    PushStack(&S, 1);
    PushStack(&S, 2);
    PushStack(&S, 3);
    PushStack(&S, 4);
    PushStack(&S, 5);
    printf("栈的长度为：%d\n", LengthStack(&S));
    DisplayStack(&S);
    printf("栈顶的元素值为：%d\n", GetStack(&S));
    PopStack(&S);
    printf("栈的长度为：%d\n", LengthStack(&S));
    printf("栈顶的元素值为：%d\n", GetStack(&S));
    DisplayStack(&S);
    DestroyStack(&S);
    return 0;
}