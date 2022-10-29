#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    } 
}

int main()
{
    int i;
    printf("Enter the number:\n");
    scanf("%d", &i);
    printf("%d\n", factorial(i));
    return 0;
}