#include"SString.c"

int main(void)
{
    SString S, T;
    InitSString(&S);
    EmptySString(&S);
    InitSString(&T);
    char string1[] = "hello";
    char string2[] = "helle";
    char string3[] = "sunsheng";
    AssignSString(&S, string1);
    AssignSString(&T, string2);
    if (EqualSString(&S, &T) == TRUE){
        printf("串为空！\n");
    }else{
        printf("串不为空！\n");
    }
    ConcatSString(&S, &T);
    DisplaySString(&S);
    printf("串的长度为：%d\n", LengthSString(&S));
    SString temp = SubSString(&S, 5, 3);
    DisplaySString(&temp);
    InsertSString(&S, 11, &temp);
    DisplaySString(&S);
    SString C = DeleteSString(&S, 5, 4);
    DisplaySString(&C);
    DisplaySString(&S);
    return 0;
}