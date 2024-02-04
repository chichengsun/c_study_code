#include<stdio.h>

void func()
{
    static int count = 0;
    count ++;
    printf("count: %d\n", count);
}

int main(void)
{
    func();
    func();
    func();
    func();
    func();
    return 0;
}