#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

void InitStack(LinkStack *L);
void DisplayStack(StackNode *S);
void DestroyStack(StackNode *S);
int LengthStack(StackNode *S);
int EmptyStack(StackNode *S);
ElemType GetStack(StackNode *S);
void PushStack(LinkStack *S, ElemType e);
void PopStack(LinkStack *S);

//初始化链栈
void InitStack(LinkStack *L)
{
    (*L) = NULL;
}

//链栈的输出
void DisplayStack(StackNode *S)
{
    //从栈顶到栈尾依次输出
    StackNode *p = S;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
}

//销毁链栈
void DestroyStack(StackNode *S)
{
    StackNode *p;
    while(S->next){
        p = S;
        S = S->next;
        free(p);
    }
    free(S);
}

//链栈的长度
int LengthStack(StackNode *S)
{
    int count = 0;
    StackNode *p = S;
    while(p){
        count ++;
        p = p->next;
    }
    return count;
}

//链栈是否为空
int EmptyStack(StackNode *S)
{
    if (S){
        return FALSE;
    }
    return TRUE;
}

//返回栈顶的元素值
ElemType GetStack(StackNode *S)
{
    return S->data;
}

//链栈的入栈
void PushStack(LinkStack *S, ElemType e)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = (*S);
    (*S) = p;
}

//链栈的出栈
void PopStack(LinkStack *S)
{
    StackNode *p = *S;
    *S = (*S)->next;
    free(p);
}