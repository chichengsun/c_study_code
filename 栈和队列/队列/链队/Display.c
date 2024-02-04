#include"Qnode.c"

int main(void)
{
    LinkQueue Q;
    ElemType e;
    InitQnode(&Q);
    printf("链队的长度为：%d\n", LengthQnode(&Q));
    EmptyQnode(&Q);
    EnQnode(&Q, 1);
    EnQnode(&Q, 2);
    EnQnode(&Q, 3);
    DisplayQnode(&Q);
    printf("链队的长度为：%d\n", LengthQnode(&Q));
    printf("链队的队头元素为：%d\n", GetQnode(&Q));
    DeQnode(&Q, &e);
    printf("出队一次链队的队头元素为：%d\n", GetQnode(&Q));
    DeQnode(&Q, &e);
    printf("出队两次链队的队头元素为：%d\n", GetQnode(&Q));
    DeQnode(&Q, &e);
    printf("出队三次链队的队头元素为：%d\n", GetQnode(&Q));
    return 0;
}