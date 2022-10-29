#include <stdio.h>
#include <string.h>

int num;

struct Drivers
{
    char N[20];
    char Dl[20];
    char R[20];
    int K;
};

void DI()
{
    int i;
    struct Drivers D[i];
    for (i = 1; i <= num; i++)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Enter your Name:\n");
        scanf("%s", D[i].N);
        printf("Enter your Driving License no:\n");
        scanf("%s", D[i].Dl);
        printf("Enter your Route:\n");
        scanf("%s", D[i].R);
        printf("Enter the kilometers travelled(approx.):\n");
        scanf("%d", &D[i].K);
        printf("-------------------------------------------------------------------\n");
        printf("\n");
    }

    printf("\n");
    for (i = 1; i <= num; i++)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Driver %d\n", i);
        printf("Name: %s\n", D[i].N);
        printf("Driving license no: %s\n", D[i].Dl);
        printf("Route: %s\n", D[i].R);
        printf("Kilometers Travelled(approx.): %d\n", D[i].K);
        printf("-------------------------------------------------------------------\n");
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("Enter the Number of drivers whoose data you want to enter:\n");
    scanf("%d", &num);
    DI();
    return 0;
}