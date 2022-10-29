#include <stdio.h>
#include <string.h>

struct Students
{
    char Name[12];
    int Class;
    int Roll_Number;
    int Admission_Number;
};

int main()
{
    int num;
    printf("Enter the Number of Students:");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        struct Students k;
        strcpy(k.Name, "Harjas Sidhu");
        k.Class = 10;
        k.Roll_Number = i;
        k.Admission_Number = i + 1000;
        printf("Name = %s", k.Name);
        printf("Class = %d\n", k.Class);
        printf("Roll Number = %d\n", k.Roll_Number);
        printf("Addmission Number = %d\n", k.Admission_Number);
        printf("\n");
    }
    return 0;
}