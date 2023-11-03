#include <stdio.h>
#include <stdlib.h>


int main()
{
    int amount = 0, loop_control = 1;
    int qty1 = 0, qty2 = 0, qty3 = 0, qty4 = 0;
    while(loop_control){
        int opt = 0;
        printf("*****     Enter the option you want to buy     *****\n");
        printf("\t1. Water Bottle\t\t\t RS.20\n");
        printf("\t2. Burger\t\t\t RS.25\n");
        printf("\t3. Pizza\t\t\t RS.100\n");
        printf("\t4. Coke\t\t\t\t RS.50\n");
        printf("\t5. Exit\n");
        printf("\tEnter Your option:-\t");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Enter the quantity:- \n");
                scanf("%d", &qty1); 
                printf("Purchased %d Water Bottle\n", qty1);
                amount += 20*qty1;
                break;
            case 2:
                printf("Enter the quantity:- \n");
                scanf("%d", &qty2);
                printf("Purchased %d Burgers\n", qty2);
                amount += 25*qty2;
                break;
            case 3:
                printf("Enter the quantity:- \n");
                scanf("%d", &qty3);
                printf("Purchased %d Pizzas\n", qty3);
                amount += 100*qty3;
                break;
            case 4:
                printf("Enter the quantity:- \n");
                scanf("%d", &qty4);
                printf("Purchased %d cokes\n", qty4);
                amount += 50*qty4;
                break;
            case 5:
                printf("Thank you for the purchase\n");
                printf("Water Bottle \t\t %d \t\t %d\n", qty1, 20*qty1);
                printf("Burger \t\t\t %d \t\t %d\n", qty2, 25*qty2);
                printf("Pizza \t\t\t %d \t\t %d\n", qty3, 100*qty3);
                printf("Coke \t\t\t %d \t\t %d\n", qty4, 50*qty4);
                loop_control = 0;
                break;
            default:
                printf("Invalid Option!!!\n");
        }
    }
    printf("\n\tYour Total Bill Is : \t %d \n", amount);
    return 0;
}
