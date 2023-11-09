#include <stdio.h>

int main(void)
{
    char name[100];
    printf("Enter your name: "); 
    scanf("%s", name); 

    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }

    printf("Length of name: %i\n", i);
    return 0; 
}
