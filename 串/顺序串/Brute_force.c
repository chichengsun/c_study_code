#include"SString.c"

//brute——force模式匹配算法 
int BF(SString S, SString T)
{
    if (LengthSString(&S) < LengthSString(&T)){
        return FALSE;
    }else if(LengthSString(&S) == LengthSString(&T)){
        if (EqualSString(&S, &T) == TRUE){
            return 1;
        }else{
            return FALSE;
        }
    }else{
        char *s1 = S.ch;
        char *s2 = T.ch;
        for (int i = 0; i < LengthSString(&S) - LengthSString(&T) + 1; i ++){
            for (int k = 0; k < LengthSString(&T); k ++){
                if (*s1 != *s2){
                    break;
                }
                s1 ++;
                s2 ++;
            }
            if (s2 - T.ch == LengthSString(&T)){
                return i + 1;
            }else{
                s1 = S.ch + 1 + i;
                s2 = T.ch;
            }
        }
        return FALSE;
    }
}

int main(void)
{
    SString S, T;
    InitSString(&S);
    InitSString(&T);
    char string1[256];
    char string2[256];
    printf("请输入字符串（主串）：");
    scanf("%s", string1);
    getchar();
    printf("请输入字符串（模式串）：");
    scanf("%s", string2);
    getchar();
    AssignSString(&S, string1);
    AssignSString(&T, string2);
    printf("主串如下：\n");
    DisplaySString(&S);
    printf("模式串如下：\n");
    DisplaySString(&T);
    int result = BF(S, T);
    if (result == FALSE){
        printf("查找失败！\n");
    }else{
        printf("查找成功！位置序号  xx为：%d\n", result);
    }
    return 0;
}