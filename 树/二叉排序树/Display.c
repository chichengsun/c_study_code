#include"BSTNode.c"

int main(void)
{
    BSTree B = NULL;
    int a[] = {45, 24, 53, 45, 2, 24, 90};
    CreateBSTNode_Array(&B, a, 7);
    //CreateBSTNode_Input(&B);
    InOrderBSTNode(B);
    printf("\n");
    LevelOrderBSTNode(B);
    printf("\n");
    DeleteBSTNode(&B, 53);
    InOrderBSTNode(B);
    printf("\n");
    LevelOrderBSTNode(B);
    printf("\n");
    return 0;
}