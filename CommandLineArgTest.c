#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *opt;
    opt = argv[1];
    int num1, num2;
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);
    printf("Operation is: %s\n", opt);
    printf("1st Number is: %d\n", num1);
    printf("2nd Number is: %d\n", num2);
    return 0;
}
 