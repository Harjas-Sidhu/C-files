#include <stdio.h>


int main(){
    int num1 = 0, num2 = 0;
    printf("Enter a number: \n");
    scanf("%d", &num1);
    printf("Enter another number: \n");
    scanf("%d", &num2);
    printf("\n%d\n", num1+num2);
    printf("%d\n", num1-num2);
    printf("%d\n", num1*num2);
    if(num2 != 0){
        printf("%d\n", num1/num2);
        printf("%d\n", num1%num2);
    }
    return 0;
}