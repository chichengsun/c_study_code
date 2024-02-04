//直接插入排序法 
#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertSort(int a[], int n)
{
    //非递减排序
    for (int i = 1; i < n; i ++){
        if (a[i] < a[i - 1]){
            int temp = a[i];
            int j = i - 1;
            for (j; j >= 0 && a[j] > temp; j --){
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    InsertSort(a, 10);
    Print(a, 10);
    return 0;
}