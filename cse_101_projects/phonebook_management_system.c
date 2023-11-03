#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[20];
    int phone_number;
};

struct PhoneBook
{
    struct Contact Contact;
};

int main()
{
    struct PhoneBook PhoneBook[10];
    int contact_count = 0;
    int opt = 0;
    printf("\n*****     MENU     *****\n");
    printf("\t 1. Add a Contact\n");
    printf("\t 2. Delete a Contact\n");
    printf("\t 3. View a Contact\n");
    printf("\t 4. View all Contacts\n");
    printf("\t 5. Exit\n");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        long long int number = 0; 
        struct Contact c;
        printf("Enter The Name of the Contact:\n");
        scanf("\n");
        scanf("%[^\n]%*c", c.name);
        printf("Enter the Phone Number:\n");
        scanf("%lld", &number);
        PhoneBook[contact_count].Contact = c;
        printf("%s\n%d", PhoneBook[contact_count].Contact.name, PhoneBook[contact_count].Contact.phone_number);
        contact_count += 1;
        break;
    default:
        break;
    }
    return 0;
}
