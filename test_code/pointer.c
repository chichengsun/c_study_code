#include<stdio.h>

void func(int **p)
{
    printf("%d\n", (**p));
    p = NULL;
}

int main(void)
{
    int a = 1;
    int *a1 = &a;
    int **a2 = &a1;
    func(a2);
    printf("%d\n", a);
    printf("%d\n", **a2);
    return 0;
}