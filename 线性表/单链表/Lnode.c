#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}Lnode,*LnodeList;

void InitLnode(LnodeList *L);
int LengthLnode(Lnode *L);
int EmptyLnode(Lnode *L);
void DisplayLnode(Lnode *L);
int DestroyLnode(Lnode *L);
void ClearLnode(Lnode *L);
int GetLnode(Lnode *L, int i, ElemType *e);
Lnode *LocateLnode(Lnode *L, ElemType e);
int LocateNumberLnode(Lnode *L, ElemType e);
int InsertLnode(Lnode *L, int i, ElemType e);
int DeleteLnode(Lnode *L, int i);
void CreateLnode_H(LnodeList *L, int n);
void CreateLnode_R(LnodeList *L, int n);

//单链表的初始化
void InitLnode(LnodeList *L)
{
    (*L) = (Lnode *)malloc(sizeof(Lnode));
    (*L)->next = NULL;
}


// 单链表的表长
int LengthLnode(Lnode *L)
{
    Lnode *p = L;
    int count = 0;
    while(p->next){
        count ++;
        p = p->next;
    }
    return count;
}

//判断单链表是否为空
int EmptyLnode(Lnode *L)
{
    //只需要判断头节点的指针域是否为空
    if (L->next){
        return FALSE;
    }
    return TRUE;
}

// 单链表打印
void DisplayLnode(Lnode *L)
{
    Lnode *p = L->next;
    for (int i = 0; i < LengthLnode(L); i ++){
        printf("%d\t%d\n", i + 1, p->data);
        p = p->next;
    }
}

//单链表的销毁
int DestroyLnode(Lnode *L)
{
    // 从头指针开始，依次销毁
    Lnode *p;// p表示要销毁的结点
    while (L){
        p = L;
        L = L->next;
        free(p);
    }
    return TRUE;
}

// 单链表的清空
void ClearLnode(Lnode *L)
{
    // 链表依然存在，但是链表中除了头结点没有其他元素 
    // 依次释放所有结点，并将头结点的指针域设置为空
    // p一直指向首元结点，然后让L指向第二个结点，释放p，循环条件是链表中除了头结点外，还有两个结点
    //循环结束除头结点外，还有一个结点，释放最后一个结点，然后让头结点的指针域为空即可
    Lnode *p;
    while(L->next->next){
        p = L->next;
        L = p->next;
        free(p);
    }
    p = L->next;
    free(p);
    L->next = NULL;
}



//单链表的取值
int GetLnode(Lnode *L, int i, ElemType *e)
{
    Lnode *p = L;
    if (i >= 1 && i <= LengthLnode(L)){
        for (int j = 0; j < i; j ++){
            p = p->next;
        }
        *e = p->data;
        return TRUE;
    }
    return FALSE;
}

// 单链表的查找：返回指针
Lnode *LocateLnode(Lnode *L, ElemType e)
{
    // 当结点的指针p不为空，并且p所指结点的数据域data不等于e，循环继续
    Lnode *p = L->next;
    while (p && p->data != e){
        p = p->next;
    }
    return p;//返回当前指针：失败为空
}

//单链表的查找：返回位置序号
int LocateNumberLnode(Lnode *L, ElemType e)
{
    Lnode *p = L->next;
    int count = 1;
    while (p && p->data != e){
        count ++;
        p = p->next;
    }
    if (p){
        return count;
    }else{
        return FALSE;
    }
}

//单链表的插入
int InsertLnode(Lnode *L, int i, ElemType e)
{
    //在第i个位置上插入新的结点
    //首先找到第i-1个位置上的结点p
    //然后构造一个新结点s，数据域为e，指针域为p->next，p的指针域为s
    Lnode *p, *s;
    p = L;
    s = (Lnode *)malloc(sizeof(Lnode));
    s->data = e;
    s->next = NULL;
    if (i >= 1 && i <= LengthLnode(L) + 1){
        for (int j = 0; j < i - 1; j ++){
            p = p->next;
        }
        s->next = p->next;
        p->next = s;
        return TRUE;
    }else{
        return FALSE;
    }
}

//单链表的删除
int DeleteLnode(Lnode *L, int i)
{
    //删除第i个位置上的结点
    //首先找到第i-1个位置上的结点p
    //然后让p的指针域指向第i+1个位置上的结点
    //最后释放第i个位置上的结点
    Lnode *p = L;
    if (i <= LengthLnode(L) && i >= 1){
        for (int j = 0; j < i - 1; j ++){
            p = p->next;
        }//p指向第i-1个位置上的结点
        Lnode *q = p->next;
        p->next = q->next;
        free(q);
        return TRUE;
    }
    return FALSE;
}

//单链表的前插法，头插法
void CreateLnode_H(LnodeList *L, int n)
{
    InitLnode(L);
    for (int i = n; i >= 1; i --){
        Lnode *p;
        p = (Lnode *)malloc(sizeof(Lnode));
        printf("请输入第%d个元素值：", i);
        scanf("%d", &(p->data));
        getchar();//读取多余的回车
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//单链表的尾插法
void CreateLnode_R(LnodeList *L, int n)
{
    InitLnode(L);
    Lnode *r = (*L);//r始终指向尾结点
    for (int i = 1; i <= n; i ++){
        Lnode *p;//p为临时结点
        p = (Lnode *)malloc(sizeof(Lnode));
        printf("请输入第%d个元素值：", i);
        scanf("%d", &(p->data));
        getchar();//读取多余的回车
        p->next = NULL;
        r->next = p;
        r = p;//r始终指向尾结点.
    }
}