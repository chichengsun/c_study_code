#include<stdio.h>
#include<stdlib.h>

#define ERROR 0 

typedef int ElemType;
typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void InsertBSTNode(BSTree *B, ElemType e);
void DeleteBSTNode(BSTree *B, ElemType e);
void CreateBSTNode_Input(BSTree *B);
void CreateBSTNode_Array(BSTree *B, ElemType array[], int n);
void InOrderBSTNode(BSTNode *B);

//二叉排序树的插入
void InsertBSTNode(BSTree *B, ElemType e)
{
    if (!(*B)){
        BSTNode *p = (BSTNode *)malloc(sizeof(BSTNode));
        p->data = e;
        p->lchild = NULL;
        p->rchild = NULL;
        (*B) = p;
    }else{
        if (e < (*B)->data){
            InsertBSTNode(&((*B)->lchild), e);
        }else if (e > (*B)->data){
            InsertBSTNode(&((*B)->rchild), e);
        }else{
            (*B)->data = e;
        }
    }
}

//二叉排序树的删除
void DeleteBSTNode(BSTree *B, ElemType e)
{
    BSTree p = (*B);
    BSTree f = NULL;
    while (p){
        if (p->data == e){
            break;
        }else if (p->data > e){
            f = p;
            p = p->lchild;
        }else{
            f = p;
            p = p->rchild;
        }
    }
    if (!p){
        return;
    }
    BSTree q = p;
    if (p->lchild && p->rchild){
        BSTree s = p->lchild;
        while (s->rchild){
            q = s;
            s = s->rchild;
        }
        p->data = s->data;
        if (q != p){
            q->rchild = s->lchild;
        }else{
            q->lchild = s->lchild;
        }
        free(s);
        return;
    }else if (!(p->lchild)){
        p = p->rchild;
    }else if (!(p->rchild)){
        p = p->lchild;
    }
    if (!f){
        (*B) = p;
    }else if (q == f->lchild){
        f->lchild = p;
    }else if (q == f->rchild){
        f->rchild = p;
    }
    free(q);
}

//二叉排序树的创建
void CreateBSTNode_Input(BSTree *B)
{
    ElemType c;
    printf("Please input a number(-1 exit):");
    scanf("%d", &c);
    while(c != ERROR){
        InsertBSTNode(B, c);
        printf("Please input a number(-1 exit):");
        scanf("%d", &c);
    }
}

//利用数组创建二叉排序树
void CreateBSTNode_Array(BSTree *B, ElemType array[], int n)
{
    for (int i = 0; i < n; i ++){
        InsertBSTNode(B, array[i]);
    }
}

//中序遍历输出二叉排序树
void InOrderBSTNode(BSTNode *B)
{
    if (B){
        InOrderBSTNode(B->lchild);
        printf("%d ", B->data);
        InOrderBSTNode(B->rchild);
    }
}

//层序遍历输出二叉排序树
void LevelOrderBSTNode(BSTNode *B)
{
    BSTree St[100];
    int i = 0;
    int j = 0;
    St[0] = B;
    while (i <= j){
        printf("%d ", St[i]->data);
        if (St[i]->lchild){
            j ++;
            St[j] = St[i]->lchild;
        }
        if (St[i]->rchild){
            j ++;
            St[j] = St[i]->rchild;
        }
        i ++;
    }
}