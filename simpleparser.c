#include <stdio.h>
#include <string.h>

void parser(char *str)
{
    int in = 0, index = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (str[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            str[index] = str[i];
            index++;
        }     
    }
    str[index] = '\0';
}

int main()
{
    char str[40] = "<h1>    This is A Heading </h1>";
    printf("Before parsing: $$%s$$\n", str);
    parser(str);
    printf("After parsing: $$%s$$\n", str);
    return 0;
}