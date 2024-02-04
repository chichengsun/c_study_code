#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Squeue{
    ElemType *base;
    int front;
    int rear;
}Squeue;

void InitSqueue(Squeue *S);
void DestroySqueue(Squeue *S);
int EmptySqueue(Squeue *S);
int LengthSqueue(Squeue *S);
ElemType GetSqueue(Squeue *S);
void EnSqueue(Squeue *S, ElemType e);
void DeSqueue(Squeue *S, ElemType *e);

//少用一个元素空间
//初始化循环队列
void InitSqueue(Squeue *S)
{
    S->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    S->front = S->rear = 0;
}

//销毁循环队列
void DestroySqueue(Squeue *S)
{
    free(S);
}

//队列是否为空
int EmptySqueue(Squeue *S)
{
    if (S->front == S->rear){
        printf("队列为空！（Empty）\n");
        return TRUE;
    }
    return FALSE;
}

//队列的长度
int LengthSqueue(Squeue *S)
{
    return (S->front - S->rear + MAXSIZE) % MAXSIZE;
}

//取队列的队头元素
ElemType GetSqueue(Squeue *S)
{
    if (EmptySqueue(S) == FALSE){
        return S->base[S->front];
    }else{
        printf("队列为空！（Get）\n");
        return FALSE;
    }
}

//入队
void EnSqueue(Squeue *S, ElemType e)
{
    if ((S->rear + 1) % MAXSIZE == S->front){
        printf("队列已满！（En）\n");
    }else{
        S->base[S->rear] = e;
        S->rear = (S->rear + 1) % MAXSIZE;
    }
}

//出队
void DeSqueue(Squeue *S, ElemType *e)
{
    if (EmptySqueue(S) == TRUE){
        printf("队列为空！（De）\n");
    }else{
        *e = S->base[S->front];
        S->front = (S->front + 1) % MAXSIZE;
    }
}