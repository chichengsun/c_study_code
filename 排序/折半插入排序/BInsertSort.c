//折半插入排序

#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BInsertSort(int a[], int n)
{
    for (int i = 1; i < n; i ++){
        int temp = a[i];
        int low = 0, high = i - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (a[mid] < temp){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        int j = i - 1;
        for (j; j >= high + 1; j --){
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    BInsertSort(a, 10);
    Print(a, 10);
    return 0;
}