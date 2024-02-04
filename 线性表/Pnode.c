#include<stdio.h>
#include<stdlib.h>

typedef struct Pnode{
    int coef;// 系数
    int expn;// 指数
    struct Pnode *next;
}Pnode, *Polynomial;

//创建多项式
void CreatePnode(Polynomial *P, int n)
{
    //链表中按指数大小从小到大排列
    (*P) = (Pnode *)malloc(sizeof(Pnode));
    (*P)->next = NULL;
    for (int i = 0; i < n; i ++){
        Pnode *s = (Pnode *)malloc(sizeof(Pnode));
        Pnode *pre = *P;
        Pnode *q = (*P)->next;
        printf("请输入系数和指数（用空格隔开）：");
        scanf("%d %d", &(s->coef), &(s->expn));
        while (q && q->expn < s->expn ){
            pre = q;
            q = q->next;
        }//退出循环时，q指向比s中指数大的最小指数项，pre指向比s中指数小的最大指数项
        s->next = q;
        pre->next = s;
    }
}

// 多项式的相加
Polynomial AddPnode(Pnode *A, Pnode *B)
{
    Polynomial C = (Pnode *)malloc(sizeof(Pnode));
    C->next = NULL;
    Pnode *p = C;//p始终指向链表中最后一个元素
    Pnode *pa = A->next;
    Pnode *pb = B->next;
    while (pa && pb){
        if (pa->expn < pb->expn){
            Pnode *s = (Pnode *)malloc(sizeof(Pnode));
            s->coef = pa->coef;
            s->expn = pa->expn;
            s->next = p->next;
            p->next = s;
            p = p->next;
            pa = pa->next;
        }else if (pa->expn == pb->expn){
            Pnode *s = (Pnode *)malloc(sizeof(Pnode));
            s->coef = pa->coef + pb->coef;
            s->expn = pa->expn;
            if (s->coef == 0){
                pa = pa->next;
                pb = pb->next;
                break;
            }else{
                s->next = p->next;
                p->next = s;
                p = p->next;
                pa = pa->next;
                pb = pb->next;
            }
            
        }else{
            Pnode *s = (Pnode *)malloc(sizeof(Pnode));
            s->coef = pb->coef;
            s->expn = pb->expn;
            s->next = p->next;
            p->next = s;
            p = p->next;
            pb = pb->next;
        }
    }
    while (pa){
        Pnode *s = (Pnode *)malloc(sizeof(Pnode));
        s->coef = pa->coef;
        s->expn = pa->expn;
        s->next = p->next;
        p->next = s;
        p = p->next;
        pa = pa->next;
    }
    while (pb){
        Pnode *s = (Pnode *)malloc(sizeof(Pnode));
        s->coef = pb->coef;
        s->expn = pb->expn;
        s->next = p->next;
        p->next = s;
        p = p->next;
        pb = pb->next;
    }
    free(pa);
    free(pb);
    free(p);
    return C;
}

void DisplayPnode(Pnode *P)
{
    printf("系数   指数\n");
    Pnode *p = P->next;
    while(p){
        printf("%4d   %4d\n", p->coef, p->expn);
        p = p->next;
    }
    free(p);
}

int main(void)
{
    Polynomial A, B;
    printf("输入A：\n");
    CreatePnode(&A, 4);
    DisplayPnode(A);
    printf("输入B：\n");
    CreatePnode(&B, 3);
    DisplayPnode(B);
    Polynomial C = AddPnode(A, B);
    DisplayPnode(C);
}