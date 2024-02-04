#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int SElemType;
typedef struct Stack{
    SElemType *base;
    SElemType *top;
    int stacksize;
}Stack;

void InitStack(Stack *S);
void DestroyStack(Stack *S);
void ClearStack(Stack *S);
int EmptyStack(Stack *S);
int LengthStack(Stack *S);
SElemType GetStack(Stack *S);
int PushStack(Stack *S, SElemType e);
int PopStack(Stack *S);
void DisplayStack(Stack *S);

//创建栈
void InitStack(Stack *S)
{
    S->base = (SElemType *)malloc(sizeof(SElemType) * MAXSIZE);
    S->top = S->base;
    S->stacksize = MAXSIZE;
}

//销毁栈
void DestroyStack(Stack *S)
{
    free(S->top);
}

//清空栈
void ClearStack(Stack *S)
{
    S->top = S->base;
}

//栈是否为空
int EmptyStack(Stack *S)
{
    if (S->top == S->base){
        return 1;
    }else{
        return 0;
    }
}

//栈的长度
int LengthStack(Stack *S)
{
    return S->top - S->base;
}

//获取栈顶的值
SElemType GetStack(Stack *S)
{
    SElemType *number = (S->top) - 1;
    return *number;
}

//入栈
int PushStack(Stack *S, SElemType e)
{
    if (LengthStack(S) < S->stacksize){
        *(S->top) = e;
        (S->top) ++;
        return TRUE;
    }
    printf("栈已满！\n");
    return FALSE;
}

//出栈
int PopStack(Stack *S)
{
    if (S->top == S->base){
        printf("栈为空！\n");
        return FALSE;
    }
    (S->top) --;
    return TRUE;
}

//遍历整个栈，输出
void DisplayStack(Stack *S)
{
    //从栈尾向栈顶遍历
    SElemType *temp = S->base;
    for (int i = 0; i < LengthStack(S); i ++){
        printf("%d\n", *temp);
        temp ++;
    }
}
