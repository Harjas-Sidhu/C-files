#include <stdio.h>

int arr[]={1,2,3,4};

void rev(int arr[])
{
    for (int j = 0; j < 4/2; j++)
    {
        int temp = arr[j];
        arr[j] = arr[3-j];
        arr[3-j] = temp;
    } 
}

void p()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Value of arr[%d] is: %d\n", i, arr[i]);
    }
    printf("\n");  
}

int main()
{
    printf("Before Reversing\n");
    p();
    rev(arr);
    printf("After Reversing\n");
    p();
    return 0;
}