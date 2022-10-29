#include <stdio.h>

int palindrome(int num, int reversed)
{
     if (num == reversed)
    {
        return 1;
    }
    else if (num != reversed)
    {
        return 0;
    }
}

int main()
{
    int num, reversed = 0;
    printf("Enter The Number:-\n");
    scanf("%d", &num);
    int org = num;
    while(num != 0)
    {
        reversed = (reversed * 10) + num % 10;
        num = num / 10;
    }
    printf("The Reversed Number is: %d\n", reversed);
    
    if (palindrome(org, reversed))
    {
        printf("The number Entered is a Palindrome\n");
    }
    else
    {
        printf("The number Entered is NOT a Palindrome\n");
    }
    
    return 0;
}