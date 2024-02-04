






                A->elem[j + 1] = temp;
                A->elem[j] = A->elem[j + 1];
                int temp = A->elem[j];
            *pc = *pa;
            *pc = *pb;
            //*pc ++ = *pa ++;
            C.length ++;
            C.length ++;
            if ( A->elem[j] > A->elem[j + 1] ){
            pa ++;
            pb ++;
            pc ++;
            pc ++;
            printf("%d ", *pc);
            printf("%d ", *pc);
            }
        *pc = *pa;
        *pc = *pb;
        C.length ++;
        C.length ++;
        for (int j = 0; j < GetLength(A) - 1 - i; j ++){
        if (*pa <= *pb){
        pa ++;
        pb ++;
        pc ++;
        pc ++;
        printf("%d ", *pb);
        printf("%d ", *pc);
        }
        }
        }else{
    // CreateSqlist(&A, 4);
    // CreateSqlist(&B, 3);
    // DisplaySqlist(&A);
    // DisplaySqlist(&B);
    // MergeSqlist(&A, &B);
    // printf("A表：\n");
    // printf("B表：\n");
    // printf("合并之后的A表：\n");
    // printf("请输入A中的元素\n");
    // printf("请输入B中的元素\n");
    // Sqlist A, B;
    //func();
    //冒泡
    //首先对于A，B中的元素进行排序
    C.elem = (ElemType *)malloc(sizeof(ElemType) * C_length);
    C.length = 0;
    CreateSqlist(&A, 4);
    CreateSqlist(&B, 7);
    DisplaySqlist(&C);
    DisplaySqlist(A);
    DisplaySqlist(B);
    for (int i = 0; i < GetLength(A); i ++){
    int *pa = A->elem;
    int *pa_last = A->elem + GetLength(A) - 1;
    int *pb = B->elem;
    int *pb_last = B->elem + GetLength(B) - 1;
    int *pc = C.elem;
    int C_length = GetLength(A) + GetLength(B);
    OrderSqlist(A);
    OrderSqlist(B);
    printf("有序表A为：\n");
    printf("有序表B为：\n");
    printf("有序表合并后的结果为：\n");
    printf("请输入A中的元素\n");
    printf("请输入B中的元素\n");
    return 0;
    return C;
    Sqlist A, B;
    Sqlist C = MergeSqlistOrder(&A, &B);
    Sqlist C;
    while (pa <= pa_last){
    while (pb <= pb_last){
    while(pa <= pa_last && pb <= pb_last){
    }
    }
    }
    }
#include"Sqlist.c"
#include<stdio.h>
#include<stdlib.h>
//             SqlistInsert(A, A_length + 1, e);
//         ElemType e = ' ';
//         GetSqlist(B, i + 1, &e);
//         if (LocateElem(A, e) == FALSE){
//         int A_length = GetLength(A);
//         }
//     // 取B中的元素值，如果在A中找不到，则添加进A
//     DestroySqlist(&L);
//     DisplaySqlist(&L);
//     DisplaySqlist(&L);
//     DisplaySqlist(&L);
//     DisplaySqlist(A);
//     ElemType e;
//     for (int i = 0; i < B_length; i ++){
//     GetSqlist(&L, 3, &e);
//     InitSqlist(&L);
//     int B_length = GetLength(B);
//     printf("d在线性表中的位置序号为：%d\n", LocateElem(&L, 'd'));
//     printf("第三个位置上的元素值为：%c\n", e);
//     printf("线性表中第六个位置的元素值为：%c\n", e);
//     printf("线性表的长度为：%d\n", GetLength(&L));
//     Sqlist L;
//     SqlistDelete(&L, 6, &e);
//     SqlistInsert(&L, 1, 'a');
//     SqlistInsert(&L, 2, 'b');
//     SqlistInsert(&L, 3, 'c');
//     SqlistInsert(&L, 4, '4');
//     SqlistInsert(&L, 4, 'd');
//     SqlistInsert(&L, 5, 'e');
//     SqlistInsert(&L, 6, 'f');
//     }
// void func(void)
// void MergeSqlist(Sqlist *A, Sqlist *B)
// {
// {
// }
// }
// 排序函数
//有序表的合并
int main(void)
Sqlist MergeSqlistOrder(Sqlist *A, Sqlist *B)
void OrderSqlist(Sqlist *A)
{
{
{
}
}
}