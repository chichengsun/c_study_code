#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_SIZE 1000

int read_column_number(int * column, int n)
{
    // 读取列标，并存放在column_number数组中
    int column_number = 0;// 列标总个数
    while (column_number < MAX_COLS && scanf("%d", &column[column_number]) == 1 && column[column_number] >= 0)
    {
        column_number ++;
    }
    getchar();
    return column_number;
}

void output_range(char * output, char * input, int column[], int column_number)
{
    int col = 0; // column数组的下标
    int output_col = 0; // 输入字符串的长度，不能超过99，还有一个位置需要存放'\0'
    int len = strlen(input); // 输入行的长度

    for (col; col < column_number; col += 2)
    {
        int nchars = column[col + 1] - column[col] + 1;
        if (output_col >= MAX_SIZE - 1 || column[col] > len)
        {
            break;
        }
        if (output_col + nchars > MAX_SIZE - 1)
        {
            nchars = MAX_SIZE - 1 - output_col;
        }
        strncpy(output + output_col, input + column[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}

int main(void)
{
    int column[MAX_COLS] = {0};// 存放列标的数组
    char input[MAX_SIZE];// 存放输入的字符数组
    char output[MAX_SIZE];// 存放输出的字符数组

    int column_number = read_column_number(column, MAX_COLS);//列标总个数
    while (scanf("%s", input) && (input[0] != '-' && input[1] != '1'))// 输入“-1”退出循环
    {
        printf("Original  input : %s\n", input);
        output_range(output, input, column, column_number);
        printf("Rearrange output: %s\n", output);
    }

    return 0;
}