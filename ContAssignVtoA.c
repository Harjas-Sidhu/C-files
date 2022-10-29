#include <stdio.h>

int lower, upper, arr[];

void contassign()
{
    arr[0] = lower;
    for (int a = 0; a <= upper - lower; a++)
    {
       arr[a] = arr[0] + a; 
       printf("a[%d] is %d\n", a, arr[a]);
    }
}

int main()
{   
    printf("Enter the Lower value\n");
    scanf("%d", &lower);
    printf("Enter the Upper value\n");
    scanf("%d", &upper);
    contassign();
    return 0;
}