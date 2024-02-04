#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

#define MAXSIZE 100
typedef struct{
    ElemType *elem;
    int length;
}Sqlist;

Status InitSqlist(Sqlist *L);
Status DisplaySqlist(Sqlist *L);
Status DestroySqlist(Sqlist *L);
Status GetSqlist(Sqlist *L, int i, ElemType *e);
Status GetLength(Sqlist *L);
Status SqlistEmpty(Sqlist *L);
Status LocateElem(Sqlist *L, ElemType e);
Status SqlistInsert(Sqlist *L, int i, ElemType e);
Status SqlistDelete(Sqlist *L, int i, ElemType *e);
void CreateSqlist(Sqlist *L, int n);

//顺序表的初始化
Status InitSqlist(Sqlist *L)
{
    L->elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    if (!L->elem){
        return OVERFLOW;
    }
    L->length = 0;
    return OK;
}

// 顺序表的打印
Status DisplaySqlist(Sqlist *L)
{
    if (SqlistEmpty(L) == FALSE){  
        for (int i = 0; i <= L->length - 1; i ++){
            printf("%d\t%d\n", i + 1, L->elem[i]);
        }
        return TRUE;
    }
    return FALSE;
    
}

//顺序表的销毁
Status DestroySqlist(Sqlist *L)
{
    free(L->elem);
    return OK;
}

//顺序表的取值
//用e返回L中第i个元素的值
Status GetSqlist(Sqlist *L, int i, ElemType *e)
{
    if (i < 1 || L->length < i){
        return ERROR;
    }
    *e = L->elem[i - 1];
    return OK;
}

int GetSqlistNumber(Sqlist *L, int i)
{
    if (i < 1 || L->length < i){
        return ERROR;
    }
    return L->elem[i - 1];
}

//顺序表的长度
Status GetLength(Sqlist *L)
{
    return L->length;
}

//顺序表是否为空
Status SqlistEmpty(Sqlist *L)
{
    if (L->length == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

//顺序表的查找
Status LocateElem(Sqlist *L, ElemType e)
{
    for (int i = 0; i < L->length; i ++){
        if (L->elem[i] == e){
            return i + 1;//返回位置序号，而不是下标
        }
    }
    return FALSE;
}

//顺序表的插入
//在L中第i个位置之前插入新的数据元素e，L的长度加一
Status SqlistInsert(Sqlist *L, int i, ElemType e)
{
    // i的合法范围是1<=i<=legnth+1
    if (i >= 1 && i <= L->length + 1 && L->length <= MAXSIZE){//判断位置序数是否合法和表是否插满
        for (int j = L->length; j >= i; j --){//后面位置的元素都要向后移动一个位置
            L->elem[j] = L->elem[j - 1];
        }
        L->elem[i - 1] = e;// 第i个位置放入新的数据元素
        L->length ++;//表的长度加一
        return OK;
    }
    return FALSE;
}

//顺序表的删除
//删除线性表中第i个位置的元素，用e返回
Status SqlistDelete(Sqlist *L, int i, ElemType *e)
{
    if (i <= L->length && i >= 1){// 判断i是否合法:1<=i<=length
        *e = L->elem[i - 1];// 用e返回第i个位置元素的值
        for (int j = i - 1; j < L->length - 1; j ++){// 后面位置的元素都要向前移动一个位置
            L->elem[j] = L->elem[j + 1];
        }
        L->length --;
        return OK;
    }
    return FALSE;
}

//单链表的创建
void CreateSqlist(Sqlist *L, int n)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * n);
    L->length = 0;
    for (int i = 0; i < n; i ++){
        ElemType e = 0;
        printf("请输入第%d个元素的值：", i + 1);
        scanf("%d", &e);
        getchar();
        SqlistInsert(L, i + 1, e);
    }
}