#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
// void minmax(int a[], int len, int *min, int *max);
int main(void)
{	
	// int number;
	// scanf("%d", &number);
	// printf("%+d\n", 0 - number);
	printf("\"hello world%c??\"\n", '??)');
	printf("%d\n", 0x012);
	printf("%c\n", '??)');
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);
	printf("%d\n", UINT_MAX);
	printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MIN);
	return 0;

	// char input[20];
	// while(1)
	// {
	// 	int number = scanf("%s", input);
	// 	if (input[0] == '-' && input[1] == '1')
	// 	{
	// 		break;
	// 	}
	// 	int length = strlen(input);
	// 	printf("%d\n", length);
	// 	printf("%d\n", number);
	// }
	

	// int a = 1;
	// int b = 1;
	// printf("%p %p\n", &a, &b);
	// return 0;

	// int a = 1;
	// int b = 2;
	// int const *p1 = &a;//不能修改指针指向的值，可以修改指针的指向
	// int *const p2 = &b;//不能修改指针的指向，可以修改指针指向的值
	// printf("%d\n", *p1);
	// p1 = p2;
	// printf("%d\n", *p1);

	// printf("%d\n", *p2);
	// (*p2) ++;
	// printf("%d\n", *p2);
	// printf("%d\n", b);

	// printf("Hello World!\n");
	// return 0;

	// char ch[10] = "";
	// scanf("%c", &ch[5]);
	// getchar();
    // for (int i = 0; i < 10; i ++){
    //     printf("%c", ch[i]);
    // }
    // printf("\n");
	// printf("%5c\n", ch[5]);
	// char ch;
	// for (int i = 0; i < 3; i ++){
	// 	printf("Input value of vertex:");
    //     scanf("%c", &ch);
    //     getchar();
    //     printf("%5c\n", ch);
	// }
	// for (int i = 0; i < 3; i ++){
	// 	char v1, v2;
	// 	int weight;
    //     printf("Input two vertex and weight:");
	// 	scanf("%c %c %d", &v1, &v2, &weight);
	// 	getchar();
	// 	printf("%5c %5c %5d\n", v1, v2, weight);
	// }
	

	// char string[10] = "stringstr";
	// printf("%s\n", string);
	// char string[] = "string";
	// char *p = &string;
	// printf("%p\n", p);
    // char *ch[10] = {NULL};
    // char string[10] = "sunsheng";
    // ch[1] = string;
    // printf("%p\n", ch);
    // printf("%p\n", ch[0]);
    // printf("%p\n", ch[1]);

//	char ch[10] = "";
//	ch[8] = '1';
//	for (int i = 0; i < 10; i ++){
//		printf("%c", ch[i]);
//	}
//	printf("\n");

	// char *ch[4]= {NULL};
	// printf("%p\n", ch);
	// printf("%p\n", ch[0]);
	// printf("%p\n", ch[1]);
	// printf("%p\n", ch[2]);
	// printf("%p\n", ch[3]);
	// char string1[10] = "string111";
	// char string2[10] = "string222";
	// ch[0] = string1;
	// ch[1] = string2;
	// printf("%p\n", ch[0]);
	// printf("%p\n", ch[1]);
	// char **str = ch;
	// printf("%p\n", str);
	// printf("%p\n", *str);
	// **str = 'A';
	// **(str + 1) = 'B';
	// *(*(str + 1) + 1) = 'C';
	// printf("%s\n", *str);
	// printf("%s\n", *(str + 1));
	// printf("%c\n", *(*(str + 1) + 1));

	// int a = 8;
	// int b = 20;
	// int c;
	// scanf("%d", &c);
	// if (c < a){
	// 	printf("**\n");
	// }else if (c < b){
	// 	printf("##\n");
	// }else{
	// 	printf("!!\n");
	// }

	// char ch[20];
	// printf("Input a string:");
	// scanf("%s", ch);
	// getchar();

	// int i = 1;
	// while (i <= 20){
	// 	char c;
    //     printf("请输入第%d个元素值：", i);
	// 	scanf("%c", &c);
	// 	getchar();//读取多余的回车
	// 	printf("%c\n", c);
	// 	i ++;
    // }

	// char * p;
	// p = (char *)malloc(sizeof(char) * 8);
	// p[0] = 1;
	// printf("%d", p[0]);

	// int *a;
	// int cnt = 0;
	// while (a = malloc(100 * 1024 * 1024)){
	// 	cnt ++;
	// }
	// printf("分配了%d00M空间\n", cnt);
	// free(a);

	// int *a;
	// int number;
	// printf("input a number:");
	// scanf("%d", &number);
	// a = (int *)malloc(number * sizeof(int));
	// for (int i = 0; i < number; i++){
	// 	scanf("%d", &a[i]);
	// }
	// for (int i = number - 1; i >= 0; i--){
	// 	printf("%d", a[i]);
	// }
	// free(a);

	// double a[3] = {1.9, 2.9, 3.9};
	// double *p = a;
	// printf("p=%p\n", p);
	// printf("p+1=%p\n", p + 1);

	// int * const a;
	// *a = 1;
	// *(a + 1) = 0;
	// printf("a[1] = %d", a[1]);

	// int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int min, max;
	// minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
	// printf("min = %d, max = %d", min, max);

	return 0;
}

// void minmax(int a[], int len, int *min, int *max)
// {
// 	int i;
// 	*min = *max = a[0];
// 	for ( i = 1; i < len; i++){
// 		if ( a[i] < *min ){
// 			*min = a[i];
// 		}
// 		if ( a[i] > *max ){
// 			*max = a[i];
// 		}
// 	}
// }