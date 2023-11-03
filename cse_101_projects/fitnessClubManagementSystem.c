#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
    int id;
    char name[50];
    char mobile_number[15];
    float BMI;
    char address[100];
    char date_of_joining[15];
    char package_details[50];
};

void add_record(struct customer c) {
    FILE *fp;
    fp = fopen("customer_records.txt", "a");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%d %s %s %f %s %s %s\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
    fclose(fp);
    system("cls");
    printf("\n\n<------customer added successfully!------->\n\n");
}

void delete_record(int id) {
    FILE *fp1, *fp2;
    int flag = 0;
    struct customer c;
    fp1 = fopen("customer_records.txt", "r");
    fp2 = fopen("temp.txt", "w");
    if (fp1 == NULL || fp2 == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp1, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (c.id != id) {
            fprintf(fp2, "%d %s %s %f %s %s %s\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
        } else {
            flag = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("customer_records.txt");
    rename("temp.txt", "customer_records.txt");
    if (flag == 1) {
    	system("cls");
        printf("Record deleted successfully!\n");
    } else {
    	system("cls");
        printf("Record not found!\n");
    }
}
void display_records() {
    FILE *fp;
    struct customer c;
    fp = fopen("customer_records.txt", "r");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    system("cls");
    printf("\n\nID\tName\tMobile Number\t\tBMI\t\tAddress\t\tDate of Joining\t\tPackage Details\n");
  printf("+---------------------------------------------------------------------------------------------+\n");
  printf("+---------------------------------------------------------------------------------------------+\n\n");
    while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        printf("%d\t%s\t%s\t\t%f\t\t%s\t\t%s\t\t%s\n\n", c.id, c.name, c.mobile_number, c.BMI, c.address, c.date_of_joining, c.package_details);
    }
    fclose(fp);
}
void search_by_id(int id) {
    FILE *fp;
    int flag = 0;
    struct customer c;
    fp = fopen("customer_records.txt", "r");
    if (fp == NULL) {
    	system("cls");
        printf("Error opening file!\n");
        exit(1);
    }
    while (fscanf(fp, "%d %s %s %f %s %s %s\n", &c.id, c.name, c.mobile_number, &c.BMI, c.address, c.date_of_joining, c.package_details) != EOF) {
        if (c.id == id) {
          printf("\n\n\t\t\t Desired customer detail\t\t\t\n");
          printf("\t--------------------------------------------\t\n");
           printf("\t--------------------------------------------\t\n");
          printf("ID: %d\n",c.id);
          printf("Name: %s\n",c.name);
          printf("Mob.no.: %s\n",c.mobile_number);
          printf("BMI: %f\n",c.BMI);
          printf("Address: %s\n",c.address);
          printf("Date_of_joining: %s\n",c.date_of_joining);
          printf("Package_Detail: %s\n\n",c.package_details);
          printf("<---------------**----End----**--------------->\n\n");
            flag = 1;
        }
    }
    fclose(fp);
    if (flag == 0) {
    	system("cls");
        printf("\tRecord not found!\n\n\n");
    }
}

int main() {
    int choice;
    int id;
    struct customer c;
    while (1) {
        printf("\n\n\n+--------------------------------------------+\n");
        printf("+\t\tFITNESS CLUB MANAGMENT SYSTEM\t\t +\n");
        printf("+--------------------------------------------+\n\n");

      
     
      printf("+--------------------------------------------+\n");
        printf("|\t1. Add record of customer to file        |\n");
        printf("+\t2. Delete the record of customer         +\n");
        printf("|\t3. Display record of all customer        |\n");
        printf("+\t4. Search the record of customer by id   +\n");
        printf("+\t5. Exit                                  +\n");
       printf("+--------------------------------------------+\n");
     
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);
         switch (choice) {
            case 1:
            system("cls");
              printf("+-------------------------------------+\n");
            		printf("+\t\tAdding Customer Record        +\n");
               printf("+-------------------------------------+\n");
                printf(" \tEnter customer id: ");
                scanf("%d", &c.id);
              getchar();
                printf(" \tEnter customer name: ");
                scanf("%s", c.name);
               getchar();
                printf(" \tEnter customer mobile number: ");
                scanf("%s", c.mobile_number);
                getchar();
                printf(" \tEnter customer BMI: ");
                scanf("%f", &c.BMI);
                getchar();
                printf(" \tEnter customer address: ");
                scanf("%[^\n]s", c.address);
                getchar();
                printf(" \tEnter customer date of joining: ");
                scanf("%s", c.date_of_joining);
                getchar();
                printf(" \tEnter customer package details: ");
                scanf("%[^\n]s", c.package_details);
                add_record(c);
                break;
                case 2:
            	system("cls");
              printf("+-----------------------------------+\n");
            	printf("+\t\tDeleting Customer Record    +\n");
              printf("+-----------------------------------+\n");
                printf(" \tEnter customer id: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            case 3:
              	system("cls");
                display_records();
                break;
     
            case 4:
              system("cls");
                printf(" \tEnter customer id: ");
                scanf("%d", &id);
                search_by_id(id);
                break;
          
            case 5:
            	system("cls");
            	printf("\n\n\n\t\t\tC Project On Fitness club Management System\n\n\t\t By Vaibhav , Jairaj Singh , Himanshu , Ramakant\n\n\n\n");
                exit(0);
            default:
                printf(" \tInvalid choice!\n\n\n");
        }
    }
    return 0;
}