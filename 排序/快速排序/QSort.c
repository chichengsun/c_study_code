//快速排序

#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Partition(int a[], int low, int high)
{
    //升序
    int pivotkey = a[low];
    while (low < high){
        while(a[high] >= pivotkey && low < high){
            high --;
        }
        a[low] = a[high];
        while(a[low] <= pivotkey && low < high){
            low ++;
        }
        a[high] = a[low];
    }
    a[low] = pivotkey;
    return low;
}

void QSort(int a[], int low, int high)
{
    if (low < high){
        int pivotloc = Partition(a, low, high);
        QSort(a, low, pivotloc - 1);
        QSort(a, pivotloc + 1, high);
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    QSort(a, 0, 9);
    Print(a, 10);
    return 0;
}