#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char *ptr;

    printf("-------------------------------------------------------------------------\n");
    printf("//////////////ABC Pvt Limited: Employee System 2.013-b\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Enter The number of Employees you want to login id of: ");
    scanf("%d", &num);
    printf("\n");
    ptr = (char *)calloc(1, sizeof(char));

    for (int i = 1; i <= num; i++)
    {
        int len;
        printf("-------------------------------------------------------------------------\n");
        printf("//////////////ABC Pvt Limited: Employee System 2.013-b\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
        printf("-------------------------------------------------------------------------\n");
        printf("Employee %d:\n", i);
        printf("Enter The number of Characters in your ABC E-id: ");
        scanf("%d", &len);
        printf("\n");
        printf("Enter Your E-id:");
        ptr = (char *)realloc(ptr, len * sizeof(char));
        scanf("%s", ptr);
        printf("\n");
        printf("E-id of Employee %d = %s\n", i, ptr);
        printf("\n");
    }
    free(ptr);
    return 0;
}