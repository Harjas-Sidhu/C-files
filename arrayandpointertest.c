#include <stdio.h>

int num;

void func(int *ptr)
{
    for (int i = 0; i <= num; i++)
    {
        printf("Value of arr[%d] is %d\n", i, *ptr);
        ptr++;
    }
}

int main()
{
    printf("Enter a number:-\n");
    scanf("%d", &num);

    int arr[num--];

    arr[0] = 0;

    for (int a = 0; a <= num; a++)
    {
        arr[a] = arr[0] + a;
        printf("a[%d] is %d\n", a, arr[a]);
    }

    int *p = arr;

    func(p);
    return 0;
}