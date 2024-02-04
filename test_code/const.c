#include<stdio.h>
#include<stdlib.h>
int main(void)
{	
	int a = 1;
	int b = 2;
	int const *p1 = &a;//不能修改指针指向的值，可以修改指针的指向
	int *const p2 = &b;//不能修改指针的指向，可以修改指针指向的值
	printf("%d\n", *p1);
	p1 = p2;
	printf("%d\n", *p1);

	printf("%d\n", *p2);
	(*p2) ++;
	printf("%d\n", *p2);
	printf("%d\n", b);
    return 0;
}