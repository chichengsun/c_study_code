#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 255
typedef struct{
    char *ch;
    int length;
}SString;

void InitSString(SString *S);
void AssignSString(SString *S, char *s);
void DisplaySString(SString *S);
int LengthSString(SString *S);
void DestroySString(SString *S);
void CopySString(SString *S, SString *T);
int EmptySString(SString *S);
int EqualSString(SString *S, SString *T);
void ConcatSString(SString *S, SString *T);
SString SubSString(SString *S, int i, int j);
int InsertSString(SString *S, int i, SString *T);
SString DeleteSString(SString *S, int i, int j);

//初始化串
void InitSString(SString *S)
{
    S->ch = (char *)malloc(sizeof(char) * MAXSIZE);
    S->length = 0;
}

//生成串
void AssignSString(SString *S, char *s)
{
    int i = 0;
    char *t = S->ch;
    for ( ; *s != '\0'; i ++){
        *t = *s;
        t ++;
        s ++;
    }
    S->length = i;
}

//输出串
void DisplaySString(SString *S)
{
    char *s = S->ch;
    for (int i = 0; i < LengthSString(S); i ++){
        printf("%c", *s);
        s ++;
    }
    printf("\n");
}

//返回串的长度
int LengthSString(SString *S)
{
    return S->length;
}

//释放串
void DestroySString(SString *S)
{
    free(S->ch);
}

//复制串
void CopySString(SString *S, SString *T)
{
    int i = 0;
    char *s1 = S->ch;
    char *s2 = T->ch;
    for ( ; i < LengthSString(T); i ++){
        *s1 = *s2;
        s1 ++;
        s2 ++;
    }
    S->length = i;
}

//串是否为空
int EmptySString(SString *S)
{
    if (LengthSString(S) == 0){
        printf("串为空！\n");
        return TRUE;
    }else{
        printf("串不为空！\n");       
        return FALSE;
    }
}

//串是否相等
int EqualSString(SString *S, SString *T)
{
    char *s1 = S->ch;
    char *s2 = T->ch;
    if (LengthSString(S) == LengthSString(T)){
        for (int i = 0; i < LengthSString(S); i ++){
            if (*s1 != *s2){
                return FALSE;
            }
            s1 ++;
            s2 ++;
        }
        return TRUE;
    }else{
        return FALSE;
    }
}

//连接串
void ConcatSString(SString *S, SString *T)
{
    //将T串连接在S串后面
    char *s1 = S->ch + LengthSString(S);
    char *s2 = T->ch;
    for (int i = 0; i < LengthSString(T); i ++){
        *s1 = *s2;
        s1 ++;
        s2 ++;
    }
    S->length = LengthSString(S) + LengthSString(T);
}

//返回子串
SString SubSString(SString *S, int i, int j)
{
    //返回串中从第i个位置开始长度为j个字符的子串
    SString C;
    InitSString(&C);
    if (i < 0 || i > LengthSString(S) || j > LengthSString(S) || i + j - 1 > LengthSString(S)){
        return C;//失败则返回空串
    }else{
        char *s1 = C.ch;
        char *s2 = S->ch + i - 1;
        for (int k = 0; k < j; k ++){
            *s1 = *s2;
            s1 ++;
            s2 ++;
        }
        C.length = j;
        return C;
    }
}

//插入串
int InsertSString(SString *S, int i, SString *T)
{
    //在S串第i个位置上插入T串
    //首先用C获取需要移动的串
    //将T串连接在S串后面
    //最后将C串连接在S串后面
    if (i > LengthSString(S) + 1){
        return FALSE;
    }else{
        SString C = SubSString(S, i, LengthSString(S) - i + 1);
        S->length = i - 1;
        ConcatSString(S, T);
        ConcatSString(S, &C);
        return TRUE;
    }
}

//删除串
SString DeleteSString(SString *S, int i, int j)
{
    //删除S串中从第i个位置开始，长度为j个字符的子串
    //最后用C返回子串
    SString C;
    InitSString(&C);
    if (i > LengthSString(S) || i < 0 || j > LengthSString(S) || i + j - 1 > LengthSString(S)){
        return C;//失败则返回空串
    }else{
        char *s1 = C.ch;
        char *s2 = S->ch + i - 1;
        char *s3 = S->ch + i - 1;
        for (int k = 0; k < j; k ++){
            *s1 = *s2;
            s1 ++;
            s2 ++;
        }
        C.length = j;
        for (int k = 0; k < LengthSString(S) - i - j + 1; k ++){
            *s3 = *s2;
            s2 ++;
            s3 ++;
        }
        S->length = LengthSString(S) - j;
        return C;
    }
}