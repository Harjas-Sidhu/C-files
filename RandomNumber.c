#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        int num = rand() % (upper - lower) + lower;
        printf("The number generated is: %d\n", num);
    }
}

int main()
{
    int a, b, c;
    printf("Enter the lower value:\n");
    scanf("%d", &a);
    printf("Enter the upper value:\n");
    scanf("%d", &b);
    printf("Enter the count value:\n");
    scanf("%d", &c);
    srand(time(0));
    random(a, b++, c);

    return 0;
}