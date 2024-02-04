#include<string.h>
#include"Stack.c"

int main(void)
{
    // 括号匹配
    //对输入进来的括号进行匹配，正确格式或者错误格式
    char string[100] = "";
    printf("请输入括号（圆括号或方括号）：");
    scanf("%s", string);
    getchar();
    char temp[] = "#";
    strcat(string, temp);
    printf("输入的结果为：%s\n", string);

    LinkStack L;
    InitStack(&L);
    int i = 0;
    int flag = 1;
    while (string[i] != '#' && flag != 0){
        switch(string[i]){
            case '(':
                PushStack(&L, string[i]);
                break;
            case '[':
                PushStack(&L, string[i]);
                break;
            case ')':
                if ((EmptyStack(L) == FALSE) && GetStack(L) == '('){
                    PopStack(&L);
                }else{
                    flag = 0;
                }
                break;
            case ']':
                  if ((EmptyStack(L) == FALSE) && GetStack(L) == '['){
                    PopStack(&L);
                }else{
                    flag = 0;
                }
                break;  
        }
        i ++;
    }
    
    DestroyStack(L);
    if (flag == 1){
        printf("括号是正确的格式！\n");
    }else{
        printf("括号是不正确的格式！\n");
    }
    return 0;
}