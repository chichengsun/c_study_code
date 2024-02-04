#include <stdio.h>

typedef struct Node {
    char c;
    int num;
}Node;

int main() {
    printf("%d\n", sizeof(Node));
    return 0;
}