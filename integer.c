#include <stdio.h>
int main()
{
    int a , opt;
    printf("ENTER Value for number 1:\n");
    scanf("%d", &a);
  k:
    printf("\t\tAIRTHMETIC CALCULATOR\n");
    printf("1. Check Positive or Negative\n");
    printf("2. Check Even or Odd\n");
    printf("3. Square\n");
    printf("4. Cube\n");
    printf("5. Exit\n");
    printf("Enter the option(1-5): ");
    scanf("%d", &opt);
    switch(opt){
        case 1: 
            a > 0 ? printf("%d is a Positive Number", a) : printf("%d is a Negative Number", a);
            break;
        case 2:
            a%2 == 0 ? printf("%d is an Even Number", a) : printf("%d is an Odd Number", a);
            break;
        case 3: 
            printf("Square of %d is %d", a,a*a);
            break;
        case 4: 
            printf("Cube of  %d is %d", a, a*a*a);
            break;
        case 5: 
            printf("\n*****     Thank you for Using Me!     *****\n");
            break;
        default: 
            printf("Invalid choice\n");
            goto k;
    }
    return 0;
}
