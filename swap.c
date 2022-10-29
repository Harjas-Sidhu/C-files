#include <stdio.h>

void val(int *x, int *y)
{
    int tempx = *x, tempy = *y;
    *x = tempx+tempy;
    *y = tempx-tempy;
}

int main()
{
    int x, y;
    printf("Enter the Value of x:\n");
    scanf("%d", &x);
    printf("Enter the Value of y:\n");
    scanf("%d", &y);
    printf("Value of x is %d, Value of y is %d\n", x, y);
    val(&x, &y);
    printf("Changing Values of x and y to [x+y] and [x-y]....\n");
    printf("Value of x is %d, Value of y is %d\n", x, y);
    return 0;
}