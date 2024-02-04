#include"BiTree.c"

int main(void)
{
    BiTree B = NULL;
    BiTree BT = NULL;
    // char string[] = "A(B(D(,G)),C(E,F))";
    // CreateBTree_1(&B, string);
    // CopyBTree(B, &BT);
    //ABC##DE#G##F###
    //ABC###C#F##
    //你把红豆赠我，不如送我一首歌
    CreateBTree_2(&B);

    printf("PreOrder(Recur):");
    PreOrderBnode_Recur(B);
    printf("\n");

    printf("PreOrder(NotRecur):");
    PreOrderBnode_NotRecur(B);
    printf("\n");

    printf("InOrder(Recur):");
    InOrderBnode_Recur(B);
    printf("\n");

    printf("InOrder(NotRecur):");
    InOrderBnode_NotRecur(B);
    printf("\n");

    printf("PostOrder(Recur):");
    PostOrderBnode_Recur(B);
    printf("\n");

    printf("PostOrder(NotRecur):");
    PostOrderBnode_NotRecur(B);
    printf("\n");

    printf("LevelOrder:");
    LevelOrderBnode(B);
    printf("\n");

    printf("二叉树B的深度为：%d\n", DeepBnode(B));
    printf("二叉树中结点的总个数为：%d\n", CountBnode(B));
    printf("二叉树中叶子结点的个数为：%d\n", CountLeafBnode(B));
    return 0;
}