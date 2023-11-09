// 选择排序
#include <stdio.h>
#include <string.h>

void selectionSort(char* str);

int main() {
    char str[100];
    printf("输入需要排序的字符串: ");
    scanf("%s", str);
    selectionSort(str);
    printf("选择排序后结果为：%s\n", str);
    return 0;
}

void selectionSort(char* str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (str[j] < str[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            char temp = str[i];
            str[i] = str[minIndex];
            str[minIndex] = temp;
        }
    }
}

