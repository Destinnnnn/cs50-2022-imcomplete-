#include <stdio.h>

int main()
{
    char *s = "hi";
    char *p =&s[0];
    printf("%p\n",p);
    printf("%p\n",s);
}