#include<stdio.h>

void Ascend_sort(int a[], int n)
{
    //使用冒泡排序
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

int Search_Bin(int a[], int n, int e)
{
    int low = 1;
    int high = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (a[mid - 1] == e){
            return mid - 1;
        }else if (a[mid - 1] < e){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int a[] = {24, 9, 20, 5, 67};
    Ascend_sort(a, 5);
    for (int i = 0; i < sizeof(a) / sizeof(int) ; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int result = Search_Bin(a, 5, 20);
    if (result == -1){
        printf("No Search!\n");
    }else{
        printf("Search Succssfully! index=%d\n", result);
    }
}