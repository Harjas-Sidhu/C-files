#include <stdio.h>

int a, b = 1;

int main()
{
    printf("Enter a Number to get its multiplication table:-\n");

    scanf("%d", &a);

    do
    {
        printf("%d * %d = %d\n", a, b, a * b);
        b = b + 1;
    } while (b < 11);

    return 0;
}
