#include"HTNode.c"

int main(void)
{
    int n;
    printf("Input a number of Node:");
    scanf("%d", &n);
    HTNode HT[2 * n];
    char string[n + 1][10];
    for (int i = 0; i < n + 1; i ++){
        for (int j = 0; j < 10; j ++){
            string[i][j] = '\0';
        }
    }
    CreateHuffmanTree(HT, n);
    DisplayHuffmanTree(HT, n);
    CreateHuffmanCode(HT, n, string);
    for (int i = 1; i <= n; i ++){
        printf("node %d:", i);
        for (int j = 0; j < 10; j ++){
            printf("%c", string[i][j]);
        }
        printf("\n");
    }
    return 0;
}