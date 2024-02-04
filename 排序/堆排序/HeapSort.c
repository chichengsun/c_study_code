//堆排序

#include<stdio.h>

void Print(int a[], int n)
{
    for (int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void HeapAdjust(int a[], int s, int n)
{
    int temp = a[s - 1];
    for (int j = 2 * s; j <= n; j *= 2){
        if (j < n && a[j - 1] < a[j]){
            j ++;
        }
        if (temp > a[j - 1]){
            break;
        }
        a[s] = a[j - 1];
        s = j;
    }
    a[s - 1] = temp;
}

void CreateHeap(int a[], int n)
{
    for (int i = n / 2; i > 0; i --){
        HeapAdjust(a, i, n);
    }
}

void HeapSort(int a[], int n)
{
    CreateHeap(a, n);
    for (int i = n; i > 1; i --){
        int x = a[0];
        a[0] = a[n - 1];
        a[n - 1] = x;
        HeapAdjust(a, 1, i - 1);
    }
}

int main(void)
{
    int a[] = {49, 38, 65, 97, 65, 13, 27, 49, 55, 4};
    Print(a, 10);
    HeapSort(a, 10);
    Print(a, 10);
    return 0;
}