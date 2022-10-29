#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20], str2[20], str3[14]="'s friend is ", str4[55];

    printf("Enter your name:\n");
    gets(str1);
    printf("Enter your friend's name:\n");
    gets(str2);

    strcpy(str4, strcat(str1, str3));
    strcpy(str4, strcat(str4, str2));
    
    puts(str4);
    return 0;
}