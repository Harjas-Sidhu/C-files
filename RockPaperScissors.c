#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int genR()
{
    srand(time(NULL));
    int r = rand() % 3; // generates 0 to 2 numbers
    return r + 1;
}

void game()
{
    static int u_points = 0;
    static int c_points = 0;
start:
    int u_in, c_in;
    printf("*****    Welcome to the Game!!!    *****\n");
    printf("Enter the number given ahead of the option you want to choose:\n");
    printf("1. Rock  \n");
    printf("2. Paper  \n");
    printf("3. Scissors  \n");
    printf("0. Quit\n");
    scanf("%d", &u_in);
    getchar();
    c_in = genR();

    if (u_in == c_in)
    {
        printf(" Tie!!!\n");
        goto start;
    }

    else if (u_in == 1)
    {
        if (c_in == 2)
        {
            printf("  Computer Wins!!!\n");
            c_points++;
            goto start;
        }

        else if (c_in == 3)
        {
            printf("   You Win!!!\n");
            u_points++;
            goto start;
        }

        else
        {
            printf("   Invalid!!!\n");
            goto start;
        }
    }

    else if (u_in == 2)
    {
        if (c_in == 3)
        {
            printf("  Computer Wins!!!\n");
            c_points++;
            goto start;
        }

        else if (c_in == 1)
        {
            printf("   You Win!!!\n");
            u_points++;
            goto start;
        }

        else
        {
            printf("   Invalid!!!\n");
            goto start;
        }
    }

    else if (u_in == 3)
    {
        if (c_in == 1)
        {
            printf("  Computer Wins!!!\n");
            c_points++;
            goto start;
        }

        else if (c_in == 2)
        {
            printf("   You Win!!!\n");
            u_points++;
            goto start;
        }

        else
        {
            printf("   Invalid!!!\n");
            goto start;
        }
    }

    else if (u_in == 0)
    {
        printf("Quitting...\n");
    }

    else
    {
        printf("   Invalid!!!\n");
        goto start;
    }

    switch (c_in)
    {
    case 1:
        printf("Computer's Choice - Rock\n");
        break;
    case 2:
        printf("Computer's Choice - Paper\n");
        break;
    case 3:
        printf("Computer's Choice - Scissors\n");
        break;
    default:
        printf("Problem with Computer's Input!!\n");
        printf("%d\n", c_in);
        break;
    }
    printf("Points of User: %d\n", u_points);
    printf("Points of Computer: %d\n", c_points);

    if (u_points > c_points)
    {
        printf("You Win!!\n");
    }

    else if (u_points == c_points)
    {
        printf("Tie!!\n");
    }

    else if (u_points < c_points)
    {
        printf("You Lose!!\n");
    }
}

int main()
{
    game();
    return 0;
}