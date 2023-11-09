#include <stdio.h>

int main()
{
    int numbers[]={4,6,8,2,7,5,0};

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == -1)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
