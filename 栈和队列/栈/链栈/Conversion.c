#include"Stack.c"

#define Bin 2 
#define Oct 8
#define Hex 16

int main(void)
{
    //将一个十进制的数转化成8进制
    ElemType e;
    LinkStack L;
    InitStack(&L);
    printf("输入一个十进制的数：");
    scanf("%d", &e);
    getchar();
    while (e != 0){
        ElemType div, mod;//div为整除得到的数，mod为求模得到的数
        div = e / Hex;
        mod = e % Hex;
        PushStack(&L, mod);
        e = div;
    }
    StackNode *p = L;
    printf("转换成%d进制：", Hex);
    while(p->next){
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}