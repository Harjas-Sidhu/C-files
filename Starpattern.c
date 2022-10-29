#include <stdio.h>

void rstar(int num)
{
    for (int i = num - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void star(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int m, n;
    printf("Enter the Number:\n");
    scanf("%d", &m);
    printf("Enter 0 to print Star Pattern OR 1 to print Reverse Star Pattern OR 2 to print Both:\n");
    scanf("%d", &n);
    switch (n)
    {
    case 0:
        star(m);
        break;
    case 1:
        rstar(m);
        break;
    case 2:
        star(m);
        rstar(m);
        break;
    default:
        printf("Invalid!\n");
    }
    return 0;
}