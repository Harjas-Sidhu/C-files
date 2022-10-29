#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 1;
int num = 0;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void swap(int fir, int sec, char **s)
{
    char *temp = malloc(strlen(s[fir]) * sizeof(char));
    strcpy(temp, s[fir]);
    strcpy(s[fir], s[sec]);
    strcpy(s[sec], temp);
    free(temp);
}

void reverse(int start, int end, char **s)
{
    char **sen = calloc(end, sizeof(char *));
    for (int i = 0; i < end; i++)
    {
        sen[i] = (char *)realloc(sen[i], strlen(s[i]) * sizeof(char));
    }
    for (int i = 0; i < end; i++)
    {
        strcpy(sen[i], s[i]);
    }

    for (int i = start; i < end; i++)
    {
        strcpy(s[i], sen[end - 1 - i]);
    }

    for (int i = 0; i < end; i++)
    {
        free(sen[i]);
    }
    free(sen);
}

int next_permutation(int n, char **s)
{
    int num = 1;
    for (int i = n-2; i > -1; i--)
    {
        if (strcmp(s[i], s[i+1]) > 0)
        {
            for (int j = n-1; j > i; j--)
            {
                if (strcmp(s[i], s[j]) > 0)
                {
                    swap(i, j, s);
                    reverse(i+1, n-1, s);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    char **s;
    int n;
    scanf("%d", &n);
    s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));
    for (int i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}