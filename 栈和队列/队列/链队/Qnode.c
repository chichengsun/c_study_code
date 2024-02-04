#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Qnode{
    ElemType data;
    struct Qnode *next;
}Qnode, *QueuePtr;
typedef struct{
    QueuePtr front;//队头指针
    QueuePtr rear;//队尾指针
}LinkQueue;

void InitQnode(LinkQueue *Q);
void DisplayQnode(LinkQueue *Q);
void DestroyQnode(LinkQueue *Q);
int EmptyQnode(LinkQueue *Q);
ElemType GetQnode(LinkQueue *Q);
int LengthQnode(LinkQueue *Q);
void EnQnode(LinkQueue *Q, ElemType e);
void DeQnode(LinkQueue *Q, ElemType *e);

//链队的初始化
void InitQnode(LinkQueue *Q)
{
    //起始front和rear都指向头结点
    Q->front = Q->rear = (Qnode *)malloc(sizeof(Qnode));
    Q->front->next = NULL; 
}

//输出链队的元素
void DisplayQnode(LinkQueue *Q)
{
    Qnode *p = Q->front->next;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//销毁链队
void DestroyQnode(LinkQueue *Q)
{
    //从头结点开始，依次销毁后续结点
    while (Q->front){
        Qnode *p = Q->front;
        Q->front = Q->front->next;
        free(p);
    }
}

//链队是否为空
int EmptyQnode(LinkQueue *Q)
{
    if (Q->front == Q->rear){
        printf("链队为空！（Empty）\n");
        return TRUE;
    }else{
        printf("链队不为空！（Empty）\n");
        return FALSE;
    }
}

//链队的长度
int LengthQnode(LinkQueue *Q)
{
    int count = 0;
    Qnode *p = Q->front->next;
    while(p){
        count ++;
        p = p->next;
    }
    return count;
}

//获取链队的队头元素值
ElemType GetQnode(LinkQueue *Q)
{
    if (EmptyQnode(Q) == FALSE){
        return Q->front->next->data;
    }else{
        printf("链队为空！（Get）\n");
        return FALSE;
    }
}

//链队的入队
void EnQnode(LinkQueue *Q, ElemType e)
{
    Qnode *p = (Qnode *)malloc(sizeof(Qnode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

//链队的出队
void DeQnode(LinkQueue *Q, ElemType *e)
{
    if (EmptyQnode(Q) == TRUE){
        printf("链队为空！（De）\n");
    }else{
        Qnode *p = Q->front->next;
        *e = p->data;
        Q->front->next = p->next;
        if (Q->rear == p){
            //出队的为最后的一个元素
            Q->rear = Q->front;
        }
        free(p);
    }
}