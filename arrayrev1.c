#include <stdio.h>

int a[7] = {1, 2, 3, 4, 5, 6, 7}, b[7];

void rev()
{
    for (int j = 0, n = 6; j <= 6; j++, n--)
    {
        a[j] = b[n];
    }
}

void p()
{
    printf("\n");
    for (int k = 0; k <= 6; k++)
    {
        printf("Value of a[%d] is %d\n", k, a[k]);
    }
    printf("\n");
}

int main()
{
    p();
    
    for (int i = 0; i <= 6; i++)
    {
        b[i] = a[i];
    }

    printf("Let it be reversed........\n");
    
    rev();
    p();
    
    return 0;
}