#include<stdio.h>

int Search_Seq(int a[], int n, int e)
{
    //返回下标
    for (int i = 0; i < n; i ++){
        if (a[i] == e){
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int result = Search_Seq(a, 5, 3);
    if (result == -1){
        printf("No Search!\n");
    }else{
        printf("Search Succssfully! index=%d\n", result);
    }
}