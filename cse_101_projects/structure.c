#include <stdio.h>
#include <string.h>

struct Student
{
    char roll_no[10];
    char name[30];
    char class[10];
    float fees;
};

int menu()
{
    int opt = 0;
    printf("*****     MENU     *****\n");
    printf("1. Add a Student's Data\n");
    printf("2. Search a Student's Data\n");
    printf("3. Delete a Student's Data\n");
    printf("4. View all Students' Data\n");
    printf("5. Add Multiple Students' Data\n");
    printf("0. Exit\n");
    printf("Enter Your option(0 - 5): ");
    scanf("%d", &opt);
    return opt;
}

void add_student(struct Student students[], int n)
{
    printf("\nEnter the name of student %d: ", n);
    scanf("%s", &students[(n)-1].name);
    printf("\nEnter the roll no of stundent %d: ", n);
    scanf("%s", &students[(n)-1].roll_no);
    printf("\nEnter the class of stundent %d: ", n);
    scanf("%s", &students[(n)-1].class);
    printf("\nEnter the fees of stundent %d: ", n);
    scanf("%f", &students[(n)-1].fees);
}

void search(struct Student students[], int size)
{
    int option = 0;
    printf("\n***************************************\n");
    printf("\n1. Search by name\n");
    printf("\n2. Search by class\n");
    printf("\n3. Search by roll no\n");
    printf("\n4. Search by fees\n");
    printf("\n***************************************\n");
    printf("Enter your option(1 - 4): ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        char name[30];
        for (int i = 0; i < size; i++)
        {
            if(strcmp(name, students[i].name)){
                printf("*****************************************\n");
                printf("\nName of Student %d is : %s\n", i + 1, students[i].name);
                printf("roll_no of Student %d is : %s\n", i + 1, students[i].roll_no);
                printf("class of Student %d is : %s\n", i + 1, students[i].class);
                printf("fees of Student %d is : %f\n\n", i + 1, students[i].fees);
                printf("*****************************************\n");
            }
        }
        break;
    default:
        break;
    }
}

void view_all(struct Student students[], int n)
{
    for (int i = 0; i < (int)n - 1; i++)
    {
        printf("*****************************************\n");
        printf("\nName of Student %d is : %s\n", i + 1, students[i].name);
        printf("roll_no of Student %d is : %s\n", i + 1, students[i].roll_no);
        printf("class of Student %d is : %s\n", i + 1, students[i].class);
        printf("fees of Student %d is : %f\n\n", i + 1, students[i].fees);
        printf("*****************************************\n");
    }
}

int main()
{
    int size = 1;
    struct Student students[size];
    int option = 1;
    while (option)
    {
        option = menu();
        switch (option)
        {
        case 1:
            add_student(students, size);
            size += 1;
            break;
        case 4:
            view_all(students, size);
            break;
        case 0:
            option = 0;
            break;
        default:
            printf("Wrong Input\n");
        }
    }
    return 0;
}