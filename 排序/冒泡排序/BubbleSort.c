//冒泡排序

#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BubbleSort(int a[], int n)
{
    //升序
    int flag = 1;
    for (int i = 0; i < n - 1 && flag == 1; i ++){
        flag = 0;
        for (int j = 0; j < n - i - 1; j ++){
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    BubbleSort(a, 10);
    Print(a, 10);
    return 0;
}