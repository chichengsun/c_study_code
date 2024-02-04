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

//����һ��Ԫ�ؿռ�
//��ʼ��ѭ������
void InitSqueue(Squeue *S)
{
    S->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    S->front = S->rear = 0;
}

//����ѭ������
void DestroySqueue(Squeue *S)
{
    free(S);
}

//�����Ƿ�Ϊ��
int EmptySqueue(Squeue *S)
{
    if (S->front == S->rear){
        printf("����Ϊ�գ���Empty��\n");
        return TRUE;
    }
    return FALSE;
}

//���еĳ���
int LengthSqueue(Squeue *S)
{
    return (S->front - S->rear + MAXSIZE) % MAXSIZE;
}

//ȡ���еĶ�ͷԪ��
ElemType GetSqueue(Squeue *S)
{
    if (EmptySqueue(S) == FALSE){
        return S->base[S->front];
    }else{
        printf("����Ϊ�գ���Get��\n");
        return FALSE;
    }
}

//���
void EnSqueue(Squeue *S, ElemType e)
{
    if ((S->rear + 1) % MAXSIZE == S->front){
        printf("������������En��\n");
    }else{
        S->base[S->rear] = e;
        S->rear = (S->rear + 1) % MAXSIZE;
    }
}

//����
void DeSqueue(Squeue *S, ElemType *e)
{
    if (EmptySqueue(S) == TRUE){
        printf("����Ϊ�գ���De��\n");
    }else{
        *e = S->base[S->front];
        S->front = (S->front + 1) % MAXSIZE;
    }
}