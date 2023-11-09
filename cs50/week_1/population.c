#include <math.h>
#include <stdio.h>
#include <windows.h>
double year_popluation(double first, double end);

int main(void)
{
    int first, end;
    double time;
    do
    {
        printf("Please input the number of llama in the first.\n");
        scanf("%d",&first);
    }
    while (first < 9);
    do
    {
        printf("Please input the number of llama in the end,\n");
        scanf("%d",&end);
    }
    while (end - first < 0);
    time = year_popluation(first, end);
    printf("Years: %.01f\n", time);
}

double year_popluation(double first, double end)
{
    double t = log10(end / first) / log10(13.0 / 12.0);
    return t;
}

