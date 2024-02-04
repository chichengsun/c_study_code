//采用二叉链表建立二叉树

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef char ElemType;
typedef struct Bnode{
    ElemType data;
    struct Bnode *lchild;//左孩子
    struct Bnode *rchild;//右孩子
}Bnode, *BiTree;

void CreateBTree_1(BiTree *B, char *str);
void CreateBTree_2(BiTree *B);
void PreOrderBnode_Recur(Bnode *B);
void PreOrderBnode_NotRecur(Bnode *B);
void InOrderBnode_Recur(Bnode *B);
void InOrderBnode_NotRecur(Bnode *B);
void PostOrderBnode_Recur(Bnode *B);
void PostOrderBnode_NotRecur(Bnode *B);
void LevelOrderBnode(Bnode *B);
void CopyBTree(Bnode *B, BiTree *BT);
int DeepBnode(Bnode *B);
int CountBnode(Bnode *B);

//创建二叉树
//例如A(B(D(,G)),C(E,F))换成二叉树如下：
//      A
//   B     C
// D     E   F
//   G 
void CreateBTree_1(BiTree *B, char *str)
{
    Bnode *St[100];
    BiTree p;
    int top = -1;
    int k = 0;
    while (*str != '\0'){
        //printf("%c(str)\n", *str);
        switch(*str){
            case '(':
                top ++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top --;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (Bnode *)malloc(sizeof(Bnode));
                p->data = *str;
                p->lchild = p->rchild = NULL;
                //printf("%c\n", p->data);
                if (*B == NULL){
                    *B = p;
                }else{
                    switch(k){
                        case 1:
                            St[top]->lchild = p;
                            //printf("%c(lift)\n", p->data);
                            break;
                        case 2:
                            St[top]->rchild = p;
                            //printf("%c(right)\n", p->data);
                            break;
                    } 
                }                     
        }
        str ++;
    }
}

//按照先序遍历的顺序建立二叉链表
void CreateBTree_2(BiTree *B)
{
    ElemType ch;
    printf("输入一个元素值：");
    scanf("%c", &ch);
    getchar();
    if (ch == '#'){
        *B = NULL;
    }else{
        (*B) = (Bnode *)malloc(sizeof(Bnode));
        (*B)->data = ch;
        CreateBTree_2(&((*B)->lchild));
        CreateBTree_2(&((*B)->rchild));
    }
}

//先序遍历递归输出二叉树
void PreOrderBnode_Recur(Bnode *B)
{
    if (B){
        printf("%c", B->data);
        PreOrderBnode_Recur(B->lchild);
        PreOrderBnode_Recur(B->rchild);
    }
}

//先序遍历非递归输出二叉树
void PreOrderBnode_NotRecur(Bnode *B)
{
    BiTree St[100];
    Bnode *p = B;
    int top = -1;
    while (p || top != -1){
        if (p){
            printf("%c", p->data);
            top ++;
            St[top] = p;
            p = p->lchild;
        }else{
            Bnode *q = St[top];
            p = q->rchild;
            top --;
        }
    }
}

//中序遍历递归输出二叉表
void InOrderBnode_Recur(Bnode *B)
{
    if (B){
        InOrderBnode_Recur(B->lchild);
        printf("%c", B->data);
        InOrderBnode_Recur(B->rchild);
    }
}

//中序遍历非递归输出二叉树
void InOrderBnode_NotRecur(Bnode *B)
{
    BiTree St[100];
    Bnode *p = B;
    int top = -1;
    while (p || top != -1){
        if (p){
            top ++;
            St[top] = p;
            p = p->lchild;
        }else{
            Bnode *q = St[top];
            printf("%c", q->data);
            p = q->rchild;
            top --;
        }
    }
}

//后序遍历递归输出二叉表
void PostOrderBnode_Recur(Bnode *B)
{
    if (B){
        PostOrderBnode_Recur(B->lchild);
        PostOrderBnode_Recur(B->rchild);
        printf("%c", B->data);
    }
}

//后序遍历非递归输出二叉表
void PostOrderBnode_NotRecur(Bnode *B)
{
    BiTree St[100];
    Bnode *p = B;
    Bnode *r = NULL;//记录上一个打印的结点
    int top = -1;
    while (p || top != -1){
        if (p){
            top ++;
            St[top] = p;
            p = p->lchild;
        }else{
            p = St[top];
            if (p->rchild && p->rchild != r){
                p = p->rchild;
            }else{
                printf("%c", St[top]->data);
                top --;
                r = p;
                p = NULL;
            }  
        }
    }
}

//层次遍历输出二叉表
void LevelOrderBnode(Bnode *B)
{
    BiTree St[100];
    int i = 0;
    int j = 0;
    St[0] = B;
    while (i <= j){
        printf("%c", St[i]->data);
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

//复制二叉树
void CopyBTree(Bnode *B, BiTree *BT)
{
    if (B == NULL){
        (*BT) = NULL;
        return;
    }else{
        (*BT) = (Bnode *)malloc(sizeof(Bnode));
        (*BT)->data = B->data;
        CopyBTree(B->lchild, &((*BT)->lchild));
        CopyBTree(B->rchild, &((*BT)->rchild));
    }
}

//递归计算二叉树的深度
int DeepBnode(Bnode *B)
{
    if (B == NULL){
        return 0;
    }else{
        int m = DeepBnode(B->lchild);
        int n = DeepBnode(B->rchild);
        if (m > n){
            return m + 1;
        }else{
            return n + 1;
        }
    }
}

//返回二叉树中结点的个数
int CountBnode(Bnode *B)
{
    if (B == NULL){
        return 0;
    }else{
        return CountBnode(B->lchild) + CountBnode(B->rchild) + 1;
    }
}

//返回二叉树中叶子结点的个数
int CountLeafBnode(Bnode *B)
{
    if (B == NULL){
        return 0;
    }if(B->lchild == NULL && B->rchild == NULL){
        return 1;
    }else{
        return CountLeafBnode(B->lchild) + CountLeafBnode(B->rchild);
    }
}