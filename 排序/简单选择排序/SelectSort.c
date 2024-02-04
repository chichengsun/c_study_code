//简单选择排序

#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void SelectSort(int a[], int n)
{
    for (int i = 0;i < n - 1; i ++){
        int index = i;
        for (int j = i + 1; j < n; j ++){
            if (a[index] > a[j]){
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    SelectSort(a, 10);
    Print(a, 10);
    return 0;
}